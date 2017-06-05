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
//TODO handles only one client now
class Server
{
	public:
	Server( Client *client );
	~Server();

	void loop();

	void disconnect();
	private:
	Dataset mDataset;
	World mWorld;
	Player mPlayer;
	Client *mClient;
};

}
