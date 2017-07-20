#pragma once

#include <cstdint>
//
#include <network/common.hpp>

namespace network
{

class UDPSocket
{
public:
	DatagramSize static const maxDatagramSize = -1;
	UDPSocket();

	void bind( Port const &port );

	void send( Data const &datagram, IP const &address, Port const &port );
	Data receive( IP const &address, Port const &port );

	Port const &getPort();
private:
	SocketHandle mSocketHandle;
	SocketAddress mAddress;
};

}
