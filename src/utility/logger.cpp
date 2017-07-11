#include <iostream>
#include <string>
//
#include "logger.hpp"

Logger::Logger( Level const &level ) :
	mLevel( level )
{
	log( TRACE, "Created Logger" );
}

Logger::~Logger()
{
	log( TRACE, "Destroyed Logger" );
}

void Logger::log( Level const &level, std::string const &message )
{
	if( level > mLevel )
	{
		return;
	}
	std::string output;
	switch( level )
	{
	case OFF:
		return;

	case FATAL:
		output = "FATAL: ";
		break;

	case ERROR:
		output = "ERROR: ";
		break;

	case WARN:
		output = "WARN: ";
		break;

	case INFO:
		output = "INFO: ";
		break;

	case DEBUG:
		output = "DEBUG: ";
		break;

	case TRACE:
		output = "TRACE: ";
		break;
	}
	output += message;
	std::cout << output << std::endl;
}

Logger globalLogger( Logger::ALL );
