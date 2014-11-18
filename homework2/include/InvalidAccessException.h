#ifndef _H_INVALID_ACCESS_EXCEPTION
#define _H_INVALID_ACCESS_EXCEPTION_

#include <exception>

class InvalidAccess : public std::exception {
public:
    InvalidAccess() {}
    const char * what() const throw() { return "Invalid action";}

};

#endif //_H_INVALID_ACCESS_EXCEPTION_