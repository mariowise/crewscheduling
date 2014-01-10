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

std::ostream & operator<<(std::ostream & os, const Phenotype & phenom) {
	os << "var rawData = [";
	for(int i = 0; i < phenom.services.size(); i++) {
		os << phenom.services.at(i);
		if(i != phenom.services.size()-1) 
			os << ", ";
	}
	os << " ]" << endl;
}

// 
// 
// init
//  Aplica el algoritmo de traducción desde el genotipo al fenotipo
//  llamando a la heurística de apilamiento mediante 'push'
void Phenotype::init(string genotype) {
	int i;
	// A por los 1
	for(i = 0; i < genotype.size(); i++) {
		if(genotype.at(i) == '1')
			_push(i);		
	}
	// A por los 0
	for(i = 0; i < genotype.size(); i++) {
		if(genotype.at(i) == '0')
			_push(i);		
	}
}

// 
// 
// getFitness
//  Calcula y retorna el fitness del individuo en función del número de 
//  que gasta o consume. Se combina además con el promedio de tiempo de
//  descanso de todo el servicio
float Phenotype::getFitness() {
	return 0.0f;
}

// 
// 
// _push
//  Busca un servicio dentro de vector de servicios donde quepa el Trip
//  entrante, si no cabe en ninguno, crea un nuevo servicio y lo apila ahi
void Phenotype::_push(int daTrip) {
	int i;

	for(i = 0; i < services.size(); i++) {
		if(services.at(i).push(daTrip))
			return;
	}
	// Entonces no cupo en ninguno entonces se agrega uno nuevo
	Service newService;
	newService.id = services.size();
	services.push_back(newService);
	services.back().push(daTrip);
}