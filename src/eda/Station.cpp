#include <iostream>
#include <eda/Station.h>

std::ostream & operator<<(std::ostream & os, const Station & U) {
    os 	<< "{ id: '" << U.id << "', "
    	<< "name: '" << U.name << "', "
    	<< "restAllowed: '" << U.restAllowed << "' }";
    return os;
}