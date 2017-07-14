#pragma once

#include <stdexcept>

/**
 * Namespace containing the exceptions.
 */
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
 * Thrown when there is no Client associated with given ClientID.
 */
class InvalidClientID : public Exception
{
	using Exception::Exception;
};

/**
 * Thrown when Client is not connected when the action requires it to be.
 */
class NotConnected : public Exception
{
	using Exception::Exception;
};

/**
 * Thrown when Server/Client is not running when the action requires it to be.
 */
class NotRunning : public Exception
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

/**
 * Thrown when Server can not start listener.
 */
class CouldNotStartListener : public Exception
{
	using Exception::Exception;
};

}
