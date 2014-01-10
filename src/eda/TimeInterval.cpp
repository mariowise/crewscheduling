#include <iostream>
#include <eda/TimeInterval.h>

using namespace std;

ostream & operator<<(ostream & os, const TimeInterval & U) {
    os 	<< "{ id: '" << U.id << "', "
    	<< "type: '" << U.type << "', "
    	<< "initTime: " << U.initTime << ", "
    	<< "endTime: " << U.endTime << ", "
    	<< "offset: " << U.initTime.toSeg() << ", "
    	<< "width: " << (U.endTime.toSeg() - U.initTime.toSeg()) << " }";
    return os;
}

DateTime TimeInterval::length() {
	return endTime - initTime;
}

