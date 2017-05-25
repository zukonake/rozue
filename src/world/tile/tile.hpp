#pragma once

#include <SFML/Graphics.hpp>

class TileSubtype;

class Tile : public virtual sf::Drawable
{
	public:
	Tile();
	Tile( Tile const &that );
	Tile( TileSubtype const *subtype );

	Tile &operator=( Tile const &that );

	virtual void draw( sf::RenderTarget &target, sf::RenderStates states ) const override;

	bool passable() const;

	TileSubtype const *subtype;
};
