#include <world/entity/entity.hpp>
#include "chunk.hpp"

namespace coldline
{

ChunkSize constexpr Chunk::size;

Chunk::Chunk() noexcept
{
	static_assert( size.x > 0, "Chunk size cannot be 0" );
	static_assert( size.y > 0, "Chunk size cannot be 0" );
	static_assert( size.z > 0, "Chunk size cannot be 0" );
}

Tile &Chunk::operator[]( ChunkInternalPoint const &point ) noexcept
{
	return mValue[ point ];
}

Tile const &Chunk::operator[]( ChunkInternalPoint const &point ) const noexcept
{
	return mValue[ point ];
}

ChunkPoint Chunk::toChunkPoint( WorldPoint3 const &point ) noexcept
{
	ChunkPoint output = point;
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

ChunkInternalPoint Chunk::toInternalPoint( WorldPoint3 const &point ) noexcept
{
	WorldPoint3 output = point;
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
