#pragma once

#include <SFML/Graphics/Drawable.hpp>
//
#include <queue>
//
#include <world/typedef.hpp>

namespace coldline
{

namespace render
{

class Tile;

}

class Sprite;
class Entity;
class World;

class Camera
{
	public:
	Camera( Camera const &that ) = delete;
	Camera(
		render::Tile const &nothing,
		World &world,
		Entity &entity,
		render::Size screenSize,
		render::Size spriteSize );
	Camera &operator=( Camera const &that ) = delete;

	bool move( world::Vector3 const &by );
	bool teleport( world::Point3 const &to );

	void lock();
	void unlock();
	void setScale( render::Scale const &scale );
	void changeScale( render::Scale const &scale );
	std::queue< Sprite > getRenderQueue();
	private:
	bool sees( world::Point3 const &what ) const;

	bool mLocked;
	render::Scale mScale;
	render::Size mScreenSize;
	render::Size mSpriteSize;
	render::Tile const &mNothing;
	World &mWorld;
	Entity *mEntity;
	world::Point3 mPosition;

	unsigned short const mFov = 6;
};

}
