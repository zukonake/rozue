#include <UnitTest++/UnitTest++.h>
//
#include <core/client.hpp>
#include <core/server.hpp>
#include <core/exception.hpp>

SUITE( server )
{

TEST( kick1 )
{
	Server server( "server", 31337 );
	server.start();
	Client client1( "client1" );
	Client client2( "client2" );
	Client client3( "client3" );
	client1.connectTo( "localhost", 31337 );
	client2.connectTo( "localhost", 31337 );
	client3.connectTo( "localhost", 31337 );
	server.kick( client2.getID());
	CHECK_EQUAL( client1.isConnected(), true );
	CHECK_EQUAL( client2.isConnected(), false );
	CHECK_EQUAL( client3.isConnected(), true );
	auto clients = server.getClients();
	CHECK_EQUAL( clients.size(), 2 );
	CHECK_EQUAL( clients.count( client1.getID()), 1 );
	CHECK_EQUAL( clients.count( client2.getID()), 0 );
	CHECK_EQUAL( clients.count( client3.getID()), 1 );
}

TEST( kick2 )
{
	Server server( "server", 31337 );
	server.start();
	Client client1( "client1" );
	Client client2( "client1" );
	client1.connectTo( "localhost", 31337 );
	client2.connectTo( "localhost", 31337 );
	CHECK_THROW( server.kick( "client3" ), Exception::InvalidClientID );
	CHECK_EQUAL( client1.isConnected(), true );
	CHECK_EQUAL( client2.isConnected(), true );
	auto clients = server.getClients();
	CHECK_EQUAL( clients.size(), 2 );
	CHECK_EQUAL( clients.count( client1.getID()), 1 );
	CHECK_EQUAL( clients.count( client2.getID()), 1 );
}

TEST( start_stop_isRunning1 )
{
	Server server( "server", 31337 );
	CHECK_EQUAL( server.isRunning(), false );
	server.start();
	CHECK_EQUAL( server.isRunning(), true );
	server.stop();
	CHECK_EQUAL( server.isRunning(), false );
}

TEST( stop1 )
{
	Server server( "server", 31337 );
	CHECK_EQUAL( server.isRunning(), false );
	CHECK_THROW( server.stop(), Exception::NotRunning );
	CHECK_EQUAL( server.isRunning(), false );
}

TEST( getClients1 )
{
	Server server( "server", 31337 );
	server.start();
	Client client1( "client1" );
	Client client2( "client1" );
	client1.connectTo( "localhost", 31337 );
	client2.connectTo( "localhost", 31337 );
	auto clients = server.getClients();
	CHECK_EQUAL( clients.size(), 2 );
	CHECK_EQUAL( clients.count( client1.getID()), 1 );
	CHECK_EQUAL( clients.count( client2.getID()), 1 );
	client2.disconnect();
	clients = server.getClients();
	CHECK_EQUAL( clients.size(), 1 );
	CHECK_EQUAL( clients.count( client1.getID()), 1 );
	CHECK_EQUAL( clients.count( client2.getID()), 0 );
}

TEST( getID1 )
{
	Network::ID ID = "localServer";
	Server server( ID, 31337 );
	server.start();
	CHECK_EQUAL( server.getID(), ID );
}

}
