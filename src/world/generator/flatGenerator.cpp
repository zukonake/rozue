#include <world/chunk/chunk.hpp>
#include "flatGenerator.hpp"

namespace coldline
{

FlatGenerator::FlatGenerator( Dataset const &dataset ) :
	mDataset( dataset )
{

}

Chunk FlatGenerator::generate( chunk::Point const &position )
{
	(void)position; //TODO
	return Chunk();
}

}
