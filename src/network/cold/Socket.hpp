#pragma once

#include <utility/NonCopyable.hpp>
//
#include <network/common.hpp>
#include <network/udp/Socket.hpp>
#include <network/cold/Packet.hpp>

namespace network
{

namespace cold
{

class Socket : virtual utility::NonCopyable, udp::Socket
{
public:
	Socket() = default;
	Socket( IP const &address, Port const &port );

	virtual ~Socket();

	void connectTo( IP address, Port port );
	void disconnect();

	template< DatagramSize size >
	void send( Packet< size > const &packet );
	template< DatagramSize size >
	Packet< size > receive();

	bool isConnected();
	IP getRemoteIP();
	Port getRemotePort();
private:
	IP mConnectedIP;
	Port mConnectedPort;
};

template< DatagramSize size >
void Socket::send( Packet< size > const &packet )
{
	packet.setHeader( Packet< size >::SEND );
	udp::Socket::send( packet.getData(), mConnectedIP, mConnectedPort );
}

template< DatagramSize size >
Packet< size > Socket::receive()
{
	return Packet< size >( udp::Socket::receive< size + 1 >( mConnectedIP, mConnectedPort ));
}

}

}
