#include <stdexcept>
#include <string>
//
#include <utility/logger.hpp>
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
		return loadChunk( Chunk::toChunkPoint( point ))[ Chunk::toInternalPoint( point )];
	}
	return mChunks[ Chunk::toChunkPoint( point )][ Chunk::toInternalPoint( point )];
}



bool World::sees( world::Point3 const &from, world::Point3 const &to )
{
	auto plot = world::Line3( from, to ).getPlot();
	if( plot.empty())
	{
		return false;
	}
	for( unsigned i = 1; i < plot.size() - 1; i++ )
	{
		if( !operator[]( plot[ i ]).passable())
		{
			return false;
		}
		if( entityOn( plot[ i ]))
		{
			if( !getEntityOn( plot[ i ]).passable())
			{
				return false;
			}
		}
	}
	return true;
}

bool World::canMove( world::Point3 const &from, world::Point3 const &to )
{
	auto plot = world::Line3( from, to ).getPlot();
	if( plot.empty())
	{
		return false;
	}
	for( auto &iPoint : plot )
	{
		if( !operator[]( iPoint ).passable())
		{
			return false;
		}
		if( entityOn( iPoint ))
		{
			if( !getEntityOn( iPoint ).passable())
			{
				return false;
			}
		}
	}
	return true;
}

bool World::entityOn( world::Point3 const &point )
{
	Chunk const &chunk = getChunk( Chunk::toChunkPoint( point ));
	for( auto &iEntity : chunk.mEntities )
	{
		if( iEntity->getPosition() == point )
		{
			return true;
		}
	}
	return false;
}



Entity &World::getEntityOn( world::Point3 const &point )
{
	Chunk const &chunk = getChunk( Chunk::toChunkPoint( point ));
	for( auto &iEntity : chunk.mEntities )
	{
		if( iEntity->getPosition() == point )
		{
			return *iEntity;
		}
	}
	throw std::out_of_range( "World::getEntityOn: no such entity" );
}

Entity &World::createEntity( world::Point3 const &position, EntitySubtype const &subtype )
{
	if( !entityOn( position ))
	{
		mEntities.emplace_back( *this, position, subtype );
		Chunk &chunk = getChunk( Chunk::toChunkPoint( position ));
		chunk.mEntities.push_back( &mEntities.back());
	}
	return mEntities.back();
}

Entity &World::createPlayer( EntitySubtype const &subtype )
{
	return createEntity( { 0, 0, 0 }, subtype ); //TODO 0, 0, 0 ?
}



void World::moveEntity( world::Point3 const &from, world::Point3 const &to )
{
	if( Chunk::toChunkPoint( from ) != Chunk::toChunkPoint( to ))
	{
		Chunk &fromChunk = getChunk( Chunk::toChunkPoint( from ));
		Chunk &toChunk = getChunk( Chunk::toChunkPoint( to ));
		for( unsigned i = 0; i < fromChunk.mEntities.size(); i++ )
		{
			if( fromChunk.mEntities[ i ]->getPosition() == from )
			{
				toChunk.mEntities.push_back( fromChunk.mEntities[ i ]);
				fromChunk.mEntities.erase( fromChunk.mEntities.begin() + i );
				return;
			}
		}
	}
}

void World::simulate()
{

}



bool World::exists( world::Point3 const &point )
{
	return mChunks.count( Chunk::toChunkPoint( point )) > 0;
}

Chunk &World::loadChunk( chunk::Point const &point )
{
	globalLogger.log( Logger::DEBUG,
		"Loaded chunk: " +
		std::to_string( point.x ) + ", " +
		std::to_string( point.y ) + ", " +
		std::to_string( point.z ));
	mChunks[ point ] = mGenerator->generate( point );
	return mChunks[ point ];
}

Chunk &World::getChunk( chunk::Point const &point )
{
	if( exists( point ))
	{
		return mChunks.at( point );
	}
	else
	{
		return loadChunk( point );
	}
}

}
