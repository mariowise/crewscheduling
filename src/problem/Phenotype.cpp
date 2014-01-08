#include <iostream>
#include <string>
#include <vector>
#include <cstring>

#include <eda/Trip.h>
#include <eda/Service.h>

#include <problem/Phenotype.h>
#include <problem/ProblemChecks.h>

#include <Common.h>

using namespace std;

//Crea servicios a partir de la entrada binario de ceros y unos
void Phenotype::createServices(string genotype){

	int numTrips = trips.size();
	int i = 0;
	int j = 0;
	int tripId;
	
	for(i = 0; i < numTrips; i++) {
		Service s;
		s.id = i;
		for(j = numTrips * i; j < numTrips * (i+1); j++) {
			if(genotype[j]=='1') {

				tripId = (j % numTrips);
				s.tripList.push_back(tripId);

			}
		}
		s.lunchAssignment();
		s.restAssignment();
		s.restCorrection();
		s.partialFitness = 0;
		services.push_back(s);

	}
	cout << "Phenotype creado de forma exitosa" << endl;
}

float Phenotype::fitness(){
	cout << "Calculando fitness" << endl;
	ProblemChecks pCh;

	float finalFitness = 0.0f;
	float aux = 0.0f;

	aux = pCh.uniqueTrip(*this);
	cout << "  uniqueTrip = " << aux << endl;
	finalFitness += aux;

	aux = pCh.validRest(*this);
	cout << "  validRest = " << aux << endl;
	finalFitness += aux;

	aux = pCh.validLunch(*this);
	cout << "  validLunch = " << aux << endl;
	finalFitness += aux;
	
	return finalFitness;
}

std::ostream & operator<<(std::ostream & os, const Phenotype & phenom) {
	os << "-----------------------------------------------" << endl;
	os << "--Phenotype------------------------------------" << endl;
	for(int i = 0; i < phenom.services.size(); i++) {
		cout << phenom.services.at(i) << endl;
	}
	os << "-----------------------------------------------" << endl;
}