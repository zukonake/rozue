#include <stdexcept>
#include <string>
//
#include <network/ColdHeader.hpp>
#include "ColdSocket.hpp"

namespace network
{

ColdSocket::ColdSocket( IP const &address, Port const &port ) :
	mConnectedIP( address ),
	mConnectedPort( port )
{
	bind( port );
}

ColdSocket::~ColdSocket()
{
	if( isConnected())
	{
		disconnect();
	}
}

void ColdSocket::connectTo( IP address, Port port )
{
	UDPSocket::send< 0x1 >( ColdPacket<>( ColdHeader::CONNECT ), address, port ); 
	UDPSocket::bind( port );
	ColdPacket<> response = UDPSocket::receive< 0x1 >( address, port );
	if( response.getHeader() != ColdHeader::ACKNOWLEDGE )
	{
		throw std::runtime_error( "network::ColdSocket::connectTo: received invalid header: " +
			std::to_string( static_cast< Byte >( response.getHeader())));
	}
}

void ColdSocket::disconnect()
{
	UDPSocket::send< 0x1 >( ColdPacket<>( ColdHeader::CONNECT ), mConnectedIP, mConnectedPort ); 
	mConnectedIP = "";
	mConnectedPort = 0;
}

bool ColdSocket::isConnected()
{
	return mConnectedIP != "";
}

IP ColdSocket::getRemoteIP()
{
	if( !isConnected())
	{
		throw std::runtime_error( "network::ColdSocket::getRemoteIP: socket is not connected" );
	}
	return mConnectedIP;
}

Port ColdSocket::getRemotePort()
{
	if( !isConnected())
	{
		throw std::runtime_error( "network::ColdSocket::getRemotePort: socket is not connected" );
	}
	return mConnectedPort;
}

}
