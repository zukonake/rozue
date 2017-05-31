#pragma once

#include <geometry/vector2.hpp>
#include <geometry/vector3.hpp>
#include <geometry/rectangle.hpp>
#include <geometry/cuboid.hpp>
//
#include <world/map/typedef.hpp>
#include <world/entity/entityMap.hpp>

namespace coldline
{

class Tile;

class Map : public EntityMap
{
	public:
	virtual Tile &operator[]( map::Point3 const &point ) = 0;
	virtual Tile const &at( map::Point3 const &point ) const = 0;

	virtual map::Point3 getFreePosition() = 0;
	virtual map::Point3 getFreePosition( map::Coordinate const &z ) = 0;

	virtual bool exists( map::Point3 const &point ) = 0;

	bool sees( map::Point3 const &from, map::Point3 const &to );
	bool sees( map::Point3 const &from, map::Point3 const &to ) const;
	bool canMove( map::Point3 const &from, map::Point3 const &to ) const;

	virtual void simulate();
};

}
