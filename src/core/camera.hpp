#pragma once

#include <cstdint>
//
#include <SFML/Graphics.hpp>
#include <coldline-geometry/vector3.hpp>
//
#include <geometry/point.hpp>
#include <geometry/vector.hpp>
#include <world/entity/entity.hpp>

class World;

class Camera : public virtual sf::Drawable, public Entity
{
	public:
	Camera( World &world );

	virtual void draw( sf::RenderTarget &target, sf::RenderStates states ) const override;

	virtual bool move( Vector const &by ) override;
	virtual bool teleport( Vector const &to ) override;

	void lock();
	void unlock();
	void setScale( float const &scale );
	void changeScale( float const &scale );
	private:
	bool sees( Point const &what ) const;

	World const &mWorld;
	Point mPosition;
	bool mLocked;
	float mScale;
	std::uint16_t const mFov = 6;
};
