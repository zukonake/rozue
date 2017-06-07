#pragma once

#include <geometry/map3.hpp>
//
#include <world/typedef.hpp>
#include <world/chunk/typedef.hpp>
#include <world/tile/tile.hpp>

namespace coldline
{

class Chunk
{
	public:
	Tile &operator[]( chunk::InternalPoint const &point );
	Tile const &operator[]( chunk::InternalPoint const &point ) const;

	bool entityOn( chunk::InternalPoint const &point ) const;
	Entity &getEntityOn( chunk::InternalPoint const &point );

	static chunk::Point toChunkPoint( world::Point3 const &point );
	static chunk::InternalPoint toInternalPoint( world::Point3 const &point );
	static chunk::Size constexpr size = { 32, 32, 1 };
	private://TODO entity vector
	std::vector< Entity * > mEntities;
	geometry::Map3< Tile, size.x, size.y, size.z > mValue;
};

}
