#pragma once

#include <string>
#include <vector>
//
#include <render/SFMLClient.hpp>
#include <data/dataset.hpp>

class Server;
struct OutputData;
struct InputData;

/*TODO
 *have autonomous thread which renders until next data is received
 *networking stuff( ip etc. )
 *render only differences from previous data
 */


class Client : SFMLClient
{
public:
	Client( std::string const &name );
	~Client();

	InputData requestInputData() noexcept;
	void receiveOutputData( OutputData outputData ) noexcept;

	void connect( Server* server );
	void disconnect();

	bool isConnected() const noexcept;
	std::string const &getName() const noexcept;
private:
	void render( OutputData const &outputData );

	std::string mName;
	Dataset mDataset;
	Server* mServer;
};
