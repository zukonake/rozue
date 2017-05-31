#include <data/inputData.hpp>
#include <data/config.hpp>
#include <render/sprite.hpp>
#include <data/dataset.hpp>
#include <world/entity/entitySubtype.hpp>
#include <world/map/map.hpp>
#include <world/world.hpp>
#include "player.hpp"

namespace coldline
{

Player::Player( Dataset const &dataset, World& world ) :
	mDataset( dataset ),
	mWorld( world ),
	mCamera( mDataset.at< Sprite >( "nothing" ),
		mWorld,
		mWorld[ mDataset.at< Config >( "config" ).startingLocation ].createPlayer( mDataset.at< EntitySubtype >( "human" )))
{

}

OutputData Player::requestOutputData() noexcept
{
	OutputData returnValue = mOutputData;
	returnValue.renderQueue = mCamera.getRenderQueue();
	return returnValue;
}

void Player::receiveInputData( InputData const &inputData ) noexcept
{
	for( auto iEvent : inputData.events )
	{
		switch( iEvent.type )
		{
			case sf::Event::Closed:
				mOutputData.playing = false;
				break;

			case sf::Event::KeyPressed:
				handleKeys( iEvent );
				break;

			default:
				break;
		}
	}
}

void Player::handleKeys( sf::Event event )
{
	switch( event.key.code )
	{
		case sf::Keyboard::Escape:
			mOutputData.playing = false;
			break;

		case sf::Keyboard::W:
			mCamera.move({ 0, -1, 0 });
			break;

		case sf::Keyboard::A:
			mCamera.move({ -1, 0, 0 });
			break;

		case sf::Keyboard::S:
			mCamera.move({ 0, 1, 0 });
			break;

		case sf::Keyboard::D:
			mCamera.move({ 1, 0, 0 });
			break;

		case sf::Keyboard::Q:
			mCamera.changeScale({ 0.25f, 0.25f });
			break;

		case sf::Keyboard::E:
			mCamera.changeScale({ -0.25f, -0.25f });
			break;

		default:
			break;
	}
}

}
