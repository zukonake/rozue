#pragma once

#include <vector>
//
#include <SFML/Window/Event.hpp>

namespace coldline
{

struct InputData
{
	std::vector< sf::Event > events;
};

}
