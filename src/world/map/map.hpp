#pragma once

#include <unordered_map>
//
#include <world/map/typedef.hpp>
#include <world/map/chunk/typedef.hpp>
#include <world/map/chunk/chunk.hpp>

namespace coldline
{

class Tile;
class Generator;

class Map
{
	public:
	Map( Generator &generator );

	Tile &operator[]( map::Point3 const &point );

	bool exists( map::Point3 const &point );
	private:
	Chunk &loadChunk( chunk::Point const &point );

	static chunk::Point toChunkPoint( map::Point3 const &point );
	static chunk::InternalPoint toInternalPoint( map::Point3 const &point );

	Generator &mGenerator;

	std::unordered_map< chunk::Point, Chunk > mChunks;
};

}
