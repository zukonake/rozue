extern "C"
{

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

Port UDPSocket::getPort()
{
	if( mAddress.sin_port == 0 )
	{
		throw std::runtime_error( "network::UDPSocket::getPort: port has not been bound" );
	}
	return mAddress.sin_port;
}

}
