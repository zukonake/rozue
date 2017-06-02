#pragma once

#include <SFML/Graphics/Drawable.hpp>
//
#include <world/map/typedef.hpp>

namespace coldline
{

class World;
class EntitySubtype;

class Entity : public sf::Drawable
{
	public:
	Entity( World &mWorld, map::Point3 const &position, EntitySubtype const &subtype );

	virtual void draw( sf::RenderTarget &target, sf::RenderStates states ) const override;

	virtual bool move( map::Vector3 const &by );
	virtual bool teleport( map::Point3 const &to );

	map::Point3 const &getPosition() const noexcept;

	bool passable() const noexcept;
	private:
	bool canMove( map::Point3 const &to );

	World &mWorld;
	EntitySubtype const &mSubtype;
	map::Point3 mPosition;
};

}
