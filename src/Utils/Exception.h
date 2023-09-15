#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <stdexcept>
#include <string>

class syntax_error : public std::runtime_error {
	using std::runtime_error::runtime_error;
};

class semantic_error : public std::runtime_error {
	using std::runtime_error::runtime_error;
};
#endif