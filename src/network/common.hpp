#pragma once

extern "C"
{

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

}

#include <cstdint>
#include <array>
#include <string>

namespace network
{

typedef uint8_t Byte;
typedef uint16_t Port;
typedef uint16_t DatagramSize;
typedef int SocketHandle;
typedef sockaddr_in InternetAddress;
typedef sockaddr SocketAddress;
typedef std::string IP; //TODO more restraining version?
template< DatagramSize size >
using Data = std::array< Byte, size >;

}
