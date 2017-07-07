#pragma once

#include <unordered_map>
//
#include <core/typedef.hpp>
#include <core/connection.hpp>
#include <data/dataset.hpp>
#include <world/world.hpp>

class Client;

class Server
{
public:
	void connect( Client &client );
	void disconnect( ClientID clientID );
	void kick( ClientID client );

	void run();
private:
	void doTick();

	Dataset mDataset;
	World mWorld;
	std::unordered_map< ClientID, Connection > mConnections;
};
