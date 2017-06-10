#pragma once

#include <render/typedef.hpp>
#include <data/loadable.hpp>

namespace coldline
{

class Dataset;
class DataMap;
class Tileset;

class RenderTile : public Loadable
{
	public:
	RenderTile( Dataset const &dataset, DataMap const &dataMap );
	RenderTile( Tileset const &tileset, RenderPoint const &tilesetPosition ) noexcept;
	
	Tileset const &tileset;
	RenderPoint tilesetPosition;
};

}
