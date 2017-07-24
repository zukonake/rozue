#pragma once

#include <memory>
//
#include <network/common.hpp>
#include <network/UDPSocket.hpp>

namespace network
{

class ColdSocket;

class ColdListener : UDPSocket
{
public:
	void listen( Port const &port );
	std::unique_ptr< ColdSocket > accept();
};

}
