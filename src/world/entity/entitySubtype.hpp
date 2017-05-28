#pragma once

#include <data/loadable.hpp>
#include <render/sprite.hpp>

class Dataset;
class DataMap;

class EntitySubtype : public Sprite, public virtual Loadable
{
	friend class Entity;
	public:
	EntitySubtype( Dataset const &dataset, DataMap const &dataMap );
	EntitySubtype( Sprite const &sprite, bool const &solid );

	private:
	bool mSolid;
};
