#pragma once

namespace network
{

namespace cold
{

enum class Header
{
	DISCONNECT = 0x0,
	CONNECT = 0x1,
	ACKNOWLEDGE = 0x2,
	SEND = 0x3
};

}

}
