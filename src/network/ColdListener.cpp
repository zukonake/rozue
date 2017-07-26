#include <network/ColdHeader.hpp>
#include <network/ColdPacket.hpp>
#include <network/ColdSocket.hpp>
#include "ColdListener.hpp"

namespace network
{

void ColdListener::listen( Port const &port )
{
	UDPSocket::bind( port );
}

std::unique_ptr< ColdSocket > ColdListener::accept()
{
	IP acceptedIP = "";
	Port acceptedPort = getPort();
	auto result = UDPSocket::receive< 0x1 >( acceptedIP, acceptedPort );
	if( static_cast< ColdHeader >( result.at( 0 )) != ColdHeader::CONNECT )
	{
		throw std::runtime_error( "network::ColdListener::accept: failed to accept" );
	}
	UDPSocket::send< 0x1 >( ColdPacket<>( ColdHeader::ACKNOWLEDGE ), acceptedIP, acceptedPort );
	return std::make_unique< ColdSocket >( acceptedIP, acceptedPort );
}

Port ColdListener::getPort()
{
	return UDPSocket::getPort();
}

}
