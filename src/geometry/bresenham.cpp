#include "bresenham.hpp"

namespace bresenham
{

std::vector< Point > plotLine( Point const &from, Point const &to )
{
	std::vector< Point > line;
	if( from.z != to.z )
	{
		return line;
	}
	Point temp = from;

	int16_t deltaX( to.x - temp.x );
	signed char const iX(( deltaX > 0 ) - ( deltaX < 0 ));
	deltaX = std::abs( deltaX ) << 1;

	int deltaY( to.y - temp.y );
	signed char const iY(( deltaY > 0 ) - ( deltaY < 0 ));
	deltaY = std::abs( deltaY ) << 1;
	
	line.push_back( temp );

	if( deltaX >= deltaY )
	{
		int16_t error( deltaY - ( deltaX >> 1 ));

		while( temp.x != to.x )
		{
			if(( error >= 0 ) && ( error || ( iX > 0 )))
			{
				error -= deltaX;
				temp.y += iY;
			}

			error += deltaY;
			temp.x += iX;

			line.push_back( temp );
		}
	}
	else
	{
		int16_t error( deltaX - ( deltaY >> 1 ));
 
		while( temp.y != to.y )
		{
			if(( error >= 0 ) && ( error || ( iY > 0 )))
			{
				error -= deltaY;
				temp.x += iX;
			}
	
			error += deltaX;
			temp.y += iY;
 
			line.push_back( temp );
		}
	}
	return line;
}

}
