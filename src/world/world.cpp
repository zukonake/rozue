#include <world/map/map.hpp>
#include "world.hpp"

namespace coldline
{

Map &World::operator[]( world::Location const &location )
{
	return *std::map< world::Location, Map * >::operator[]( location );
}

Map const &World::operator[]( world::Location const &location ) const
{
	return *std::map< world::Location, Map * >::at( location );
}
Map const &World::at( world::Location const &location ) const
{
	return *std::map< world::Location, Map * >::at( location );
}

void World::simulate()
{
	for( auto &iMap : *this )
	{
		iMap.second->simulate();
	}
}

}
