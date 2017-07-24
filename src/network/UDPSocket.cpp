extern "C"
{

#include <strings.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

}

#include <stdexcept>
#include <algorithm>
#include <string>
//
#include "UDPSocket.hpp"

namespace network
{

UDPSocket::UDPSocket() :
	mSocketHandle( socket( AF_INET, SOCK_DGRAM, 0 ))
{
	mAddress.sin_family = AF_INET;
	mAddress.sin_port = 0;
	mAddress.sin_addr.s_addr = INADDR_ANY;
	std::fill_n( mAddress.sin_zero, 8, 0 );
}
UDPSocket::~UDPSocket()
{
	shutdown( mSocketHandle, 2 );
}

void UDPSocket::bind( Port const &port )
{
	mAddress.sin_port = htons( port );
	SocketAddress *socketAddress = reinterpret_cast< SocketAddress * >( &mAddress );
	if( ::bind( mSocketHandle, socketAddress, sizeof( mAddress ) < 0 ))
	{
		throw std::runtime_error( "network::UDPSocket::bind: failed to bind port: " + std::to_string( port ));
	}
}

void UDPSocket::send( Data const &datagram, IP const &address, Port const &port )
{
	InternetAddress to;
	to.sin_family = AF_INET;
	auto hostAddress = gethostbyname( address.c_str());
	bcopy(
		reinterpret_cast< char * >( hostAddress->h_addr ),
		reinterpret_cast< char * >( &to.sin_addr ),
		hostAddress->h_length
		);
	to.sin_port = htons( port );

	SocketAddress const *socketAddress = reinterpret_cast< SocketAddress const * >( &to );
	if( sendto( mSocketHandle, &datagram[ 0 ], datagram.size(), 0, socketAddress , sizeof( InternetAddress )) < 0 )
	{
		throw std::runtime_error( "network::UDPSocket::receive: failed to receive" );
	}
}

Data UDPSocket::receive( IP const &address, Port const &port, DatagramSize const &size)
{
	Data datagram;
	datagram.resize( size );

	InternetAddress from;
	from.sin_family = AF_INET;
	auto hostAddress = gethostbyname( address.c_str());
	bcopy(
		reinterpret_cast< char * >( hostAddress->h_addr ),
		reinterpret_cast< char * >( &from.sin_addr ),
		hostAddress->h_length
		);
	from.sin_port = htons( port );
	SocketAddress *socketAddress = reinterpret_cast< SocketAddress * >( &from );
	unsigned addressSize = sizeof( InternetAddress );

	if( recvfrom( mSocketHandle, &datagram[ 0 ], size, 0, socketAddress, &addressSize ) < 0 )
	{
		throw std::runtime_error( "network::UDPSocket::receive: failed to receive" );
	}
	return datagram;
}

Port UDPSocket::getPort()
{
	if( mAddress.sin_port == 0 )
	{
		throw std::runtime_error( "network::UDPSocket::getPort: port has not been bound" );
	}
	return mAddress.sin_port;
}

}
