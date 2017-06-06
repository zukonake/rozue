#include <utility>
#include <stdexcept>
//
#include <data/config.hpp>
#include <data/inputData.hpp>
#include <core/client.hpp>
#include <world/generator/flatGenerator.hpp>
#include "server.hpp"

namespace coldline
{

Server::Server( Client *client ) :
	mWorld( new FlatGenerator( mDataset )),
	mPlayer( mDataset, mWorld ),
	mClient( client )
{
	mClient->connect( this );
}

Server::~Server()
{
	mClient->disconnect();
}

void Server::loop()
{
	while( mClient != nullptr )
	{
		mWorld.simulate();
		mPlayer.receiveInputData( mClient->requestInputData());
		mClient->receiveOutputData( mPlayer.requestOutputData());
	}
}

void Server::disconnect()
{
	mClient = nullptr;
}

}
