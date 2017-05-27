#include <core/server.hpp>
#include <data/outputData.hpp>
#include <data/inputData.hpp>
#include "client.hpp"

#include <iostream> //TODO

Client::Client( std::string const &name ) :
	mName( name ),
	mServer( nullptr )
{

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
		SFMLClient::getView().setCenter( outputData.viewPosition );
		SFMLClient::getView().zoom( outputData.zoom );
		if( !SFMLClient::isRunning())
		{
			SFMLClient::openWindow(
				{ 1024, 768 },
				"Rozue",
				60,
				true,
				0 );
		}
		render( outputData );
		update();
	}
}

void Client::connect( Server* server )
{
	if( !isConnected())
	{
		mServer = server;
		mServer->connect( this );
	}
}

void Client::disconnect()
{
	if( isConnected())
	{
		mServer->disconnect( this );
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
	auto sprites = outputData.sprites;
	for( uint16_t i = 0; i < sprites.size() + i; i++ )
	{
		SFMLClient::getWindow().draw( sprites.front());
		sprites.pop();
	}
}
