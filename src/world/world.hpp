#pragma once

#include <unordered_map>
#include <list>
//
#include <geometry/point.hpp>
#include <world/map.hpp>
#include <world/entity/entity.hpp>

class Tile;
class Generator;

class World
{
	public:
	World( World const &that ) = default;
	World( Map const &map );

	Tile &operator[]( Point3 const &index );
	Tile const &operator[]( Point3 const &index ) const;

	Point3 getStartPosition() const;
	Point3 getFreePosition() const;
	Entity &getEntityOn( Point3 const &point );
	Entity const &getEntityOn( Point3 const &point ) const;
	bool sees( Point3 const &from, Point3 const &to ) const;
	bool entityOn( Point3 const &point ) const;

	void simulate();
	bool moveEntity( Point3 const &from, Point3 const &to );

	Entity &createEntity( EntitySubtype const &subtype, Point3 const &position );
	Entity &createPlayer( EntitySubtype const &subtype );

	static bool exists( Point3 const &where );
	private:
	Map mMap;
	std::list< Entity > mEntities;
	std::unordered_map< Point3, Entity * > mEntitiesMap;
};
