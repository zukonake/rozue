#pragma once

#include <world/typedef.hpp>

namespace coldline
{

class RenderTile;
class EntitySubtype;
class World;

class Entity
{
	public:
	Entity( World &mWorld, WorldPoint3 const &position, EntitySubtype const &subtype ) noexcept;

	bool move( WorldVector3 const &by );
	bool teleport( WorldPoint3 const &to );

	RenderTile const &getRenderTile() const noexcept;
	WorldPoint3 const &getPosition() const noexcept;

	bool passable() const noexcept;
	private:
	bool canMove( WorldPoint3 const &to );

	World &mWorld;
	EntitySubtype const &mSubtype;
	WorldPoint3 mPosition;
};

}
