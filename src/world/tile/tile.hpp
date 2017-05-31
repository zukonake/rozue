#pragma once

#include <SFML/Graphics/Drawable.hpp>

namespace coldline
{

class TileSubtype;

class Tile : public sf::Drawable
{
	public:
	Tile();
	Tile( Tile const &that );
	Tile( TileSubtype const &subtype );

	Tile &operator=( Tile const &that );
	Tile &operator=( TileSubtype const &that );

	virtual void draw( sf::RenderTarget &target, sf::RenderStates states ) const override;

	bool passable() const;
	private:
	TileSubtype const *mSubtype;
};

}
