#include <thread>
#include <mutex>
#include <future>
//
#include <UnitTest++/UnitTest++.h>
//
#include <network/common.hpp>
#include <network/UDPSocket.hpp>

using namespace network;

SUITE( network_UDPSocket )
{

TEST( bind1 )
{
	UDPSocket socket;
	socket.bind( 31337 );
	CHECK_EQUAL( socket.getPort(), 31337 );
}

TEST( send1 )
{
	UDPSocket socket;
	UDPSocket receiver;
	Data datagram{ 1, 3, 3, 7 };
	std::promise< Data > promise;
	auto future = promise.get_future();

	socket.bind( 31337 );
	std::thread receiverThread(
		[ &receiver ]( std::promise< Data > && promise )
		{
			promise.set_value( receiver.receive( "localhost", 31337 ));
		},
		std::move( promise ));
	socket.send( datagram, "localhost", 31337 );
	receiverThread.join();
	Data result = future.get();

	CHECK( result[ 0 ] == 1 );
	CHECK( result[ 1 ] == 3 );
	CHECK( result[ 2 ] == 3 );
	CHECK( result[ 3 ] == 7 );
}

TEST( send2 )
{
	UDPSocket socket;
	socket.bind( 31337 );

	Data datagram{ 1, 3, 3, 7 };
	socket.send( datagram, "localhost", 31337 );

	/*auto result = UDPSocket.receive( "localhost", 31337 );
	CHECK( result[ 0 ] == 1 );
	CHECK( result[ 1 ] == 3 );
	CHECK( result[ 2 ] == 3 );
	CHECK( result[ 3 ] == 7 );*/
}

}
