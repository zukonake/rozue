#pragma once

#include <cstdint>
#include <string>
//
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/TcpListener.hpp>

namespace Network
{

typedef std::string ID;
typedef uint16_t Port;
typedef sf::IpAddress IP;
typedef sf::Packet Packet;
typedef sf::Socket Socket;
typedef sf::TcpSocket TCPSocket;
typedef sf::TcpListener TCPListener;

}
