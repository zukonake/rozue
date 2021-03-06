#pragma once

namespace network
{

namespace cold
{

template< DatagramSize size >
Packet< size >::Packet( Data< size > const &data, Header const &header ) :
	mIndex( 0 )
{
	*this << static_cast< Byte >( header );
	mData = data;
}

template< DatagramSize size >
Packet< size >::Packet( Header const &header ) :
	mIndex( 0 )
{
	*this << static_cast< Byte >( header );
}

template< DatagramSize size >
Packet< size >::Packet( Data< size + 1 > const &data ) :
	mIndex( 0 )
{
	*this << static_cast< Byte >( 0x00 );
	mData = data;
}

template< DatagramSize size >
Packet< size >::operator Data< size + 1 > const &() const noexcept
{
	return getData();
}

template< DatagramSize size >
Packet< size > &Packet< size >::operator<<( bool const &value )
{
	*this << static_cast< uint8_t >( value );
	return *this;
}

template< DatagramSize size >
Packet< size > &Packet< size >::operator<<( uint8_t const &value )
{
	mData.at( mIndex ) = value;
	mIndex++;
	return *this;
}

template< DatagramSize size >
Packet< size > &Packet< size >::operator<<( int8_t const &value )
{
	*this << static_cast< uint8_t >( value );
	return *this;
}

template< DatagramSize size >
Packet< size > &Packet< size >::operator<<( uint16_t const &value )
{
	*this <<   value & 0xFF00;
	*this << ( value & 0x00FF ) >> 0x8;
	return *this;
}

template< DatagramSize size >
Packet< size > &Packet< size >::operator<<( int16_t const &value )
{
	*this << static_cast< uint16_t >( value );
	return *this;
}

template< DatagramSize size >
Packet< size > &Packet< size >::operator<<( uint32_t const &value )
{
	*this <<   value & 0x000000FF;
	*this << ( value & 0x0000FF00 ) >> 0x08;
	*this << ( value & 0x00FF0000 ) >> 0x10;
	*this << ( value & 0xFF000000 ) >> 0x18;
	return *this;
}

template< DatagramSize size >
Packet< size > &Packet< size >::operator<<( int32_t const &value )
{
	*this << static_cast< uint32_t >( value );
	return *this;
}

template< DatagramSize size >
Packet< size > &Packet< size >::operator<<( uint64_t const &value )
{
	*this <<   value & 0x00000000000000FF;
	*this << ( value & 0x000000000000FF00 ) >> 0x08;
	*this << ( value & 0x0000000000FF0000 ) >> 0x10;
	*this << ( value & 0x00000000FF000000 ) >> 0x18;
	*this << ( value & 0x000000FF00000000 ) >> 0x20;
	*this << ( value & 0x0000FF0000000000 ) >> 0x28;
	*this << ( value & 0x00FF000000000000 ) >> 0x30;
	*this << ( value & 0xFF00000000000000 ) >> 0x38;
	return *this; //TODO this is probably slow as fuck
}

template< DatagramSize size >
Packet< size > &Packet< size >::operator<<( int64_t const &value )
{
	*this << static_cast< uint64_t >( value );
	return *this;
}

template< DatagramSize size >
Packet< size > &Packet< size >::operator<<( float const &value )
{
	*this << static_cast< uint32_t >( value );
	return *this;
}

template< DatagramSize size >
Packet< size > &Packet< size >::operator<<( double const &value )
{
	*this << static_cast< uint64_t >( value );
	return *this; //TODO fucks up if size is different
}

template< DatagramSize size >
Packet< size > &Packet< size >::operator<<( std::string const &value )
{
	for( auto const &character : value )
	{
		*this << static_cast< Byte >( character );
	}
	*this << 0; //null terminator to read the string later
	return *this;
}

template< DatagramSize size >
Packet< size > const &Packet< size >::operator>>( bool &value )
{
	*this >> static_cast< uint8_t >( value );
	return *this;
}

template< DatagramSize size >
Packet< size > const &Packet< size >::operator>>( uint8_t &value )
{
	value = mData[ mIndex ];
	mIndex++;
	return *this;
}

template< DatagramSize size >
Packet< size > const &Packet< size >::operator>>( int8_t &value )
{
	*this >> static_cast< uint8_t >( value );
	return *this;
}

template< DatagramSize size >
Packet< size > const &Packet< size >::operator>>( uint16_t &value )
{
	value |= mData[ mIndex ] ;
	mIndex++;
	value |= ( mData.at( mIndex ) & 0xFF00 ) >> 0x8;
	mIndex++;
	value |= ( mData.at( mIndex ) & 0x00FF ) << 0x8;
	mIndex++;
	return *this;
}

template< DatagramSize size >
Packet< size > const &Packet< size >::operator>>( int16_t &value )
{
	*this >> static_cast< uint16_t >( value );
	return *this;
}

template< DatagramSize size >
Packet< size > const &Packet< size >::operator>>( uint32_t &value )
{
	value = 0;
	value |= ( mData.at( mIndex ) & 0xFF000000 ) >> 0x18;
	mIndex++;
	value |= ( mData.at( mIndex ) & 0x00FF0000 ) >> 0x08;
	mIndex++;
	value |= ( mData.at( mIndex ) & 0x0000FF00 ) << 0x08;
	mIndex++;
	value |= ( mData.at( mIndex ) & 0x000000FF ) << 0x18;
	mIndex++;
	return *this;
}

template< DatagramSize size >
Packet< size > const &Packet< size >::operator>>( int32_t &value )
{
	*this >> static_cast< uint32_t >( value );
	return *this;
}

template< DatagramSize size >
Packet< size > const &Packet< size >::operator>>( uint64_t &value )
{
	value = 0;
	value |= ( mData.at( mIndex ) & 0xFF00000000000000 ) >> 0x38;
	mIndex++;
	value |= ( mData.at( mIndex ) & 0x00FF000000000000 ) >> 0x28;
	mIndex++;
	value |= ( mData.at( mIndex ) & 0x0000FF0000000000 ) >> 0x18;
	mIndex++;
	value |= ( mData.at( mIndex ) & 0x000000FF00000000 ) >> 0x08;
	mIndex++;
	value |= ( mData.at( mIndex ) & 0x00000000FF000000 ) << 0x08;
	mIndex++;
	value |= ( mData.at( mIndex ) & 0x0000000000FF0000 ) << 0x18;
	mIndex++;
	value |= ( mData.at( mIndex ) & 0x000000000000FF00 ) << 0x28;
	mIndex++;
	value |= ( mData.at( mIndex ) & 0x00000000000000FF ) << 0x38;
	mIndex++;
	return *this;
}

template< DatagramSize size >
Packet< size > const &Packet< size >::operator>>( int64_t &value )
{
	*this >> static_cast< uint16_t >( value );
	return *this;
}

template< DatagramSize size >
Packet< size > const &Packet< size >::operator>>( float &value )
{
	*this >> static_cast< uint32_t >( value );
	return *this;
}

template< DatagramSize size >
Packet< size > const &Packet< size >::operator>>( double &value )
{
	*this >> static_cast< uint64_t >( value );
	return *this;
}

template< DatagramSize size >
Packet< size > const &Packet< size >::operator>>( std::string &value )
{
	while( mData[ mIndex ] != 0 )
	{
		Byte byte;
		*this >> byte;
		value += byte;
	}
	return *this;
}

template< DatagramSize size >
Header const &Packet< size >::getHeader() const
{
	return reinterpret_cast< Header const & >( mData.at( 0 ));
}

template< DatagramSize size >
void Packet< size >::setHeader( Header const &header )
{
	mData.at( 0 ) = header;
}

template< DatagramSize size >
Data< size + 1 > const &Packet< size >::getData() const noexcept
{
	return mData;
}

}

}
