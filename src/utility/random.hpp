#pragma once

#include<random>

namespace utility
{

class NumberGenerator : std::mt19937
{
	public:
	NumberGenerator();
	NumberGenerator( std::mt19937::result_type const &seed );

	using std::mt19937::operator();

	void setSeed();
	void setSeed( std::mt19937::result_type const &seed );
	private:
};

extern NumberGenerator numberGenerator;

}
