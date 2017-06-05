#pragma once

namespace coldline
{

namespace render
{
	class Tile;
}

class TileSubtype;
class Entity;

class Tile
{
	public:
	Tile();
	Tile( Tile const &that );
	Tile( TileSubtype const &subtype );

	Tile &operator=( Tile const &that );
	Tile &operator=( TileSubtype const &that );

	render::Tile const &getRenderTile() const noexcept;

	bool passable() const;
	private:
	TileSubtype const *mSubtype;
};

}
