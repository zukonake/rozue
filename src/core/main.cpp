#include <core/server.hpp>
#include <core/client.hpp>

int main()
{
	Server server( "localServer" );
	Client client( "zukonake" );
	client.connectTo( server );
	return 0;
}
