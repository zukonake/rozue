#pragma once

#include <geometry/map3.hpp>
#include <world/map/chunk/typedef.hpp>
#include <world/map/tile/tile.hpp>

namespace coldline::world::map
{

template< chunk::Length width, chunk::Length height, chunk::Length depth  >
class Chunk
{
	typedef ::coldline::geometryMap3< Tile, width, height, depth > ChunkValue;
	public:
	constexpr chunk::Size getSize() const noexcept;
	private:
	ChunkValue
};

}
