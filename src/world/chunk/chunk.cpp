#include <world/tile/tile.hpp>
#include <world/entity/entity.hpp>
#include "chunk.hpp"

namespace coldline
{

chunk::Size constexpr Chunk::size;

Tile &Chunk::operator[]( chunk::InternalPoint const &point )
{
	return mValue[ point ];
}

Tile const &Chunk::operator[]( chunk::InternalPoint const &point ) const
{
	return mValue[ point ];
}

bool Chunk::entityOn( chunk::InternalPoint const &point ) const
{
	for( auto &iEntity : mEntities )
	{
		if( iEntity->getPosition() == point )
		{
			return true;
		}
	}
	return false;
}

Entity &Chunk::getEntityOn( chunk::InternalPoint const &point )
{
	(void)point; //TODO
	return *mEntities[ 0 ];
}

chunk::Point Chunk::toChunkPoint( world::Point3 const &point )
{
	chunk::Point output = point;
	if( output.x < 0 )
	{
		output.x -= size.x - 1;
	}
	if( output.y < 0 )
	{
		output.y -= size.y - 1;
	}
	if( output.z < 0 )
	{
		output.z -= size.z - 1;
	}
	return output / size;
}

chunk::InternalPoint Chunk::toInternalPoint( world::Point3 const &point )
{
	world::Point3 output = point;
	output.x %= size.x;
	output.y %= size.y;
	output.z %= size.z;
	if( output.x < 0 )
	{
		output.x += size.x;
	}
	if( output.y < 0 )
	{
		output.y += size.y;
	}
	if( output.z < 0 )
	{
		output.z += size.z;
	}
	return output;
}

}
