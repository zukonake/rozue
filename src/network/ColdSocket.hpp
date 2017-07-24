#pragma once

#include <network/common.hpp>
#include <network/UDPSocket.hpp>

namespace network
{

class ColdSocket : UDPSocket
{
public:
	ColdSocket();

	virtual ~ColdSocket();

	void connectTo( IP const &address, Port const &port );
	void disconnect();

	virtual void send( Data const &datagram );
	virtual Data receive();

	bool isConnected();
	IP getRemoteIP();
	Port getRemotePort();
};

}
