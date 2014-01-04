#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <eda/DateTime.h>
#include <eda/TimeInterval.h>
#include <eda/Station.h>
#include <eda/Trip.h>
#include <eda/Service.h>

#include <problem/Reader.h>

using namespace std;

vector<Trip> trips;

vector<Station> stations;

vector<Service> services;


int main(int argc, char * argv[]) {
	
	DateTime d1("15:00");
	DateTime d2("13:00");
	cout << (d1 > d2) << endl;

	return 0;
}