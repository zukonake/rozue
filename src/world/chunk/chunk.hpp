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

	Tile &operator[]( ChunkInternalPoint const &point ) noexcept;
	Tile const &operator[]( ChunkInternalPoint const &point ) const noexcept;

	static ChunkPoint toChunkPoint( WorldPoint const &point ) noexcept;
	static ChunkInternalPoint toInternalPoint( WorldPoint const &point ) noexcept;
	static ChunkSize constexpr size = { 24, 24, 1 };
	private:
	std::vector< Entity * > mEntities;
	WorldSpace< size.x, size.y, size.z > mValue;
};

}
