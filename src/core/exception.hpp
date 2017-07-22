#pragma once

#include <stdexcept>

namespace Exception
{

/**
 * Base exception class.
 */
class Exception : public std::runtime_error
{
	using std::runtime_error::runtime_error;
};

/**
 * Thrown when the given Client is invalid.
 */
class InvalidClient : public Exception
{
	using Exception::Exception;
};

/**
 * Thrown when Server/Client is in invalid state for the action.
 */
class InvalidState : public Exception
{
	using Exception::Exception;
};

/**
 * Thrown when Client can not connect to server.
 */
class CouldNotConnect : public Exception
{
	using Exception::Exception;
};

}
