#pragma once

#include <exception>

namespace Exception
{

class Exception : public std::runtime_error
{

};

class InvalidClient : public Exception
{

};

class NotConnected : public Exception
{

};

}
