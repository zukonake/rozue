#pragma once

#include <geometry/point.hpp>
#include <geometry/size.hpp>

class DataMap;

namespace auxiliary
{

Point2 loadPoint2( DataMap const &dataMap );
Point3 loadPoint3( DataMap const &dataMap );
Size2 loadSize2( DataMap const &dataMap );
Size3 loadSize3( DataMap const &dataMap );

}
