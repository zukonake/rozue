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

	Tile &operator[]( WorldPoint3 const &point );
	World &operator=( World const &that ) = delete;

	bool sees( WorldPoint3 const &from, WorldPoint3 const &to );
	bool canMove( WorldPoint3 const &from, WorldPoint3 const &to );
	bool entityOn( WorldPoint3 const &point );

	Entity &getEntityOn( WorldPoint3 const &point );
	Entity &createEntity( WorldPoint3 const &position, EntitySubtype const &subtype );
	Entity &createPlayer( EntitySubtype const &subtype );

	void moveEntity( WorldPoint3 const &from, WorldPoint3 const &to );
	void simulate();
	private://TODO add isPathClear and Path typedef
	bool exists( WorldPoint3 const &point );
	Chunk &loadChunk( ChunkPoint const &point );
	Chunk &getChunk( ChunkPoint const &point );

	static ChunkPoint toChunkPoint( WorldPoint3 const &point );
	static ChunkInternalPoint toInternalPoint( WorldPoint3 const &point );
	Generator *mGenerator;

	std::list< Entity > mEntities;
	std::unordered_map< ChunkPoint, Chunk > mChunks;
};

}
