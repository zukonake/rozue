#include <core/server.hpp>
#include <data/config.hpp>
#include <data/outputData.hpp>
#include <data/inputData.hpp>
#include "client.hpp"

namespace coldline
{

Client::Client( std::string const &name ) :
	mServer( nullptr ),
	mName( name )
{
	SFMLClient::openWindow(
		mDataset.at< Config >( "config" ).screenSize,
		"Rozue",
		60,
		true,
		0 );
}

Client::~Client()
{
	disconnect();
}

InputData Client::requestInputData() noexcept
{
	if( isConnected())
	{
		InputData returnValue;
		returnValue.events = SFMLClient::getEvents();
		return returnValue;
	}
	else
	{
		return InputData();
	}
}

void Client::receiveOutputData( OutputData outputData ) noexcept
{
	if( isConnected())
	{
		if( outputData.playing == false )
		{
			disconnect();
			return;
		}
		render( outputData );
		update();
	}
}

void Client::connect( Server *server )
{
	mServer = server;
}

void Client::disconnect()
{
	if( isConnected())
	{
		mServer->disconnect();
		mServer = nullptr;
	}
}

bool Client::isConnected() const noexcept
{
	return mServer != nullptr;
}

std::string const &Client::getName() const noexcept
{
	return mName;
}

void Client::render( OutputData const &outputData )
{
	auto renderQueue = outputData.renderQueue;
	for( unsigned i = 0; i < renderQueue.size() + i; i++ )
	{
		SFMLClient::getWindow().draw( renderQueue.front());
		renderQueue.pop();
	}
}

}
