#pragma once

#include <list>
#include <unordered_map>
//
#include <world/typedef.hpp>
#include <world/chunk/typedef.hpp>
#include <world/chunk/chunk.hpp>

namespace coldline
{

class Tile;
class Entity;
class EntitySubtype;
class Generator;

class World
{
	public:
	World( Generator * const &generator );
	World( World const &that ) = delete;

	~World();

	Tile &operator[]( WorldPoint const &point );
	World &operator=( World const &that ) = delete;

	bool sees( WorldPoint const &from, WorldPoint const &to );
	bool canMove( WorldPoint const &from, WorldPoint const &to );
	bool entityOn( WorldPoint const &point );

	Entity &getEntityOn( WorldPoint const &point );
	Entity &createEntity( WorldPoint const &position, EntitySubtype const &subtype );
	Entity &createPlayer( EntitySubtype const &subtype );

	void moveEntity( WorldPoint const &from, WorldPoint const &to );
	void simulate();
	private://TODO add isPathClear and Path typedef
	bool exists( WorldPoint const &point );
	Chunk &loadChunk( ChunkPoint const &point );
	Chunk &getChunk( ChunkPoint const &point );

	static ChunkPoint toChunkPoint( WorldPoint const &point );
	static ChunkInternalPoint toInternalPoint( WorldPoint const &point );
	Generator *mGenerator;

	std::list< Entity > mEntities;
	std::unordered_map< ChunkPoint, Chunk > mChunks;
};

}
