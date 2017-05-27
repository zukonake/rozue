#pragma once

#include <render/renderable.hpp>

class TileSubtype;

class Tile : public Renderable
{
	public:
	Tile();
	Tile( Tile const &that );
	Tile( TileSubtype const *subtype );

	Tile &operator=( Tile const &that );

	virtual Sprite const &getSprite() const override;

	bool passable() const;
	private:
	TileSubtype const *mSubtype;
};
