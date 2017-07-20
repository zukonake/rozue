#include <utility>
#include <memory>
#include <exception>
#include <string>
#include <thread>
//
#include <utility/Logger.hpp>
#include <core/exception.hpp>
#include "Server.hpp"

Server::Server( ID const &ID, network::Port port ) :
	mID( ID ),
	mPort( port )
{
	utility::logger.log(
		"S",
		utility::Logger::INFO,
		"starting server:\n\tID: " +
		mID + "\n\tport: " +
		std::to_string( mPort ));
}

Server::~Server()
{
	utility::logger.log( "S", utility::Logger::INFO, "closing server: " + mID );
	if( isRunning())
	{
		stop();
	}
	auto clients = getClients();
	for( auto &iClient : clients )
	{
		kick( iClient, "server shutting down" );
	}
}

void Server::kick( ID const &clientID, std::string const &reason )
{
	(void) reason; //TODO
	utility::logger.log( "S", utility::Logger::INFO, "kicking client: " + mID );
	if( mConnections.count( clientID ) == 0 )
	{
		throw Exception::InvalidClientID( "Server::kick: non-existant client: " + clientID );
	}
	mConnections.erase( clientID );
}

void Server::start()
{
	utility::logger.log( "S", utility::Logger::DEBUG, "starting server" );
	mRunning = true;
	startListener();
	startLoop();
}

void Server::stop()
{
	utility::logger.log( "S", utility::Logger::DEBUG, "stopping server" );
	mRunning = false;
	stopListener();
	stopLoop();
}

std::set< ID > Server::getClients() const
{
	std::set< ID > clients;
	for( auto &iConnection : mConnections )
	{
		clients.insert( iConnection.first );
	}
	return clients;
}

ID const &Server::getID() const noexcept
{
	return mID;
}

bool const &Server::isRunning() const noexcept
{
	return mRunning;
}

void Server::startListener()
{
	utility::logger.log( "S", utility::Logger::INFO, "starting TCP listener on port: " + std::to_string( mPort ));
}

void Server::startLoop()
{
	utility::logger.log( "S", utility::Logger::DEBUG, "starting server loop" );
	mLoopThread = std::thread( &Server::loop, this );
}

void Server::stopListener()
{
	utility::logger.log( "S", utility::Logger::DEBUG, "stopping listener" );
}

void Server::stopLoop()
{
	utility::logger.log( "S", utility::Logger::DEBUG, "stopping server loop" );
	mLoopThread.join();
}

void Server::loop()
{
	while( isRunning())
	{
		listenForClients();
		doTick();
	}
}

void Server::doTick()
{
	for( auto &iConnection : mConnections )
	{
		iConnection.second.exchangeData();
	}
}

void Server::listenForClients()
{
}

void Server::connectToClient()
{
	//utility::logger.log( "S", utility::Logger::DEBUG, "connecting to: " + mClientSocket->getRemoteAddress().toString());
	std::unique_ptr< Player > player( new Player( mDataset, mWorld ));
	/*
	mConnections.emplace(
		std::piecewise_construct,
		std::forward_as_tuple( "test" ),
		std::forward_as_tuple( std::move( mClientSocket ), std::move( player )));
	mClientSocket.reset( new network::TCPSocket());*/
}
