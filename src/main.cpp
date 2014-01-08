#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>

#include <eda/DateTime.h>
#include <eda/TimeInterval.h>
#include <eda/Station.h>
#include <eda/Trip.h>
#include <eda/Service.h>
#include <problem/Phenotype.h>
#include <gai/Genotype.h>

#include <problem/Reader.h>

using namespace std;

vector<Trip> trips;

vector<Station> stations;

vector<Service> services;

vector<TimeInterval> fats;

map<string, DateTime> generalIntervals;

int main(int argc, char * argv[]) {	
	Reader rd;
	rd.readFile("etc/EntradaPrototipe.txt");
	cout << "Lectura del archivo realizada" << endl;


	Genotype::main();

	return 0;
}