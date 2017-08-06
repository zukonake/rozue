#include <stdexcept>
//
#include <UnitTest++/UnitTest++.h>
//
#include <core/common.hpp>
#include <core/Client.hpp>
#include <core/Server.hpp>

SUITE( Server )
{

TEST( kick1 )
{
	Server server;
	server.start( 31337 );
	Client client1( "client1" );
	Client client2( "client2" );
	Client client3( "client3" );
	client1.connectTo( "localhost", 31337 );
	client2.connectTo( "localhost", 31337 );
	client3.connectTo( "localhost", 31337 );
	server.kick( "client2" );
	CHECK_EQUAL( client1.isConnected(), true );
	CHECK_EQUAL( client2.isConnected(), false );
	CHECK_EQUAL( client3.isConnected(), true );
	auto clients = server.getClients();
	CHECK_EQUAL( clients.size(), 2 );
	CHECK_EQUAL( clients.count( client1.getNickname()), 1 );
	CHECK_EQUAL( clients.count( client2.getNickname()), 0 );
	CHECK_EQUAL( clients.count( client3.getNickname()), 1 );
}

TEST( kick2 )
{
	Server server;
	server.start( 31337 );
	Client client1( "client1" );
	Client client2( "client1" );
	client1.connectTo( "localhost", 31337 );
	client2.connectTo( "localhost", 31337 );
	CHECK_THROW( server.kick( "client3" ), std::runtime_error );
	CHECK_EQUAL( client1.isConnected(), true );
	CHECK_EQUAL( client2.isConnected(), true );
	auto clients = server.getClients();
	CHECK_EQUAL( clients.size(), 2 );
	CHECK_EQUAL( clients.count( client1.getNickname()), 1 );
	CHECK_EQUAL( clients.count( client2.getNickname()), 1 );
}

TEST( start1_stop1_isRunning1 )
{
	Server server;
	CHECK_EQUAL( server.isRunning(), false );
	server.start( 31337 );
	CHECK_EQUAL( server.isRunning(), true );
	server.stop();
	CHECK_EQUAL( server.isRunning(), false );
}

TEST( start2 )
{
	Server server;
	server.start( 31337 );
	CHECK_EQUAL( server.isRunning(), true );
	CHECK_THROW( server.start( 31337 ), std::runtime_error );
	CHECK_EQUAL( server.isRunning(), true );
}

TEST( stop2 )
{
	Server server;
	CHECK_EQUAL( server.isRunning(), false );
	CHECK_THROW( server.stop(), std::runtime_error );
	CHECK_EQUAL( server.isRunning(), false );
}

TEST( getClients1 )
{
	Server server;
	server.start( 31337 );
	Client client1( "client1" );
	Client client2( "client1" );
	client1.connectTo( "localhost", 31337 );
	client2.connectTo( "localhost", 31337 );
	auto clients = server.getClients();
	CHECK_EQUAL( clients.size(), 2 );
	CHECK_EQUAL( clients.count( client1.getNickname()), 1 );
	CHECK_EQUAL( clients.count( client2.getNickname()), 1 );
	client2.disconnect();
	clients = server.getClients();
	CHECK_EQUAL( clients.size(), 1 );
	CHECK_EQUAL( clients.count( client1.getNickname()), 1 );
	CHECK_EQUAL( clients.count( client2.getNickname()), 0 );
}

}
