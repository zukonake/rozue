#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
//
#include <render/typedef.hpp>
#include <data/loadable.hpp>

namespace coldline
{

class Dataset;
class DataMap;
class Tileset;

namespace render
{


class Tile : public virtual Loadable
{
	public:
	Tile( Dataset const &dataset, DataMap const &dataMap );
	Tile( Tileset const &tileset, Point const &tilesetPosition );
	
	Tileset const &tileset;
	Point tilesetPosition;
};

}

}
