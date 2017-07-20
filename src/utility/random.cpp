#include "random.hpp"

namespace utility
{

NumberGenerator::NumberGenerator()
{
	setSeed();
}

NumberGenerator::NumberGenerator( std::mt19937::result_type const &seed )
{
	setSeed( seed );
}

void NumberGenerator::setSeed()
{
	std::random_device randomDevice;
	std::mt19937::seed( randomDevice());
}

void NumberGenerator::setSeed( std::mt19937::result_type const &seed )
{
	std::mt19937::seed( seed );
}

NumberGenerator numberGenerator;

}
