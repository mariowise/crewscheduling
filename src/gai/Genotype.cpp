#include <iostream>
#include <sstream>
#include <ctime>
#include <string>
#include <unistd.h>

#include <ga/GA1DBinStrGenome.h>
#include <ga/GASimpleGA.h>
#include <ga/GAGenome.h>
#include <problem/Phenotype.h>

#include <gai/Genotype.h>
#include <Common.h>

using namespace std;

int globalCount = 0;

float Genotype::evaluator(GAGenome & dude) {
	// sleep(1);
	// cout << endl << "Trips.size() = " << trips.size() << endl << endl;
	GA1DBinaryStringGenome & realDude = ((GA1DBinaryStringGenome &) dude);
	string genome;
	ostringstream os;

	for(int i = 0; i < trips.size() * trips.size(); i++){
		os << realDude.gene(i);
	}

	genome = os.str();

	Phenotype p;
	p.createServices(genome);
	// cout << p;
	// cout << "  evaluator(" << genome << ")";
	float fit = p.fitness();

	// if(globalCount++ % 1000 == 0) {
	// 	cout << genome << "(" << fit << ")" << endl;	
	// }

	
	// if(fit < 100) {
	// 	cout << "Apareció un wn bkn " << genome << "(" << fit << ")" << endl;
	// 	// exit(0);
	// }

	if(fit == 0) {
		fit = 5010;
	}

	return 1/fit;
}

void Genotype::main() {
	GARandomSeed(time(NULL));

	// Configuración de GA
	int genotypeLength = trips.size() * trips.size();

	// Se crea el objeto genoma
	cout << "Creando prototipo para Genoma (" << genotypeLength << ")" << endl;
	GA1DBinaryStringGenome genoma(genotypeLength, Genotype::evaluator);

	// Lanzamiento del algoritmo genético
	cout << "Configurando el GAlib" << endl;
	GASimpleGA ga(genoma);
	ga.populationSize(500);
	ga.nGenerations(6000);
	ga.pMutation(0.01);
	ga.pCrossover(0.9);
	ga.evolve(); // Launch

	ostringstream wladi;
	wladi << ga.statistics().bestIndividual();

	Phenotype fwladi;
	fwladi.createServices(wladi.str());

	cout << "\nThe GA found: (" << fwladi.fitness() << ")" << wladi.str() << "\n";	

	cout << fwladi << endl;
}
