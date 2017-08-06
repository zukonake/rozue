#include <stdexcept>
#include <future>
#include <mutex>
//
#include <UnitTest++/UnitTest++.h>
//
#include <network/cold/Socket.hpp>
#include <network/cold/Listener.hpp>

using namespace network;

SUITE( network_cold_Socket )
{

TEST( connectTo1_disconnect1_isConnected1_getRemoteIP1_getRemotePort1 )
{
	cold::Listener listener;
	cold::Socket socket;
	std::promise< std::unique_ptr< cold::Socket > > promise;
	auto future = promise.get_future();

	CHECK_EQUAL( socket.isConnected(), false );
	listener.listen( 31337 );
	std::thread listenerThread(
		[ &listener ]( std::promise< std::unique_ptr< cold::Socket > > && promise )
		{
			promise.set_value( listener.accept());
		},
		std::move( promise ));
	socket.connectTo( "localhost", 31337 );
	listenerThread.join();
	auto remoteSocket = future.get();
	CHECK_EQUAL( socket.isConnected(), true );
	CHECK_EQUAL( socket.getRemoteIP(), "127.0.0.1" );
	CHECK_EQUAL( socket.getRemotePort(), 31337 );
	CHECK_EQUAL( remoteSocket->isConnected(), true );
	CHECK_EQUAL( remoteSocket->getRemoteIP(), "127.0.0.1" );
	CHECK_EQUAL( remoteSocket->getRemotePort(), 31337 );
	socket.disconnect();
	CHECK_EQUAL( socket.isConnected(), false );
	CHECK_EQUAL( remoteSocket->isConnected(), false );
}

TEST( connectTo2 )
{
	cold::Socket socket;
	CHECK_THROW( socket.connectTo( "invalid", 31337 ), std::runtime_error );
	CHECK_EQUAL( socket.isConnected(), false );
}

TEST( disconnect2 )
{
	cold::Listener listener;
	cold::Socket socket;
	std::promise< std::unique_ptr< cold::Socket > > promise;
	auto future = promise.get_future();

	listener.listen( 31337 );
	std::thread listenerThread(
		[ &listener ]( std::promise< std::unique_ptr< cold::Socket > > && promise )
		{
			promise.set_value( listener.accept());
		},
		std::move( promise ));
	socket.connectTo( "localhost", 31337 );
	listenerThread.join();
	auto remoteSocket = future.get();
	remoteSocket->disconnect();
	socket.receive< 0 >();
	CHECK_EQUAL( socket.isConnected(), false );
	CHECK_EQUAL( remoteSocket->isConnected(), false );
}

TEST( disconnect3 )
{
	cold::Socket socket;
	CHECK_THROW( socket.disconnect(), std::runtime_error );
	CHECK_EQUAL( socket.isConnected(), false );
}

TEST( getRemoteIP2 )
{
	cold::Socket socket;
	CHECK_THROW( socket.getRemoteIP(), std::runtime_error );
}

TEST( getRemotePort2 )
{
	cold::Socket socket;
	CHECK_THROW( socket.getRemotePort(), std::runtime_error );
}

}
