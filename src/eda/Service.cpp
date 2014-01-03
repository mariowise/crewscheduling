#include <iostream>
#include <eda/Service.h>

using namespace std;

ostream & operator<<(ostream & os, const Service & U) {
	os 	<< "{ id: '" << U.id << "', "
    	<< "tripList: '" << U.tripList.size() << "', "
    	<< "time: " << U.time << " }";
    return os;
}