#include <iostream>
#include <eda/DateTime.h>

using namespace std;

ostream & operator<<(ostream & os, const DateTime & U) {
    os << U.h << ":" << U.m;
    return os;
}