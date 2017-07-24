#include <UnitTest++/UnitTest++.h>
//
#include <core/common.hpp>
#include <core/Server.hpp>
#include <core/Client.hpp>

SUITE( Client )
{

	//TODO
TEST( getNickname1 )
{
	Nickname nickname = "test";
	Client client( nickname );
	CHECK_EQUAL( client.getNickname(), nickname );
	CHECK_EQUAL( client.isConnected(), false );
}

}
