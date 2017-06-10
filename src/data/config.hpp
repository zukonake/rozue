#pragma once

#include <render/typedef.hpp>
#include <data/loadable.hpp>

namespace coldline
{

class DataMap;

struct Config : public Loadable
{
	Config( RenderSize const &screenSize, RenderSize const &spriteSize ) noexcept;
	Config( DataMap const &dataMap );
	RenderSize screenSize;
	RenderSize spriteSize;
};

}
