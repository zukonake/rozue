#pragma once

#include <cstdint>
#include <cstddef>
#include <stack>
//
#include <network/common.hpp>
#include <network/cold/Header.hpp>

namespace network
{

namespace cold
{

template< DatagramSize size = 0 >
class Packet
{
public:
	explicit Packet( Data< size > const &data, Header const &header );
	explicit Packet( Header const &header );
	Packet( Data< size + 1> const &data );

	operator Data< size + 1 > const &() const noexcept;

	Packet &operator<<( bool const &value );
	Packet &operator<<( uint8_t const &value );
	Packet &operator<<( int8_t const &value );
	Packet &operator<<( uint16_t const &value );
	Packet &operator<<( int16_t const &value );
	Packet &operator<<( uint32_t const &value );
	Packet &operator<<( int32_t const &value );
	Packet &operator<<( uint64_t const &value );
	Packet &operator<<( int64_t const &value );
	Packet &operator<<( float const &value );
	Packet &operator<<( double const &value );
	Packet &operator<<( std::string const &value );

	Packet const &operator>>( bool &value );
	Packet const &operator>>( uint8_t &value );
	Packet const &operator>>( int8_t &value );
	Packet const &operator>>( uint16_t &value );
	Packet const &operator>>( int16_t &value );
	Packet const &operator>>( uint32_t &value );
	Packet const &operator>>( int32_t &value );
	Packet const &operator>>( uint64_t &value );
	Packet const &operator>>( int64_t &value );
	Packet const &operator>>( float &value );
	Packet const &operator>>( double &value );
	Packet const &operator>>( std::string &value );

	Header const &getHeader() const;
	void setHeader( Header const &header );
	Data< size + 1 > const &getData() const noexcept;
private:
	Data< size + 1 > mData;
	DatagramSize mIndex;
};

}

}

#include "Packet.inl"
