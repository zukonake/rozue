#pragma once

#include <list>
#include <unordered_map>
//
#include <world/map/typedef.hpp>
#include <world/typedef.hpp>
#include <world/entity/entity.hpp>

namespace coldline
{

class EntitySubtype;
class World;

class EntityMap
{
	public:
	EntityMap( World &world );

	void simulate();
	void moveEntity( map::Point3 const &from, map::Point3 const &to );

	Entity &createEntity( world::Position const &position, EntitySubtype const &subtype );
	virtual Entity &createPlayer( EntitySubtype const &subtype ) = 0;

	bool entityOn( map::Point3 const &point ) const;
	bool canMove( map::Point3 const &to ) const;

	Entity const &getEntityOn( map::Point3 const &point ) const;
	private:
	std::list< Entity > mEntities;
	std::unordered_map< map::Point3, Entity * > mEntitiesMap;
	World &mWorld;
};

}
