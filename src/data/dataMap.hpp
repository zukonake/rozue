#pragma once

#include <cstddef>
#include <string>

class DataMap
{
	public:
	virtual bool getBool( std::string const &key ) const = 0;
	virtual bool getBool( std::size_t const &index ) const = 0;
	virtual int getInteger( std::string const &key ) const = 0;
	virtual int getInteger( std::size_t const &index ) const = 0;
	virtual double getDouble( std::string const &key ) const = 0;
	virtual double getDouble( std::size_t const &index ) const = 0;
	virtual std::string getString( std::string const &key ) const = 0;
	virtual std::string getString( std::size_t const &index ) const = 0;
};
