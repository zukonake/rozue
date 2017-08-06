#include <utility>
#include <memory>
#include <stdexcept>
#include <string>
#include <thread>
//
#include <utility/Logger.hpp>
#include <network/common.hpp>
#include <network/cold/Socket.hpp>
#include "Server.hpp"

Server::Server() :
	mRunning( false )
{
	utility::logger.log( "S", utility::Logger::DEBUG, "constructing server" );
}

Server::~Server()
{
	utility::logger.log( "S", utility::Logger::DEBUG, "destructing server" );
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

void Server::kick( network::IP const &IP, std::string const &reason )
{
	(void) reason; //TODO
	utility::logger.log( "S", utility::Logger::INFO, "kicking client: " + IP );
	if( mConnections.count( IP ) == 0 )
	{
		throw std::runtime_error( "Server::kick: non-existant client: " + IP );
	}
	mConnections.erase( IP );
}

void Server::start( network::Port const &port )
{
	utility::logger.log( "S", utility::Logger::INFO, "starting server" );
	if( mRunning )
	{
		throw std::runtime_error( "Server::start: server is already running" );
	}
	mRunning = true;
	startListener( port );
	startLoop();
}

void Server::stop()
{
	utility::logger.log( "S", utility::Logger::DEBUG, "stopping server" );
	if( !mRunning )
	{
		throw std::runtime_error( "Server::start: server is already stopped" );
	}
	mRunning = false;
	stopListener();
	stopLoop();
}

std::set< network::IP > Server::getClients() const
{
	std::set< network::IP > clients;
	for( auto &iConnection : mConnections )
	{
		clients.insert( iConnection.first );
	}
	return clients;
}

bool const &Server::isRunning() const noexcept
{
	return mRunning;
}

void Server::startListener( network::Port const &port )
{
	utility::logger.log( "S", utility::Logger::INFO, "starting listener on port: " + std::to_string( port ));
	mListener.listen( port );
	mListenerThread = std::thread( &Server::listen, this );
}

void Server::startLoop()
{
	utility::logger.log( "S", utility::Logger::DEBUG, "starting server loop" );
	mLoopThread = std::thread( &Server::loop, this );
}

void Server::stopListener()
{
	utility::logger.log( "S", utility::Logger::INFO, "stopping listener" );
	mListenerThread.join();
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

void Server::listen()
{

}

void Server::connectToClient( std::unique_ptr< network::cold::Socket > clientSocket )
{
	utility::logger.log( "S", utility::Logger::INFO, "connecting to: " + clientSocket->getRemoteIP());
	std::unique_ptr< Player > player( new Player( mDataset, mWorld ));
	/*
	mConnections.emplace(
		std::piecewise_construct,
		std::forward_as_tuple( "test" ),
		std::forward_as_tuple( std::move( mClientSocket ), std::move( player )));
	mClientSocket.reset( new network::TCPSocket());*/
}
