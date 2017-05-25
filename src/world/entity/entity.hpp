#pragma once

#include <SFML/Graphics.hpp>
//
#include <geometry/point.hpp>
#include <geometry/vector.hpp>

class World;
class EntitySubtype;

class Entity : public virtual sf::Drawable
{
	public:
	Entity( World &world, Point const &position, EntitySubtype const &subtype );

	virtual void draw( sf::RenderTarget &target, sf::RenderStates states ) const override;

	virtual bool move( Vector const &by );
	virtual bool teleport( Vector const &to );

	Point const &getPosition() const noexcept;
	private:
	World &mWorld;
	Point mPosition;
	public:
	EntitySubtype const &subtype;
};
