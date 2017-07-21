#pragma once

#include <set>
#include <thread>
#include <string>
//
#include <network/common.hpp>

namespace network
{

class Server
{
public:
	Server();

	virtual ~Server();

	void kick( IP const &clientIP, std::string const &reason = "unspecified" );

	void startListener( Port const &port );
	void stopListener();

	std::set< IP > getClients() const;
private:
	void listenForClients();
	void connectToClient();

	Port mPort;
	std::thread mListenerThread;
	std::set< IP > mClients;
}

}
