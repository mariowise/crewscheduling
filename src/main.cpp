#include <iostream>
#include <string>
#include <vector>

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
	
	Reader rd;

	rd.readFile("/home/arthen/Proyectos/crewscheduling/etc/EntradaPrototipe.txt");

	return 0;
}