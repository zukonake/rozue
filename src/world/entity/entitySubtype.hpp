#pragma once

#include <data/loadable.hpp>
#include <render/sprite.hpp>

class Dataset;
class DataMap;

class EntitySubtype : public Sprite, public virtual Loadable
{
	public:
	EntitySubtype( Dataset const &dataset, DataMap const &dataMap );
	EntitySubtype( Sprite const &sprite );
};
