#include <iostream>
#include <string>

#include <eda/DateTime.h>
#include <eda/TimeInterval.h>
#include <eda/Train.h>
#include <eda/Station.h>
#include <eda/Trip.h>
#include <eda/Service.h>

using namespace std;

int main(int argc, char * argv[]) {
	
	DateTime dt(11, 30);
	
	TimeInterval ti(dt, dt);

	Service ser(3, ti);

	cout << ser << endl;
	
	return 0;
}