#pragma once

#include <type_traits>
#include <unordered_map>
#include <string>
//
#include <data/loadable.hpp>

namespace coldline
{

class Dataset
{
	public:
	Dataset() noexcept;

	template< typename T >
	T const &at( std::string const &key ) const;
	private:
	std::unordered_map< std::string, const Loadable * > mObjects;
};

template< typename T >
T const &Dataset::at( std::string const &key ) const
{
	static_assert( std::is_base_of< Loadable, T >::value, "Dataset only holds objects of base Loadable" );
	return dynamic_cast< T const & >( *mObjects.at( key ));
}

}
