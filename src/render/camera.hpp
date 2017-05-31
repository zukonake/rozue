#pragma once

#include <SFML/Graphics/Drawable.hpp>
//
#include <queue>
#include <functional>
//
#include <render/typedef.hpp>
#include <render/sprite.hpp>
#include <world/map/typedef.hpp>
#include <world/typedef.hpp>

namespace coldline
{

class Map;
class Renderable;
class TransformedSprite;
class Entity;

class Camera
{
	public:
	Camera( Sprite const &nothing, World &world, Entity &entity );

	bool move( map::Vector3 const &by );
	bool teleport( map::Point3 const &to );

	void lock();
	void unlock();
	void setScale( screen::Scale const &scale );
	void changeScale( screen::Scale const &scale );
	std::queue< TransformedDrawable > getRenderQueue() const;
	private:
	static void addDrawable( std::queue< TransformedDrawable > &renderQueue,
		sf::Drawable const &drawable,
		screen::Point const &point,
		screen::Scale const &scale );
	bool sees( map::Point3 const &what ) const;

	bool mLocked;
	screen::Scale mScale;
	Sprite const &mNothing;
	World &mWorld;
	std::reference_wrapper< Entity > mEntity;
	world::Position mPosition;

	unsigned short const mFov = 6;
};

}
