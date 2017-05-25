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

	Tile &operator[]( Point const &index );
	Tile const &operator[]( Point const &index ) const;

	Point getStartPosition() const;
	Point getFreePosition() const;
	Entity &getPlayer();

	void simulate();
	void createEntity( EntitySubtype const &subtype );
	void createPlayer( EntitySubtype const &subtype );

	static bool exists( Point const &where );
	private:
	Map mMap;
	std::vector< Entity > mEntities;
};
