#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <set>
#include <thread>
//
#include <network/common.hpp>
#include <network/ColdSocket.hpp>
#include <core/common.hpp>
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
	Server( ID const &ID, network::Port port );

	~Server();

	void kick( ID const &clientID, std::string const &reason = "unspecified" );

	void start();
	void stop();

	std::set< ID > getClients() const;
	ID const &getID() const noexcept;
	bool const &isRunning() const noexcept;
private:
	void startListener();
	void startLoop();

	void stopListener();
	void stopLoop();

	void loop();
	void doTick();
	void listenForClients();
	void connectToClient();

	ID mID;
	network::Port mPort;
	std::thread mLoopThread;
	std::unordered_map< ID, Connection > mConnections;
	bool mRunning;

	Dataset mDataset;
	World mWorld;
};
