#pragma once

#include <stdexcept>

namespace exception
{

/**
 * Base exception class.
 */
class Exception : public std::runtime_error
{
	using std::runtime_error::runtime_error;
};

/**
 * Thrown when Socket is in invalid state for the action.
 */
class InvalidState : public Exception
{
	using Exception::Exception;
};

/**
 * Thrown when ColdSocket can not connect to server.
 */
class CouldNotConnect : public Exception
{
	using Exception::Exception;
};

}
