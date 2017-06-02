#pragma once

#include <string>
//
#include <render/typedef.hpp>
#include <data/loadable.hpp>

namespace coldline
{

class DataMap;

struct Config : public Loadable
{
	Config( screen::Size const &screenSize );
	Config( DataMap const &dataMap );
	screen::Size screenSize;
};

}
