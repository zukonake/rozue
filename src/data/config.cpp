#include "config.hpp"

namespace coldline
{

Config::Config( world::Location const &startingLocation,
	screen::Size const &screenSize ) :
	startingLocation( startingLocation ),
	screenSize( screenSize )
{

}

}
