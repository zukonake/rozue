#pragma once

#include <geometry/point.hpp>
#include <geometry/vector.hpp>
#include <render/renderable.hpp>

class World;
class EntitySubtype;

class Entity : public Renderable
{
	public:
	Entity( World &world, Point3 const &position, EntitySubtype const &subtype );

	virtual Sprite const &getSprite() const override;

	virtual bool move( Vector const &by );
	virtual bool teleport( Vector const &to );

	Point3 const &getPosition() const noexcept;
	private:
	World &mWorld;
	EntitySubtype const &mSubtype;
	Point3 mPosition;
};
