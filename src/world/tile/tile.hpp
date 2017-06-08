#pragma once

namespace coldline
{

namespace render
{
	class Tile;
}

class TileSubtype;

class Tile
{
	public:
	Tile() = default;
	Tile( Tile const &that ) noexcept;
	Tile( TileSubtype const &subtype ) noexcept;

	Tile &operator=( Tile const &that ) noexcept;
	Tile &operator=( TileSubtype const &that ) noexcept;

	render::Tile const &getRenderTile() const noexcept;

	bool passable() const noexcept;
	private:
	TileSubtype const *mSubtype;
};

}
