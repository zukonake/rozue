#pragma once

#include <SFML/Graphics/Drawable.hpp>
//
#include <queue>
//
#include <world/typedef.hpp>
#include <render/typedef.hpp>

namespace coldline
{

class RenderTile;
class Sprite;
class Entity;
class World;

class Camera
{
	public:
	Camera( Camera const &that ) = delete;
	Camera(
		RenderTile const &nothing,
		World &world,
		Entity &entity,
		RenderSize screenSize,
		RenderSize spriteSize );
	Camera &operator=( Camera const &that ) = delete;

	bool move( WorldVector const &by );
	bool teleport( WorldPoint const &to );

	void lock();
	void unlock();
	void setScale( RenderScale const &scale );
	void changeScale( RenderScale const &scale );
	std::queue< Sprite > getRenderQueue();
	private:
	bool sees( WorldPoint const &what ) const;
	void updateFov();

	bool mLocked;
	RenderScale mScale;
	RenderSize mScreenSize;
	RenderSize mSpriteSize;
	RenderTile const &mNothing;
	World &mWorld;
	Entity *mEntity;
	WorldPoint mPosition;

	RenderSize mFov;
};

}
