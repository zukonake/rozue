#include <render/typedef.hpp>
#include <data/dataMap.hpp>
#include <data/dataset.hpp>
#include <render/tileset.hpp>
#include "renderTile.hpp"

namespace coldline
{

RenderTile::RenderTile( Dataset const &dataset, DataMap const &dataMap ) :
	tileset( dataset.at< Tileset >( dataMap.getString( "tileset" ))),
	tilesetPosition( dataMap.getDataMap( "position" )->toVector2< RenderCoordinate >())
{

}

RenderTile::RenderTile( Tileset const &tileset, RenderPoint const &tilesetPosition ) noexcept:
	tileset( tileset ),
	tilesetPosition( tilesetPosition )
{

}

}
