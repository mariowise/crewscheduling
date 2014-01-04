#include <iostream>
#include <eda/Trip.h>

using namespace std;

ostream & operator<<(ostream & os, const Trip & U) {
    os << "{" 
    	<< "  id: '" << U.id << "', " 
    	<< "  line: '" << U.line << "', " 
    	<< "  initTime: '" << U.initTime << "', " 
    	<< "  initStation: '" << U.initStation << "', " 
    	<< "  endTime: '" << U.endTime << "', " 
    	<< "  endStation: '" << U.endStation << "' " 
    	<< "}" ;
	return os;
}

DateTime Trip::length() {
    return endTime - initTime;
}