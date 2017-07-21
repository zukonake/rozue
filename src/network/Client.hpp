#pragma once

#include <network/common.hpp>

namespace network
{

class Client
{
public:
	Client() = default;
	virtual ~Client() = default;

	void connectTo( network::IP const &IPAddress, network::Port const &port );
	void disconnect();

	bool isConnected() const noexcept;
private:
	UDPSocket mSocket;
}

}
