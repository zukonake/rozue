#pragma once

#include <string>
#include <vector>
//
#include <render/typedef.hpp>
#include <render/SFMLClient.hpp>
#include <data/dataset.hpp>

namespace coldline
{

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

	Server* mServer;
	Dataset mDataset;
	render::Size mScreenSize;
	std::string mName;
};

}
