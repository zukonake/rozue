#include <world/typedef.hpp>
#include <world/chunk/chunk.hpp>
#include <world/entity/entitySubtype.hpp>
#include <world/entity/entity.hpp>
#include <world/generator/generator.hpp>
#include "world.hpp"

namespace coldline
{

World::World( Generator * const &generator ) :
	mGenerator( generator )
{

}



World::~World()
{
	delete mGenerator;
}



Tile &World::operator[]( world::Point3 const &point )
{
	if( !exists( point ))
	{
		return loadChunk( toChunkPoint( point ))[ toInternalPoint( point )];
	}
	return mChunks[ point ][ toInternalPoint( point )];
}



bool World::sees( world::Point3 const &from, world::Point3 const &to )
{
	if( !exists( to ) || !exists( from ))
	{
		return false;
	}
	auto plot = world::Line3( from, to ).getPlot();
	if( plot.empty())
	{
		return false;
	}
	for( unsigned i = 1; i < plot.size() - 1; i++ )
	{
		if( operator[]( plot[ i ]).passable())
		{
			return false;
		}
		if( entityOn( plot[ i ]))
		{
			if( getEntityOn( plot[ i ]).passable())
			{
				return false;
			}
		}
	}
	return true;
}

bool World::canMove( world::Point3 const &from, world::Point3 const &to )
{
	return sees( from, to ) && operator[]( to ).passable() && !entityOn( to );
}

bool World::entityOn( world::Point3 const &point ) const
{
	return mEntitiesMap.count( point );
}



Entity const &World::getEntityOn( world::Point3 const &point ) const
{
	return *mEntitiesMap.at( point );
}

Entity &World::createEntity( world::Point3 const &position, EntitySubtype const &subtype )
{
	if( !entityOn( position ))
	{
		mEntities.emplace_back( *this, position, subtype );
		mEntitiesMap.emplace( position, &mEntities.back());
	}
	return *mEntitiesMap.at( position );
}

Entity &World::createPlayer( EntitySubtype const &subtype )
{
	return createEntity( { 0, 0, 0 }, subtype ); //TODO
}



void World::moveEntity( world::Point3 const &from, world::Point3 const &to )
{
	mEntitiesMap[ to ] = mEntitiesMap[ from ];
	mEntitiesMap.erase( from );
}

void World::simulate()
{

}



bool World::exists( world::Point3 const &point )
{
	return mChunks.count( point ) > 0;
}

Chunk &World::loadChunk( chunk::Point const &point )
{
	mChunks[ point ] = mGenerator->generate( point );
	return mChunks[ point ];
}



chunk::Point World::toChunkPoint( world::Point3 const &point )
{
	chunk::Point output = point;
	if( output.x < 0 )
	{
		output.x -= Chunk::size.x - 1;
	}
	if( output.y < 0 )
	{
		output.y -= Chunk::size.y - 1;
	}
	if( output.z < 0 )
	{
		output.z -= Chunk::size.z - 1;
	}
	return output;
}

chunk::InternalPoint World::toInternalPoint( world::Point3 const &point )
{
	world::Point3 output = point;
	output.x %= Chunk::size.x;
	output.y %= Chunk::size.y;
	output.z %= Chunk::size.z;
	if( output.x < 0 )
	{
		output.x += Chunk::size.x;
	}
	if( output.y < 0 )
	{
		output.y += Chunk::size.y;
	}
	if( output.z < 0 )
	{
		output.z += Chunk::size.z;
	}
	return output;
}

}
