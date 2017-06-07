#pragma once

#include<random>

namespace coldline
{

class NumberGenerator : std::mt19937
{
	public:
	NumberGenerator();
	NumberGenerator( std::mt19937::result_type const &seed );

	using std::mt19937::operator();

	void seed();
	void seed( std::mt19937::result_type const &seed );
	private:
};

extern NumberGenerator globalNumberGenerator;

}
