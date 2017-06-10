#pragma once

namespace coldline
{

class RenderTile;
class TileSubtype;

class Tile
{
	public:
	Tile() = default;
	Tile( Tile const &that ) noexcept;
	Tile( TileSubtype const &subtype ) noexcept;

	Tile &operator=( Tile const &that ) noexcept;
	Tile &operator=( TileSubtype const &that ) noexcept;

	RenderTile const &getRenderTile() const noexcept;

	bool passable() const noexcept;
	private:
	TileSubtype const *mSubtype;
};

}
