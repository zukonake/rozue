#pragma once

#include <unordered_map>
#include <set>
//
#include <core/typedef.hpp>
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
	Server( ServerID const &ID );

	void kick( ClientID client );

	void run();
	std::set< ClientID > getClients();

	ServerID const &getID() const noexcept;
private:
	void connectedWith( Client &client );
	void disconnectedWith( ClientID clientID );
	void doTick();

	ServerID mID;
	Dataset mDataset;
	World mWorld;
	std::unordered_map< ClientID, Connection > mConnections;
};
