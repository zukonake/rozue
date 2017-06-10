#pragma once

#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Color.hpp>
//
#include <render/typedef.hpp>

namespace coldline
{

class RenderTile;

class Tileset;

class Sprite : public sf::Drawable
{
	public:
	Sprite(
		RenderSurface const &surface,
		RenderTile const &renderTile,
		sf::Color const &color = sf::Color::White );

	virtual void draw( sf::RenderTarget &target, sf::RenderStates states ) const override;

	void setColor( sf::Color const &color );
	void setSurface( RenderSurface const &surface );
	void setRenderTile( RenderTile const &renderTile );
	private:
	sf::Vertex mVertices[ 4 ];
	Tileset const *mTileset;
};

}
