#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <set>
#include <thread>
//
#include <core/network.hpp>
#include <core/connection.hpp>
#include <data/dataset.hpp>
#include <world/world.hpp>

class Client;

/**
 * Server manages Connections and its World.
 */
class Server
{
public:
	Server( Network::ID const &ID, Network::Port port );

	~Server();

	void kick( Network::ID const &clientID, std::string const &reason = "unspecified" );

	void start();
	void stop();

	std::set< Network::ID > getClients() const;
	Network::ID const &getID() const noexcept;
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

	Network::ID mID;
	Network::Port mPort;
	Network::TCPListener mListener;
	std::unique_ptr< Network::TCPSocket > mClientSocket;
	std::thread mLoopThread;
	std::unordered_map< Network::ID, Connection > mConnections;
	bool mRunning;

	Dataset mDataset;
	World mWorld;
};
