#pragma once

#include <data/spriteQueue.hpp>

/**
 * Represents data sent from the Server to the Client.
 *
 * ServerData will contain the output data for the Client
 * to parse, for example: what to render and where,
 * what sound to play and with what loudness.
 */
struct ServerData
{
	public:
	SpriteQueue mSpriteQueue;
	private:
};
