#pragma once

#include <cstddef>
#include <string>
//
#include <geometry/vector2.hpp>
#include <geometry/vector3.hpp>

namespace coldline
{

class DataMap
{
	public:
	virtual bool getBool( std::string const &key ) const = 0;
	virtual bool getBool( std::size_t const &index ) const = 0;
	virtual int getInt( std::string const &key ) const = 0;
	virtual int getInt( std::size_t const &index ) const = 0;
	virtual double getDouble( std::string const &key ) const = 0;
	virtual double getDouble( std::size_t const &index ) const = 0;
	virtual std::string getString( std::string const &key ) const = 0;
	virtual std::string getString( std::size_t const &index ) const = 0;

	template< typename T >
	geometry::Vector2< T > toVector2() const;
	template< typename T >
	geometry::Vector3< T > toVector3() const;
};

template< typename T >
geometry::Vector2< T > DataMap::toVector2() const
{ //TODO other types?
	return geometry::Vector2< T >( getDouble( 0 ), getDouble( 1 ));
}

template< typename T >
geometry::Vector3< T > DataMap::toVector3() const
{
	return geometry::Vector3< T >( getDouble( 0 ), getDouble( 1 ), getDouble( 2 ));
}

}
