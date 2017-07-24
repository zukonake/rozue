#include <future>
#include <mutex>
//
#include <UnitTest++/UnitTest++.h>
//
#include <network/exception.hpp>
#include <network/ColdSocket.hpp>
#include <network/ColdListener.hpp>

using namespace network;

SUITE( Client )
{

TEST( connectTo1_disconnect1_isConnected1_getRemoteIP1_getRemotePort1 )
{
	ColdListener listener;
	ColdSocket socket;
	std::promise< std::unique_ptr< ColdSocket > > promise;
	auto future = promise.get_future();

	CHECK_EQUAL( socket.isConnected(), false );
	listener.listen( 31337 );
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
	ColdSocket socket;
	CHECK_THROW( socket.connectTo( "invalid", 31337 ), exception::CouldNotConnect );
	CHECK_EQUAL( socket.isConnected(), false );
}

TEST( disconnect2 )
{
	ColdListener listener;
	ColdSocket socket;
	std::promise< std::unique_ptr< ColdSocket > > promise;
	auto future = promise.get_future();

	listener.listen( 31337 );
	std::thread listenerThread(
		[ &listener ]( std::promise< std::unique_ptr< ColdSocket > > && promise )
		{
			promise.set_value( listener.accept());
		},
		std::move( promise ));
	socket.connectTo( "localhost", 31337 );
	listenerThread.join();
	auto remoteSocket = future.get();
	remoteSocket->disconnect();
	CHECK_EQUAL( socket.isConnected(), false );
	CHECK_EQUAL( remoteSocket->isConnected(), false );
}

TEST( disconnect3 )
{
	ColdSocket socket;
	CHECK_THROW( socket.disconnect(), exception::InvalidState );
	CHECK_EQUAL( socket.isConnected(), false );
}

TEST( getRemoteIP2 )
{
	ColdSocket socket;
	CHECK_THROW( socket.getRemoteIP(), exception::InvalidState );
}

TEST( getRemotePort2 )
{
	ColdSocket socket;
	CHECK_THROW( socket.getRemotePort(), exception::InvalidState );
}

}
