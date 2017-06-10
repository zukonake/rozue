#pragma once

#include <geometry/vector2.hpp>
#include <geometry/line2.hpp>
#include <geometry/rectangle.hpp>

namespace coldline
{

typedef float RenderCoordinate;
typedef float RenderLength;
typedef ::coldline::geometry::Vector2< RenderCoordinate > RenderPoint;
typedef ::coldline::geometry::Vector2< RenderCoordinate > RenderScale;
typedef ::coldline::geometry::Vector2< RenderCoordinate > RenderSize;
typedef ::coldline::geometry::Vector2< RenderCoordinate > RenderVector;
typedef ::coldline::geometry::Line2< RenderCoordinate > RenderLine;
typedef ::coldline::geometry::Rectangle< RenderCoordinate, RenderLength > RenderSurface;

}

