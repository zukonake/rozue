#include <UnitTest++/UnitTest++.h>
//
#include <network/exception.hpp>
#include <network/Server.hpp>
#include <network/Client.hpp>

using namespace network;

SUITE( network_Client )
{

TEST( connectTo1 )
{
	Client client( "test" );
	Server server( "server", 31337 );
	server.start();
	client.connectTo( "localhost", 31337 );
	CHECK_EQUAL( client.isConnected(), true );
}

TEST( connectTo2 )
{
	Client client( "test" );
	CHECK_THROW( client.connectTo( "invalid", 31337 ), CouldNotConnect );
	CHECK_EQUAL( client.isConnected(), false );
}

TEST( disconnect1 )
{
	Client client( "test" );
	Server server( "server", 31337 );
	server.start();
	client.connectTo( "localhost", 31337 );
	client.disconnect();
	CHECK_EQUAL( client.isConnected(), false );
}

TEST( disconnect2 )
{
	Client client( "test" );
	CHECK_THROW( client.disconnect(), InvalidState );
	CHECK_EQUAL( client.isConnected(), false );
}

TEST( isConnected )
{
	Client client( "test" );
	Server server( "server", 31337 );
	server.start();
	CHECK_EQUAL( client.isConnected(), false );
	client.connectTo( "localhost", 31337 );
	CHECK_EQUAL( client.isConnected(), true );
	client.disconnect();
	CHECK_EQUAL( client.isConnected(), false );
}

}
