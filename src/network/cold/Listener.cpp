#include <network/cold/Header.hpp>
#include <network/cold/Packet.hpp>
#include <network/cold/Socket.hpp>
#include "Listener.hpp"

namespace network
{

namespace cold
{

void Listener::listen( Port const &port )
{
	udp::Socket::bind( port );
}

std::unique_ptr< Socket > Listener::accept()
{
	IP acceptedIP = "";
	Port acceptedPort = getPort();
	auto result = udp::Socket::receive< 0x1 >( acceptedIP, acceptedPort );
	if( static_cast< Header >( result.at( 0 )) != Header::CONNECT )
	{
		throw std::runtime_error( "network::ColdListener::accept: failed to accept" );
	}
	udp::Socket::send< 0x1 >( Packet<>( Header::ACKNOWLEDGE ), acceptedIP, acceptedPort );
	return std::make_unique< cold::Socket >( acceptedIP, acceptedPort );
}

Port Listener::getPort()
{
	return udp::Socket::getPort();
}

}

}
