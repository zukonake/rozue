#include <world/tile/tile.hpp>
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

}
