#pragma once

#include <string>
//
#include <SFML/Window/Event.hpp>
//
#include <data/outputData.hpp>
#include <render/camera.hpp>

namespace coldline
{

struct InputData;
class Dataset;
class World;

class Player
{
	public:
	Player( Dataset const &dataset, World &world );

	OutputData requestOutputData() noexcept;
	void receiveInputData( InputData const &inputData ) noexcept;
	private:
	void handleKeys( sf::Event event );

	OutputData mOutputData;
	Dataset const &mDataset;
	World &mWorld;
	Camera mCamera;
};

}
