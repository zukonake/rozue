#include <core/server.hpp>
#include <core/client.hpp>

int main()
{
	coldline::Client client( "rozueClient" );
	coldline::Server server( &client );
	server.loop();
	return 0;
}
