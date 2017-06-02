#include <render/typedef.hpp>
#include <data/dataMap.hpp>
#include "tileset.hpp"

namespace coldline
{

Tileset::Tileset( DataMap const &dataMap ) :
	mTileSize( dataMap.toVector2< screen::Coordinate >())
{
	mTexture.loadFromFile( dataMap.getString( "path" ));
}

Tileset::Tileset( std::string const &path, screen::Size const &tileSize ) :
	mTileSize( tileSize )
{
	mTexture.loadFromFile( path );
}

screen::Size const &Tileset::getTileSize() const noexcept
{
	return mTileSize;
}

sf::Texture const &Tileset::getTexture() const noexcept
{
	return mTexture;
}

}
