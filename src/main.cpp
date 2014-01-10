#include <iostream>
#include <fstream>
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
	cout << "Lectura del archivo realizada (" << trips.size() << ")" << endl;

	Genotype::main();

	// string randomDude;
	// for(int i = 0; i < trips.size(); i++)
	// 	randomDude += (i % 2 == 0) ? '1':'0';

	// Phenotype ph;
	// ph.init(randomDude);
	// cout << "fitness: " << ph.getFitness() << endl;


	// ofstream fout("www/js/rawData.js");
	// fout << ph;

	return 0;
}