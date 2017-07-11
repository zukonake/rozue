#include <UnitTest++/UnitTest++.h>
//
#include <core/client.hpp>
#include <core/server.hpp>
#include <core/exception.hpp>

SUITE( server )
{

TEST( kick1 )
{
	Client client1( "client1" );
	Client client2( "client2" );
	Client client3( "client3" );
	Server server( "server" );
	client1.connectTo( server );
	client2.connectTo( server );
	client3.connectTo( server );
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
	Client client1( "client1" );
	Client client2( "client1" );
	Server server( "server" );
	client1.connectTo( server );
	client2.connectTo( server );
	CHECK_THROW( server.kick( "client3" ), Exception::InvalidClientID );
	CHECK_EQUAL( client1.isConnected(), true );
	CHECK_EQUAL( client2.isConnected(), true );
	auto clients = server.getClients();
	CHECK_EQUAL( clients.size(), 2 );
	CHECK_EQUAL( clients.count( client1.getID()), 1 );
	CHECK_EQUAL( clients.count( client2.getID()), 1 );
}

TEST( getClients )
{
	Client client1( "client1" );
	Client client2( "client1" );
	Server server( "server" );
	client1.connectTo( server );
	client2.connectTo( server );
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

TEST( getID )
{
	ServerID ID = "localServer";
	Server server( ID );
	CHECK_EQUAL( server.getID(), ID );
}

}
