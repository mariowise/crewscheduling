#include <iostream>
#include <eda/DateTime.h>

std::ostream & operator<<(std::ostream & os, const DateTime & U) {
    os << U.h << ":" << U.m;
    return os;
}