#include <iostream>
#include <eda/Train.h>

std::ostream & operator<<(std::ostream & os, const Train & U) {
    os 	<< "{ id: '" << U.id << "', "
    	<< "name: '" << U.name << "' }";
    return os;
}