#pragma once
#include <stdexcept>
namespace chess {

	class KingException : public std::logic_error {
	public:
		using logic_error::logic_error;
	};
}