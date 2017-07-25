#pragma once

#include <cstdint>
#include <cstddef>
#include <stack>
//
#include <network/common.hpp>
#include <network/ColdHeader.hpp>

namespace network
{

template< DatagramSize size = 0 >
class ColdPacket
{
public:
	explicit ColdPacket( Data< size > const &data, ColdHeader const &header );
	explicit ColdPacket( ColdHeader const &header );
	ColdPacket( Data< size + 1> const &data );

	operator Data< size + 1 > const &() const noexcept;

	ColdPacket &operator<<( bool const &value );
	ColdPacket &operator<<( uint8_t const &value );
	ColdPacket &operator<<( int8_t const &value );
	ColdPacket &operator<<( uint16_t const &value );
	ColdPacket &operator<<( int16_t const &value );
	ColdPacket &operator<<( uint32_t const &value );
	ColdPacket &operator<<( int32_t const &value );
	ColdPacket &operator<<( uint64_t const &value );
	ColdPacket &operator<<( int64_t const &value );
	ColdPacket &operator<<( float const &value );
	ColdPacket &operator<<( double const &value );
	ColdPacket &operator<<( std::string const &value );

	ColdPacket const &operator>>( bool &value );
	ColdPacket const &operator>>( uint8_t &value );
	ColdPacket const &operator>>( int8_t &value );
	ColdPacket const &operator>>( uint16_t &value );
	ColdPacket const &operator>>( int16_t &value );
	ColdPacket const &operator>>( uint32_t &value );
	ColdPacket const &operator>>( int32_t &value );
	ColdPacket const &operator>>( uint64_t &value );
	ColdPacket const &operator>>( int64_t &value );
	ColdPacket const &operator>>( float &value );
	ColdPacket const &operator>>( double &value );
	ColdPacket const &operator>>( std::string &value );

	ColdHeader const &getHeader() const;
	void setHeader( ColdHeader const &header );
	Data< size + 1 > const &getData() const noexcept;
private:
	Data< size + 1 > mData;
	DatagramSize mIndex;
};

}

#include "ColdPacket.inl"
