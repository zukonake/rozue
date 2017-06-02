#include <world/tile/tile.hpp>
#include <world/map/chunk/chunk.hpp>
#include <world/generator/generator.hpp>
#include "map.hpp"
//TODO move tile dir to map dir?
namespace coldline
{

Map::Map( Generator &generator ) :
	mGenerator( generator )
{

}

Tile &Map::operator[]( map::Point3 const &point )
{
	if( exists( point ))
	{
		return loadChunk( toChunkPoint( point ))[ toInternalPoint( point )];
	}
	return mChunks[ point ][ toInternalPoint( point )];
}

bool Map::exists( map::Point3 const &point )
{
	return mChunks.count( point ) > 0;
}

Chunk &Map::loadChunk( chunk::Point const &point )
{
	mChunks[ point ] = mGenerator.generate( point );
}

chunk::Point Map::toChunkPoint( map::Point3 const &point )
{
	chunk::Point output = point;
	if( output.x < 0 )
	{
		output.x -= chunkSize.x - 1;
	}
	if( output.y < 0 )
	{
		output.y -= chunkSize.y - 1;
	}
	if( output.z < 0 )
	{
		output.z -= chunkSize.z - 1;
	}
	return output;
}

chunk::InternalPoint Map::toInternalPoint( map::Point3 const &point )
{
	map::Point3 output = point;
	output.x %= chunkSize.x;
	output.y %= chunkSize.y;
	output.z %= chunkSize.z;
	if( output.x < 0 )
	{
		output.x += chunkSize.x;
	}
	if( output.y < 0 )
	{
		output.y += chunkSize.y;
	}
	if( output.z < 0 )
	{
		output.z += chunkSize.z;
	}
	return output;
}

}
