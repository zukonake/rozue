extern "C"
{

#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>

}

#include <stdexcept>
#include <algorithm>
#include <string>
//
#include <network/common.hpp>
#include "Socket.hpp"

namespace network
{

namespace udp
{

Socket::Socket() :
	mPort( 0 )
{
	mSocketHandle = socket( AF_INET, SOCK_DGRAM, 0 );
	if( mSocketHandle < 0 )
	{
		throw std::runtime_error( "network::UDPSocket::UDPSocket: failed to create socket errno: " +
			std::to_string( errno ));
	}
	mAddress.sin_family = AF_INET;
	mAddress.sin_port = 0;
	mAddress.sin_addr.s_addr = INADDR_ANY;
	std::fill_n( mAddress.sin_zero, 8, 0x00 );
	int option = 1;
	setsockopt( mSocketHandle, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast< char * >( &option ), sizeof( option ));
}

Socket::~Socket()
{
	shutdown( mSocketHandle, 2 );
}

void Socket::bind( Port const &port )
{
	mAddress.sin_port = htons( port );
	if( ::bind( mSocketHandle, reinterpret_cast< sockaddr * >( &mAddress ), sizeof( mAddress )) < 0 )
	{
		throw std::runtime_error( "network::UDPSocket::bind: failed to bind port: " +
			std::to_string( port ) +
			" errno: " + std::to_string( errno ));
	}
	mPort = port;
}

Port Socket::getPort()
{
	if( mPort == 0 )
	{
		throw std::runtime_error( "network::UDPSocket::getPort: port has not been bound" );
	}
	return mPort;
}

}

}
