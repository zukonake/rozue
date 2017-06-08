#pragma once

#include <render/typedef.hpp>
#include <data/loadable.hpp>

namespace coldline
{

class DataMap;

struct Config : public Loadable
{
	Config( render::Size const &screenSize, render::Size const &spriteSize ) noexcept;
	Config( DataMap const &dataMap );
	render::Size screenSize;
	render::Size spriteSize;
};

}
