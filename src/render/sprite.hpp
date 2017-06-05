#pragma once

#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Color.hpp>
//
#include <render/typedef.hpp>

namespace coldline
{

namespace render
{
	class Tile;
}

class Tileset;

class Sprite : public sf::Drawable
{
	public:
	Sprite(
		render::Surface const &surface,
		render::Tile const &tile,
		sf::Color const &color = sf::Color::White );

	virtual void draw( sf::RenderTarget &target, sf::RenderStates states ) const override;

	void setColor( sf::Color const &color );
	void setSurface( render::Surface const &surface );
	void setTile( render::Tile const &tile );
	private:
	sf::Vertex mVertices[ 4 ];
	Tileset const *mTileset;
};

}
