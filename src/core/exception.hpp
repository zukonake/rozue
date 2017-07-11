#pragma once

#include <exception>

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

};

/**
 * Thrown when there is no Client associated with given ClientID.
 */
class InvalidClientID : public Exception
{

};

/**
 * Thrown when Client is not connected when the action requires it to be.
 */
class NotConnected : public Exception
{

};

}
