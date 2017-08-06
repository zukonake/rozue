#include <stdexcept>
#include <future>
#include <mutex>
//
#include <UnitTest++/UnitTest++.h>
//
#include <network/ColdSocket.hpp>
#include <network/ColdListener.hpp>

using namespace network;

SUITE( ColdListener )
{

TEST( listen1_accept1_getPort1 )
{
	ColdListener listener;
	ColdSocket socket;
	std::promise< std::unique_ptr< ColdSocket > > promise;
	auto future = promise.get_future();

	listener.listen( 31337 );
	CHECK_EQUAL( listener.getPort(), 31337 );
	std::thread listenerThread(
		[ &listener ]( std::promise< std::unique_ptr< ColdSocket > > && promise )
		{
			promise.set_value( listener.accept());
		},
		std::move( promise ));
	socket.connectTo( "localhost", 31337 );
	listenerThread.join();
	auto remoteSocket = future.get();
	CHECK_EQUAL( socket.isConnected(), true );
	CHECK_EQUAL( remoteSocket->isConnected(), true );
}

TEST( listen2 )
{
	ColdListener listener1;
	ColdListener listener2;
	listener1.listen( 31337 );
	CHECK_THROW( listener2.listen( 31337 ), std::runtime_error );
}

TEST( accept2 )
{
	ColdListener listener;
	CHECK_THROW( listener.accept(), std::runtime_error );
}

TEST( getPort2 )
{
	ColdListener listener;
	CHECK_THROW( listener.getPort(), std::runtime_error );
}

}
