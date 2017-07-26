#pragma once

#include <utility/NonCopyable.hpp>
//
#include <network/common.hpp>
#include <network/UDPSocket.hpp>
#include <network/ColdPacket.hpp>

namespace network
{

class ColdSocket : virtual utility::NonCopyable, UDPSocket
{
public:
	ColdSocket() = default;
	ColdSocket( IP const &address, Port const &port );

	virtual ~ColdSocket();

	void connectTo( IP address, Port port );
	void disconnect();

	template< DatagramSize size >
	void send( ColdPacket< size > const &packet );
	template< DatagramSize size >
	ColdPacket< size > receive();

	bool isConnected();
	IP getRemoteIP();
	Port getRemotePort();
private:
	IP mConnectedIP;
	Port mConnectedPort;
};

template< DatagramSize size >
void ColdSocket::send( ColdPacket< size > const &packet )
{
	packet.setHeader( ColdPacket< size >::SEND );
	UDPSocket::send( packet.getData(), mConnectedIP, mConnectedPort );
}

template< DatagramSize size >
ColdPacket< size > ColdSocket::receive()
{
	return ColdPacket< size >( UDPSocket::receive< size + 1 >( mConnectedIP, mConnectedPort ));
}

}
