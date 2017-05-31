#pragma once

#include <SFML/Graphics/Drawable.hpp>
//
#include <data/loadable.hpp>
#include <render/sprite.hpp>

namespace coldline
{

class Dataset;
class DataMap;

class EntitySubtype : public virtual Loadable, public Sprite
{
	friend class Entity;
	public:
	EntitySubtype( Dataset const &dataset, DataMap const &dataMap );
	EntitySubtype( Sprite const &sprite, bool const &solid );

	private:
	bool mSolid;
};

}
