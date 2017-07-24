#pragma once

#include <network/common.hpp>

namespace network
{

class UDPSocket
{
public:
	DatagramSize static const maxDatagramSize = -1;
	UDPSocket();
	~UDPSocket();

	void bind( Port const &port );

	void send( Data const &datagram, IP const &address, Port const &port );
	Data receive( IP const &address, Port const &port, DatagramSize const &size );

	Port getPort(); //TODO throw if port not bound
private:
	SocketHandle mSocketHandle;
	InternetAddress mAddress;
};

}
