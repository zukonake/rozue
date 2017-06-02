#pragma once

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Drawable.hpp>
//
#include <render/typedef.hpp>

namespace coldline
{

class Tileset;

class TileMap : public sf::Drawable
{
	public:
	typedef std::vector< std::vector< screen::Point > > Tiles;

	TileMap(
		screen::Size const &tileSize,
		screen::Size const &screenSize,
		Tileset const *tileset );

	virtual void draw( sf::RenderTarget &target, sf::RenderStates states ) const override;

	void update( Tiles const &tiles );
	void setTileSize( screen::Size const &tileSize );
	void setScreenSize( screen::Size const &screenSize );
	void setTileset( Tileset const *tileset );
	private:
	void updateSize();
	screen::Size mSize;
	screen::Size mTileSize;
	screen::Size mScreenSize;
	Tileset const *mTileset;

	sf::VertexArray mVertices;
};

}
