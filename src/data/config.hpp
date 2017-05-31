#pragma once

#include <string>
//
#include <render/typedef.hpp>
#include <world/typedef.hpp>
#include <data/loadable.hpp>

namespace coldline
{

struct Config : public Loadable
{
	Config( world::Location const &startingLocation,
		screen::Size const &screenSize );
	world::Location startingLocation;
	screen::Size screenSize;
};

}
