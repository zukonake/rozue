#pragma once

#include <map>
//
#include <world/typedef.hpp>

namespace coldline
{

class Map;

class World : public std::map< world::Location, Map * >
{
	public:
	Map &operator[]( world::Location const &location );
	Map const &operator[]( world::Location const &location ) const;
	Map const &at( world::Location const &location ) const;

	void simulate();
};

}
