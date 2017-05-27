#include <core/server.hpp>
#include <core/client.hpp>

int main()
{
	Client client( "rozueClient" );
	Server server;
	client.connect( &server );
	server.loop();
	return 0;
}
