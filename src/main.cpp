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

map<string, DateTime> generalIntervals;

int main(int argc, char * argv[]) {
	

	Reader rd;

	rd.readFile("etc/EntradaPrototipe.txt");




	return 0;
}