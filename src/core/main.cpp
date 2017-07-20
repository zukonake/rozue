#include <core/Server.hpp>
#include <core/Client.hpp>

int main()
{
	Server server( "localServer", 31337 );
	server.start();
	Client client( "localClient" );
	client.connectTo( "localhost", 31337 );
	return 0;
}
