#include "config.hpp"

namespace coldline
{

Config::Config( render::Size const &screenSize, render::Size const &spriteSize ) noexcept :
	screenSize( screenSize ),
	spriteSize( spriteSize )
{

}

}
