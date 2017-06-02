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

class Tileset : public virtual Loadable
{
	public:
	Tileset( DataMap const &dataMap );
	Tileset( std::string const &path, screen::Size const &tileSize );

	screen::Size const &getTileSize() const noexcept;
	sf::Texture const &getTexture() const noexcept;
	private:
	screen::Size mTileSize;

	sf::Texture mTexture;
};

}
