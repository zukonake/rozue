#pragma once

#include <geometry/map3.hpp>
//
#include <world/chunk/typedef.hpp>
#include <world/tile/tile.hpp>

namespace coldline
{

class Chunk
{
	public:
	Tile &operator[]( chunk::InternalPoint const &point );
	Tile const &operator[]( chunk::InternalPoint const &point ) const;

	static chunk::Size constexpr size = { 32, 32, 1 };
	private://TODO entity vector
	geometry::Map3< Tile, size.x, size.y, size.z > mValue;
};

chunk::Size constexpr Chunk::size;

}
