#pragma once

#include <cstddef>
#include <vector>
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
	World( Map const &map, std::vector< Entity > const &entities = std::vector< Entity >());

	Tile &operator[]( Point3 const &index );
	Tile const &operator[]( Point3 const &index ) const;

	Point3 getStartPosition() const;
	Point3 getFreePosition() const;
	Entity &getPlayer();
	bool sees( Point3 const &from, Point3 const &to ) const;

	void simulate();
	void createEntity( EntitySubtype const &subtype );
	void createPlayer( EntitySubtype const &subtype );

	static bool exists( Point3 const &where );
	private:
	Map mMap;
	std::vector< Entity > mEntities;
};
