#include <core/Server.hpp>
#include <core/Client.hpp>

int main()
{
	Server server;
	server.start( 31337 );
	Client client( "localClient" );
	client.connectTo( "localhost", 31337 );
	return 0;
}
