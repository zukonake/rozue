#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <set>
#include <thread>
//
#include <network/common.hpp>
#include <network/ColdSocket.hpp>
#include <core/Connection.hpp>
#include <data/Dataset.hpp>
#include <world/World.hpp>

class Client;

/**
 * Server manages Connections and its World.
 */
class Server
{
public:
	Server();

	~Server();

	void kick( network::IP const &IP, std::string const &reason = "unspecified" );

	void start( network::Port const &port );
	void stop();

	std::set< network::IP > getClients() const;
	bool const &isRunning() const noexcept;
private:
	void startListener( network::Port const &port );
	void startLoop();

	void stopListener();
	void stopLoop();

	void loop();
	void doTick();
	void listenForClients();
	void connectToClient( std::unique_ptr< network::ColdSocket > clientSocket );

	std::thread mLoopThread;
	std::unordered_map< network::IP, Connection > mConnections;
	bool mRunning;

	Dataset mDataset;
	World mWorld;
};
