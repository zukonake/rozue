#pragma once

#include <memory>
//
#include <network/common.hpp>
#include <network/udp/Socket.hpp>
#include <network/cold/Socket.hpp>

namespace network
{

namespace cold
{

class Listener : udp::Socket
{
public:
	void listen( Port const &port );
	std::unique_ptr< cold::Socket > accept();
	Port getPort();
};

}

}
