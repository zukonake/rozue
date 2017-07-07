#include <core/server.hpp>
#include <core/client.hpp>

int main()
{
	Server server;
	Client client( "zukonake" );
	server.connect( client );
	return 0;
}
