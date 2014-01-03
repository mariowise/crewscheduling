#include <iostream>
#include <eda/Trip.h>

using namespace std;

ostream & operator<<(ostream & os, const Trip & U) {
    os << "{" << endl
    	<< "  id: '" << U.id << "', " << endl
    	<< "  line: '" << U.line << "', " << endl
    	<< "  initTime: '" << U.initTime << "', " << endl
    	<< "  initStation: '" << U.initStation << "', " << endl
    	<< "  endTime: '" << U.endTime << "', " << endl
    	<< "  endStation: '" << U.endStation << "', " << endl
    	<< "}" << endl;
	return os;
}