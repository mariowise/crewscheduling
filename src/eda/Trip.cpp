#include <iostream>
#include <eda/Trip.h>

std::ostream & operator<<(std::ostream & os, const Trip & U) {
    os << "{" << endl
    	<< "  id: '" << U.id << "', " << endl
    	<< "  line: '" << U.line << "', " << endl
    	<< "  trainId: '" << U.trainId << "', " << endl
    	<< "  initTime: '" << U.initTime << "', " << endl
    	<< "  initStation: '" << U.initStation << "', " << endl
    	<< "  endTime: '" << U.endTime << "', " << endl
    	<< "  endStation: '" << U.endStation << "', " << endl
    	<< "  initFatTime: '" << U.initFatTime << "', " << endl
    	<< "  endFatTime: '" << U.endFatTime << "', " << endl
    	<< "}" << endl;
	return os;
}