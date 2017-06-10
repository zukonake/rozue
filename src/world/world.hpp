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

	Tile &operator[]( world::Point3 const &point );
	World &operator=( World const &that ) = delete;

	bool sees( world::Point3 const &from, world::Point3 const &to );
	bool canMove( world::Point3 const &from, world::Point3 const &to );
	bool entityOn( world::Point3 const &point );

	Entity &getEntityOn( world::Point3 const &point );
	Entity &createEntity( world::Point3 const &position, EntitySubtype const &subtype );
	Entity &createPlayer( EntitySubtype const &subtype );

	void moveEntity( world::Point3 const &from, world::Point3 const &to );
	void simulate();
	private://TODO add isPathClear and Path typedef
	bool exists( world::Point3 const &point );
	Chunk &loadChunk( chunk::Point const &point );
	Chunk &getChunk( chunk::Point const &point );

	static chunk::Point toChunkPoint( world::Point3 const &point );
	static chunk::InternalPoint toInternalPoint( world::Point3 const &point );
	Generator *mGenerator;

	std::list< Entity > mEntities;
	std::unordered_map< chunk::Point, Chunk > mChunks;
};

}
