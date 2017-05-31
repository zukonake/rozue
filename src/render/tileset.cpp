#include <render/typedef.hpp>
#include <data/dataMap.hpp>
#include "tileset.hpp"

namespace coldline
{

Tileset::Tileset( DataMap const &dataMap ) :
	mSpriteSize( dataMap.toVector2< screen::Coordinate >())
{
	mTexture.loadFromFile( dataMap.getString( "path" ));
}

Tileset::Tileset( std::string const &path, screen::Size const &spriteSize ) :
	mSpriteSize( spriteSize )
{
	mTexture.loadFromFile( path );
}

screen::Size const &Tileset::getSpriteSize() const noexcept
{
	return mSpriteSize;
}

sf::Texture const &Tileset::getTexture() const noexcept
{
	return mTexture;
}

}
