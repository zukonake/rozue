#pragma once

#include <string>
//
#include <SFML/Graphics.hpp>
//
#include <geometry/size.hpp>
#include <data/loadable.hpp>

class DataMap;

class Tileset : public virtual Loadable
{
	public:
	Tileset( DataMap const &dataMap );
	Tileset( std::string const &path, Size2 const &spriteSize );

	Size2 const &getSpriteSize() const noexcept;
	sf::Texture const &getTexture() const noexcept;
	private:
	Size2 mSpriteSize;

	sf::Texture mTexture;
};
