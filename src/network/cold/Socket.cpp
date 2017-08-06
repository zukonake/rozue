#include <stdexcept>
#include <string>
//
#include <network/cold/Header.hpp>
#include "Socket.hpp"

namespace network
{

namespace cold
{

Socket::Socket( IP const &address, Port const &port ) :
	mConnectedIP( address ),
	mConnectedPort( port )
{
	bind( port );
}

Socket::~Socket()
{
	if( isConnected())
	{
		disconnect();
	}
}

void Socket::connectTo( IP address, Port port )
{
	udp::Socket::bind( port );
	udp::Socket::send< 0x1 >( Packet<>( Header::CONNECT ), address, port );
	Packet<> response = udp::Socket::receive< 0x1 >( address, port );
	if( response.getHeader() != Header::ACKNOWLEDGE )
	{
		throw std::runtime_error( "network::Socket::connectTo: received invalid header: " +
			std::to_string( static_cast< Byte >( response.getHeader())));
	}
}

void Socket::disconnect()
{
	udp::Socket::send< 0x1 >( Packet<>( Header::CONNECT ), mConnectedIP, mConnectedPort ); 
	mConnectedIP = "";
	mConnectedPort = 0;
}

bool Socket::isConnected()
{
	return mConnectedIP != "";
}

IP Socket::getRemoteIP()
{
	if( !isConnected())
	{
		throw std::runtime_error( "network::Socket::getRemoteIP: socket is not connected" );
	}
	return mConnectedIP;
}

Port Socket::getRemotePort()
{
	if( !isConnected())
	{
		throw std::runtime_error( "network::Socket::getRemotePort: socket is not connected" );
	}
	return mConnectedPort;
}

}

}
