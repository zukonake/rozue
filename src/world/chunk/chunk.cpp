#include <world/tile/tile.hpp>
#include "chunk.hpp"

namespace coldline
{

Tile &Chunk::operator[]( chunk::InternalPoint const &point )
{
	return mValue[ point ];
}

Tile const &Chunk::operator[]( chunk::InternalPoint const &point ) const
{
	return mValue[ point ];
}

}
