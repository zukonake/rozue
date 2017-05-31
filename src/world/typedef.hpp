#pragma once

#include <string>
//
#include <world/map/typedef.hpp>

namespace coldline
{

namespace world
{

typedef std::string Location;

struct Position
{
	map::Point3 point;
	map::Coordinate &x = point.x;
	map::Coordinate &y = point.y;
	map::Coordinate &z = point.z;
	Location location;
};

}

}
