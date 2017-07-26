#pragma once

extern "C"
{

#include <strings.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

}

#include <utility/NonCopyable.hpp>
//
#include <network/common.hpp>

namespace network
{

class UDPSocket : virtual utility::NonCopyable
{
public:
	DatagramSize static const maxDatagramSize = -1;
	UDPSocket();
	~UDPSocket();

	void bind( Port const &port );

	template< DatagramSize size >
	void send( Data< size > const &datagram, IP const &address, Port const &port );
	template< DatagramSize size >
	Data< size > receive( IP const &address, Port const &port );
	template< DatagramSize size >
	Data< size > receive( IP &address, Port &port );

	Port getPort(); //TODO throw if port not bound
private:
	Port mPort;
	SocketHandle mSocketHandle;
	InternetAddress mAddress;
};

template< DatagramSize size >
void UDPSocket::send( Data< size > const &datagram, IP const &address, Port const &port )
{
	InternetAddress to;
	to.sin_family = AF_INET;
	auto hostAddress = gethostbyname( address.c_str());
	bcopy(
		reinterpret_cast< char * >( hostAddress->h_addr ),
		reinterpret_cast< char * >( &to.sin_addr ),
		hostAddress->h_length
		);
	to.sin_port = htons( port );

	SocketAddress const *socketAddress = reinterpret_cast< SocketAddress const * >( &to );
	if( sendto( mSocketHandle, datagram.data(), size, 0, socketAddress , sizeof( InternetAddress )) < 0 )
	{
		throw std::runtime_error( "network::UDPSocket::receive: failed to receive" );
	}
}

template< DatagramSize size >
Data< size > UDPSocket::receive( IP const &address, Port const &port )
{
	IP tempAddress = address;
	Port tempPort = port;
	return receive< size >( tempAddress, tempPort );
}

template< DatagramSize size >
Data< size > UDPSocket::receive( IP &address, Port &port )
{
	Data< size > datagram;

	InternetAddress from;
	from.sin_family = AF_INET;
	auto hostAddress = gethostbyname( address.c_str());
	bcopy(
		reinterpret_cast< char * >( hostAddress->h_addr ),
		reinterpret_cast< char * >( &from.sin_addr ),
		hostAddress->h_length
		);
	from.sin_port = htons( port );
	SocketAddress *socketAddress = nullptr;
	unsigned addressSize = 0;
	if( address != "" ) //empty means we receive from all addresses
	{
		socketAddress = reinterpret_cast< SocketAddress * >( &from );
		addressSize = sizeof( InternetAddress );
	}

	if( recvfrom( mSocketHandle, datagram.data(), size, 0, socketAddress, &addressSize ) < 0 )
	{
		throw std::runtime_error( "network::UDPSocket::receive: failed to receive" );
	}
	port = ntohs( from.sin_port );
	char const *addr;
	inet_aton( addr, &from.sin_addr );
	address = addr;
	return datagram;
}

}
