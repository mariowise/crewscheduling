#include <iostream>
#include <eda/Station.h>

using namespace std;

ostream & operator<<(ostream & os, const Station & U) {
    os 	<< "{ id: '" << U.id << "', "
    	<< "name: '" << U.name << "', "
    	<< "restAllowed: " << U.restAllowed << " }";
    return os;
}