#pragma once

#include <utility>
#include <map>
#include <string>
//
#include <data/dataset.hpp>
#include <world/world.hpp>
#include <core/player.hpp>

namespace coldline
{

class Client;

class Server
{
	public:
	Server();
	~Server();

	void loop();

	void connect( Client *client );
	void disconnect( Client *client );
	private:
	void cleanClients();

	std::map< std::string, std::pair< Player, Client * > > mClients;

	Dataset mDataset;
	World mWorld;
};

}
