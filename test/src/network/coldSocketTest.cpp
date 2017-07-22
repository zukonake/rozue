#include <UnitTest++/UnitTest++.h>
//

SUITE( Client )
{

TEST( connectTo1 )
{
	Client client;
	Server server;
	server.start( 31337 );
	client.connectTo( "localhost", 31337 );
	CHECK_EQUAL( client.isConnected(), true );
}

TEST( connectTo2 )
{
	Client client();
	CHECK_THROW( client.connectTo( "invalid", 31337 ), Exception::CouldNotConnect );
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
	CHECK_THROW( client.disconnect(), Exception::NotConnected );
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

TEST( getID )
{
	ID ID = "test";
	Client client( ID );
	CHECK_EQUAL( client.getID(), ID );
	CHECK_EQUAL( client.isConnected(), false );
}

}
