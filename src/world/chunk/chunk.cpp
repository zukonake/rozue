#include <world/entity/entity.hpp>
#include "chunk.hpp"

namespace coldline
{

chunk::Size constexpr Chunk::size;

Chunk::Chunk() noexcept
{
	static_assert( size.x > 0, "Chunk size cannot be 0" );
	static_assert( size.y > 0, "Chunk size cannot be 0" );
	static_assert( size.z > 0, "Chunk size cannot be 0" );
}

Tile &Chunk::operator[]( chunk::InternalPoint const &point ) noexcept
{
	return mValue[ point ];
}

Tile const &Chunk::operator[]( chunk::InternalPoint const &point ) const noexcept
{
	return mValue[ point ];
}

chunk::Point Chunk::toChunkPoint( world::Point3 const &point ) noexcept
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

chunk::InternalPoint Chunk::toInternalPoint( world::Point3 const &point ) noexcept
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
