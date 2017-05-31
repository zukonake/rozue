#pragma once

#include <SFML/Graphics/Drawable.hpp>
//
#include <queue>
//
#include <render/typedef.hpp>
#include <render/sprite.hpp>
#include <world/map/typedef.hpp>
#include <world/typedef.hpp>
#include <world/entity/entity.hpp>

namespace coldline
{

class Map;
class Renderable;
class TransformedSprite;

class Camera : public Entity
{
	public:
	Camera( Entity const &entity, World const &world, Sprite const &nothing );

	virtual bool move( map::Vector3 const &by ) override;
	virtual bool teleport( map::Point3 const &to ) override;

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
	world::Position mPosition;
	World const &mWorld;
	Sprite const &mNothing;

	unsigned short const mFov = 6;
};

}
