#include <iostream>
#include <eda/TimeInterval.h>

std::ostream & operator<<(std::ostream & os, const TimeInterval & U) {
    os 	<< "{ id: '" << U.id << "', "
    	<< "type: '" << U.type << "', "
    	<< "initTime: '" << U.initTime << "', "
    	<< "endTime: '" << U.endTime << "' }";
    return os;
}