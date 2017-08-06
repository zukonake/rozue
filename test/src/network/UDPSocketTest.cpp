#include <stdexcept>
#include <thread>
#include <mutex>
#include <future>
//
#include <UnitTest++/UnitTest++.h>
//
#include <network/common.hpp>
#include <network/udp/Socket.hpp>

using namespace network;

SUITE( network_udp_Socket )
{

TEST( bind1 )
{
	udp::Socket socket;
	socket.bind( 31337 );
	CHECK_EQUAL( socket.getPort(), 31337 );
}

TEST( bind2 )
{
	udp::Socket socket1;
	udp::Socket socket2;
	socket1.bind( 31337 );
	CHECK_THROW( socket2.bind( 31337 ), std::runtime_error );
	CHECK_THROW( socket2.getPort(), std::runtime_error );
}

TEST( send1 )
{
	udp::Socket socket;
	udp::Socket receiver;
	Data< 4 > datagram{{ 1, 3, 3, 7 }};
	std::promise< Data< 4 > > promise;
	auto future = promise.get_future();

	socket.bind( 31337 );
	std::thread receiverThread(
		[ &receiver ]( std::promise< Data< 4 > > && promise )
		{
			promise.set_value( receiver.receive< 4 >( "localhost", 31337 ));
		},
		std::move( promise ));
	socket.send< 4 >( datagram, "localhost", 31337 );
	receiverThread.join();
	Data< 4 > result = future.get();

	CHECK( result[ 0 ] == 1 );
	CHECK( result[ 1 ] == 3 );
	CHECK( result[ 2 ] == 3 );
	CHECK( result[ 3 ] == 7 );
}

TEST( send2 )
{
	udp::Socket socket;
	socket.bind( 31337 );

	Data< 4 > datagram{{ 1, 3, 3, 7 }};
	socket.send< 4 >( datagram, "localhost", 31337 );

	/*auto result = udp::Socket.receive( "localhost", 31337 );
	CHECK( result[ 0 ] == 1 );
	CHECK( result[ 1 ] == 3 );
	CHECK( result[ 2 ] == 3 );
	CHECK( result[ 3 ] == 7 );*/
}

}
