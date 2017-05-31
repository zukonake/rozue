#include <core/server.hpp>
#include <core/client.hpp>

int main()
{
	coldline::Client client( "rozueClient" );
	coldline::Server server;
	client.connect( &server );
	server.loop();
	return 0;
}
