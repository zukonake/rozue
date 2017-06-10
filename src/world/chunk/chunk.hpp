#pragma once

#include <geometry/map3.hpp>
//
#include <world/typedef.hpp>
#include <world/chunk/typedef.hpp>
#include <world/tile/tile.hpp>

namespace coldline
{

class Entity;
class Tile;

class Chunk
{
	friend class World;
	public:
	Chunk() noexcept;

	Tile &operator[]( chunk::InternalPoint const &point ) noexcept;
	Tile const &operator[]( chunk::InternalPoint const &point ) const noexcept;

	static chunk::Point toChunkPoint( world::Point3 const &point ) noexcept;
	static chunk::InternalPoint toInternalPoint( world::Point3 const &point ) noexcept;
	static chunk::Size constexpr size = { 32, 32, 1 };
	private:
	std::vector< Entity * > mEntities;
	world::Space< size.x, size.y, size.z > mValue;
};

}
