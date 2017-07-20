#include <iostream>
#include <string>
//
#include "logger.hpp"

namespace utility
{

Logger::Logger( Level const &level ) :
	mLevel( level )
{
	log( "LOG", TRACE, "Created Logger" );
}

Logger::~Logger()
{
	log( "LOG", TRACE, "Destroyed Logger" );
}

void Logger::log( std::string const &prefix, Level const &level, std::string const &message )
{
	if( level > mLevel )
	{
		return;
	}
	std::string output = "[" + prefix + "] ";
	switch( level )
	{
	case OFF:
		return;

	case CRITICAL:
		output += "CRT: ";
		break;

	case ERROR:
		output += "ERR: ";
		break;

	case WARN:
		output += "WRN: ";
		break;

	case INFO:
		output += "INF: ";
		break;

	case DEBUG:
		output += "DBG: ";
		break;

	case TRACE:
		output += "TRC: ";
		break;
	}
	output += message;
	std::cout << output << std::endl;
}

Logger logger( Logger::ALL );

}
