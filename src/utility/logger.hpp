#pragma once

#include <string>

namespace coldline
{


class Logger
{
	public:
	enum Level
	{
		OFF,
		FATAL,
		ERROR,
		WARN,
		INFO,
		DEBUG,
		TRACE,
		ALL = TRACE
	};

	Logger( Level const &level );
	~Logger();

	void log( Level const &level, std::string const &message );
	private:
	Level mLevel;
};

extern Logger globalLogger;

}
