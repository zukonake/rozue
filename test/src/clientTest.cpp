#include <UnitTest++/UnitTest++.h>
//
#include <core/typedef.hpp>
#include <core/exception.hpp>
#include <core/server.hpp>
#include <core/client.hpp>

SUITE( client )
{

TEST( connectTo )
{
	Client client( "test" );
	Server server( "server" );
	client.connectTo( server );
	CHECK_EQUAL( client.isConnected(), true );
}

TEST( disconnect1 )
{
	Client client( "test" );
	Server server( "server" );
	client.connectTo( server );
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
	Server server( "server" );
	CHECK_EQUAL( client.isConnected(), false );
	client.connectTo( server );
	CHECK_EQUAL( client.isConnected(), true );
	client.disconnect();
	CHECK_EQUAL( client.isConnected(), false );
}

TEST( getID )
{
	ClientID ID = "test";
	Client client( ID );
	CHECK_EQUAL( client.getID(), ID );
	CHECK_EQUAL( client.isConnected(), false );
	CHECK( client.getID() != "asdf" );
}

}
