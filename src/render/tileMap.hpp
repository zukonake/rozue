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
	typedef std::vector< std::vector< render::Point > > Tiles;

	TileMap() = default;
	TileMap(
		render::Size const &spriteSize,
		render::Size const &screenSize,
		Tileset const *tileset );

	virtual void draw( sf::RenderTarget &target, sf::RenderStates states ) const override;

	void update( Tiles const &tiles );
	void setSpriteSize( render::Size const &spriteSize );
	void setScreenSize( render::Size const &screenSize );
	void setTileset( Tileset const *tileset );
	private:
	void updateSize();
	render::Size mSize;
	render::Size mSpriteSize;
	render::Size mScreenSize;
	Tileset const *mTileset;

	sf::VertexArray mVertices;
};

}
