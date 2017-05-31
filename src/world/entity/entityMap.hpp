#pragma once

#include <list>
#include <unordered_map>
//
#include <world/map/typedef.hpp>
#include <world/entity/entity.hpp>

namespace coldline
{

class EntitySubtype;

class EntityMap
{
	public:
	void simulate();
	void moveEntity( map::Point3 const &from, map::Point3 const &to );

	Entity &createEntity( EntitySubtype const &subtype, map::Point3 const &position );
	Entity &createPlayer( EntitySubtype const &subtype );

	bool entityOn( map::Point3 const &point ) const;
	bool canMove( map::Point3 const &from, map::Point3 const &to ) const;

	Entity &getEntityOn( map::Point3 const &point );
	Entity const &getEntityOn( map::Point3 const &point ) const;
	private:
	std::list< Entity > mEntities;
	std::unordered_map< map::Point3, Entity * > mEntitiesMap;
};

}
