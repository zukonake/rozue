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
	Entity( World &mWorld, WorldPoint const &position, EntitySubtype const &subtype ) noexcept;

	bool move( WorldVector const &by );
	bool teleport( WorldPoint const &to );

	RenderTile const &getRenderTile() const noexcept;
	WorldPoint const &getPosition() const noexcept;

	bool passable() const noexcept;
	private:
	bool canMove( WorldPoint const &to );

	World &mWorld;
	EntitySubtype const &mSubtype;
	WorldPoint mPosition;
};

}
