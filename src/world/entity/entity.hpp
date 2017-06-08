#pragma once

#include <world/typedef.hpp>

namespace coldline
{

namespace render
{

class Tile;

}

class EntitySubtype;
class World;

class Entity
{
	public:
	Entity( World &mWorld, world::Point3 const &position, EntitySubtype const &subtype ) noexcept;

	bool move( world::Vector3 const &by );
	bool teleport( world::Point3 const &to );

	render::Tile const &getRenderTile() const noexcept;
	world::Point3 const &getPosition() const noexcept;

	bool passable() const noexcept;
	private:
	bool canMove( world::Point3 const &to );

	World &mWorld;
	EntitySubtype const &mSubtype;
	world::Point3 mPosition;
};

}
