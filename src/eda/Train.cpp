#include <iostream>
#include <eda/Train.h>

using namespace std;

ostream & operator<<(ostream & os, const Train & U) {
    os 	<< "{ id: '" << U.id << "', "
    	<< "name: '" << U.name << "' }";
    return os;
}