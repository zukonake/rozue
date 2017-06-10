#pragma once

#include <string>
//
#include <SFML/Graphics/Texture.hpp>
//
#include <render/typedef.hpp>
#include <data/loadable.hpp>

namespace coldline
{

class DataMap;

class Tileset : public Loadable
{
	public:
	Tileset( DataMap const &dataMap );
	Tileset( std::string const &path, RenderSize const &tileSize );

	RenderSize const &getTileSize() const noexcept;
	sf::Texture const &getTexture() const noexcept;
	private:
	RenderSize mTileSize;

	sf::Texture mTexture;
};

}
