#pragma once

namespace network
{

enum class ColdHeader
{
	DISCONNECT = 0x00,
	CONNECT = 0x10,
	ACKNOWLEDGE = 0x20,
	SEND = 0x30
};

}
