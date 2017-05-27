#pragma once

#include <SFML/System.hpp>
//
#include <data/outputData.hpp>
#include <render/camera.hpp>

class Dataset;
class World;
class Entity;
struct InputData;

class Player
{
	public:
	Player( Dataset const &dataset, World &world );

	OutputData requestOutputData() noexcept;
	void receiveInputData( InputData const &inputData ) noexcept;
	private:
	void handleKeys( sf::Event event );

	Dataset const &mDataset;
	World &mWorld;
	Camera mCamera;
	OutputData mOutputData;
};
