#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <set>
#include <thread>
//
#include <network/common.hpp>
#include <network/cold/Socket.hpp>
#include <network/cold/Listener.hpp>
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
	Server();

	~Server();

	void kick( Nickname const &nickname, std::string const &reason = "unspecified" );

	void start( network::Port const &port );
	void stop();

	std::set< Nickname > getClients() const;
	bool const &isRunning() const noexcept;
private:
	void startListener( network::Port const &port );
	void startLoop();

	void stopListener();
	void stopLoop();

	void loop();
	void doTick();
	void listen();
	void connectToClient( std::unique_ptr< network::cold::Socket > clientSocket );

	std::thread mLoopThread;
	std::thread mListenerThread;
	std::unordered_map< Nickname, Connection > mConnections;
	bool mRunning;
	network::cold::Listener mListener;

	Dataset mDataset;
	World mWorld;
};
