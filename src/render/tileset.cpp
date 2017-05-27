#include <data/dataMap.hpp>
#include <auxiliary.hpp>
#include "tileset.hpp"

Tileset::Tileset( DataMap const &dataMap ) :
	mSpriteSize( auxiliary::loadSize2( dataMap ) )
{
	mTexture.loadFromFile( dataMap.getString( "path" ));
}

Tileset::Tileset( std::string const &path, Size2 const &spriteSize ) :
	mSpriteSize( spriteSize )
{
	mTexture.loadFromFile( path );
}

Size2 const &Tileset::getSpriteSize() const noexcept
{
	return mSpriteSize;
}

sf::Texture const &Tileset::getTexture() const noexcept
{
	return mTexture;
}
