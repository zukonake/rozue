#pragma once

#include <network/common.hpp>
#include <network/UDPSocket.hpp>

namespace network
{

class ColdSocket
{
public:
	ColdSocket();

	~ColdSocket();

	void connectTo( IP const &address, Port const &port );
	void disconnect();

	void send( Data const &datagram );
	Data receive();

	bool isConnected();
	IP getRemoteIP();
	Port getRemotePort();
private:
	UDPSocket socket;
};

}
