#pragma once

#include <stdexcept>

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
