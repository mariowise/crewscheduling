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

#include <problem/Reader.h>
#include <problem/Phenotype.h>

using namespace std;

vector<Trip> trips;

vector<Station> stations;

vector<Service> services;

vector<TimeInterval> fats;

map<string, DateTime> generalIntervals;



int main(int argc, char * argv[]) {
	

	  Reader rd;
	  rd.readFile("etc/EntradaPrototipe.txt");
	 // rd.testRead();


	vector<int> geno;
	vector<Service> s;

	srand(time(NULL));

	for(int i = 0; i < trips.size() * trips.size(); i++){
		geno.push_back(rand()%2);
	}
	
	Phenotype p;
	
	p.createServices(geno, s);
	
	return 0;
}