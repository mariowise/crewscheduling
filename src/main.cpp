#include <iostream>
#include <string>
#include <vector>

#include <eda/DateTime.h>
#include <eda/TimeInterval.h>
#include <eda/Train.h>
#include <eda/Station.h>
#include <eda/Trip.h>
#include <eda/Service.h>

using namespace std;

vector<Trip> trips;

vector<Station> stations;

vector<Service> services;


int main(int argc, char * argv[]) {
	
	DateTime dt("12:50");

	cout << dt << endl;

	return 0;
}