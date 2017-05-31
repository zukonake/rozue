#pragma once

#include <map>
//
#include <world/typedef.hpp>

namespace coldline
{

class Map;
class Entity;
class EntitySubtype;

class World : public std::map< world::Location, Map * >
{
	public:
	World() = delete;
	World( world::Location const &startingLocation );

	Map &operator[]( world::Location const &location );
	Map const &operator[]( world::Location const &location ) const;

	Entity &createPlayer( EntitySubtype const &subtype );
	void simulate();
	private:
	world::Location mStartingLocation;
};

}
