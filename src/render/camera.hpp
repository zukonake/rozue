#pragma once

#include <cstdint>
#include <queue>
//
#include <SFML/Graphics.hpp>
//
#include <geometry/point.hpp>
#include <geometry/vector.hpp>
#include <geometry/scale.hpp>
#include <world/entity/entity.hpp>

class World;
class Renderable;
class TransformedSprite;

class Camera : public Entity
{
	public:
	Camera( World &world, Sprite const &nothing );

	virtual bool move( Vector const &by ) override;
	virtual bool teleport( Vector const &to ) override;

	void lock();
	void unlock();
	void setScale( Scale2 const &scale );
	void changeScale( Scale2 const &scale );
	std::queue< TransformedSprite > getSprites() const;
	private:
	static void addSprite( std::queue< TransformedSprite > &sprites,
		Renderable const &sprite,
		Point2 const &position,
		Scale2 const &scale );
	bool sees( Point3 const &what ) const;

	World const &mWorld;
	Sprite const &mNothing;
	Point3 mPosition;
	bool mLocked;
	Scale2 mScale;
	std::uint16_t const mFov = 6;
};
