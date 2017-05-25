#include <world/world.hpp>
#include "generator.hpp"

Generator::operator World()
{
	return this->generate();
}
