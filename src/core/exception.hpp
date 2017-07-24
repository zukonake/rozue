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
 * Thrown when Server/Client is in invalid state for the action.
 */
class InvalidState : public Exception
{
	using Exception::Exception;
};

/**
 * Thrown when the given Client is invalid.
 */
class InvalidClient : public Exception
{
	using Exception::Exception;
};

}
