#pragma once

#include <string>
//
#include <data/loadable.hpp>

struct Config : public Loadable
{
	std::string startingLocation;
};
