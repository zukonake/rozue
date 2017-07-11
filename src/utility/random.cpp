#include "random.hpp"

namespace coldline
{

NumberGenerator::NumberGenerator()
{
	std::random_device randomDevice;
	std::mt19937::seed( randomDevice());
}

NumberGenerator::NumberGenerator( std::mt19937::result_type const &seed )
{
	std::mt19937::seed( seed );
}

void NumberGenerator::seed()
{
	std::random_device randomDevice;
	std::mt19937::seed( randomDevice());
}

void NumberGenerator::seed( std::mt19937::result_type const &seed )
{
	std::mt19937::seed( seed );
}

NumberGenerator globalNumberGenerator;

}
