#pragma once

#include <list>
#include <unordered_map>
//
#include <world/map/typedef.hpp>
#include <world/map/map.hpp>

namespace coldline
{

class Entity;
class EntitySubtype;
class Generator;

class World
{
	public:
	World( Generator * const &generator );

	~World();

	Tile &operator[]( map::Point3 const &point );

	map::Point3 getFreePoint();
	map::Point3 getFreePoint( map::Coordinate const &z );

	bool sees( map::Point3 const &from, map::Point3 const &to );
	bool canMove( map::Point3 const &from, map::Point3 const &to );
	bool entityOn( map::Point3 const &point ) const;

	Entity const &getEntityOn( map::Point3 const &point ) const;
	Entity &createEntity( map::Point3 const &position, EntitySubtype const &subtype );
	Entity &createPlayer( EntitySubtype const &subtype );

	void moveEntity( map::Point3 const &from, map::Point3 const &to );
	void simulate();
	private:
	bool exists( map::Point3 const &point );
	Generator *mGenerator;

	std::list< Entity > mEntities;
	std::unordered_map< map::Point3, Entity * > mEntitiesMap; //TODO ref wrapper?

	Map mMap;
};

}
