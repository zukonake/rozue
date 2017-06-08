#pragma once

#include <render/typedef.hpp>
#include <data/loadable.hpp>

namespace coldline
{

class Dataset;
class DataMap;
class Tileset;

namespace render
{


class Tile : public Loadable
{
	public:
	Tile( Dataset const &dataset, DataMap const &dataMap );
	Tile( Tileset const &tileset, Point const &tilesetPosition ) noexcept;
	
	Tileset const &tileset;
	Point tilesetPosition;
};

}

}
