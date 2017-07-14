#pragma once

#include <string>

class Logger
{
	public:
	enum Level
	{
		OFF,
		CRITICAL,
		ERROR,
		WARN,
		INFO,
		DEBUG,
		TRACE,
		ALL = TRACE
	};

	Logger( Level const &level );
	~Logger();

	void log( std::string const &mPrefix, Level const &level, std::string const &message );
	private:
	Level mLevel;
};

extern Logger globalLogger;
