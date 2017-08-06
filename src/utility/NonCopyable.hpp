#pragma once

namespace utility
{

class NonCopyable
{
public:
	NonCopyable() = default;

	NonCopyable( NonCopyable const &that ) = delete;
	NonCopyable &operator=( NonCopyable const &that ) = delete;
};

}
