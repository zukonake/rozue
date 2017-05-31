#include <world/map/map.hpp>
#include "world.hpp"

namespace coldline
{

World::World( world::Location const &startingLocation ) :
	mStartingLocation( startingLocation )
{

}

Map &World::operator[]( world::Location const &location )
{
	return *std::map< world::Location, Map * >::operator[]( location );
}

Map const &World::operator[]( world::Location const &location ) const
{
	return *std::map< world::Location, Map * >::at( location );
}

Entity &World::createPlayer( EntitySubtype const &subtype )
{
	return operator[]( mStartingLocation ).createPlayer( subtype );
}

void World::simulate()
{
	for( auto &iMap : *this )
	{
		iMap.second->simulate();
	}
}

}
