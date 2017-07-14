#include <utility>
#include <memory>
#include <exception>
#include <string>
#include <thread>
//
#include <utility/logger.hpp>
#include <core/exception.hpp>
#include "server.hpp"

Server::Server( Network::ID const &ID, Network::Port port ) :
	mID( ID ),
	mPort( port )
{
	globalLogger.log(
		"S",
		Logger::INFO,
		"starting server:\n\tID: " +
		mID + "\n\tport: " +
		std::to_string( mPort ));
}

Server::~Server()
{
	globalLogger.log( "S", Logger::INFO, "closing server: " + mID );
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

void Server::kick( Network::ID const &clientID, std::string const &reason )
{
	(void) reason; //TODO
	globalLogger.log( "S", Logger::INFO, "kicking client: " + mID );
	if( mConnections.count( clientID ) == 0 )
	{
		throw Exception::InvalidClientID( "Server::kick: non-existant client: " + clientID );
	}
	mConnections.erase( clientID );
}

void Server::start()
{
	globalLogger.log( "S", Logger::DEBUG, "starting server" );
	mRunning = true;
	startListener();
	startLoop();
}

void Server::stop()
{
	globalLogger.log( "S", Logger::DEBUG, "stopping server" );
	mRunning = false;
	stopListener();
	stopLoop();
}

std::set< Network::ID > Server::getClients() const
{
	std::set< Network::ID > clients;
	for( auto &iConnection : mConnections )
	{
		clients.insert( iConnection.first );
	}
	return clients;
}

Network::ID const &Server::getID() const noexcept
{
	return mID;
}

bool const &Server::isRunning() const noexcept
{
	return mRunning;
}

void Server::startListener()
{
	globalLogger.log( "S", Logger::INFO, "starting TCP listener on port: " + std::to_string( mPort ));
	mListener.setBlocking( false );
	if( mListener.listen( mPort ) != Network::Socket::Done )
	{
		throw Exception::CouldNotStartListener( "Server::startListener: could not start listener on port: " +
			std::to_string( mPort ));
	}
	mClientSocket.reset( new Network::TCPSocket());
}

void Server::startLoop()
{
	globalLogger.log( "S", Logger::DEBUG, "starting server loop" );
	mLoopThread = std::thread( &Server::loop, this );
}

void Server::stopListener()
{
	globalLogger.log( "S", Logger::DEBUG, "stopping listener" );
	mListener.close();
}

void Server::stopLoop()
{
	globalLogger.log( "S", Logger::DEBUG, "stopping server loop" );
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
	if( mListener.accept( *mClientSocket ) == Network::Socket::Done )
	{
		connectToClient();
	}
}

void Server::connectToClient()
{
	globalLogger.log( "S", Logger::DEBUG, "connecting to: " + mClientSocket->getRemoteAddress().toString());
	std::unique_ptr< Player > player( new Player( mDataset, mWorld ));
	mConnections.emplace(
		std::piecewise_construct,
		std::forward_as_tuple( "test" ),
		std::forward_as_tuple( std::move( mClientSocket ), std::move( player )));
	mClientSocket.reset( new Network::TCPSocket());
}
