#include <core/server.hpp>
#include <core/client.hpp>

int main()
{
	Server server( "localServer", 31337 );
	server.start();
	Client client( "localClient" );
	client.connectTo( "localhost", 31337 );
	return 0;
}
