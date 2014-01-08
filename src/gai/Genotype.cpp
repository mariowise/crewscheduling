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

float Genotype::evaluator(GAGenome & dude) {
	// sleep(1);
	cout << endl << "Trips.size() = " << trips.size() << endl << endl;
	GA1DBinaryStringGenome & realDude = ((GA1DBinaryStringGenome &) dude);
	string genome;
	ostringstream os;

	for(int i = 0; i < realDude.length(); i++){
		os << realDude.gene(i);
		genome += os.str();
		os.clear();
	}

	Phenotype p;
	p.createServices(genome);
	cout << p;
	cout << "  evaluator(" << genome << ")";
	float fit = p.fitness();

	cout << " = " << fit << endl;

	return fit;
}

void Genotype::main() {
	GARandomSeed(time(NULL));

	// Configuración de GA
	int genotypeLength = trips.size() * trips.size();
	int popSize = 50;
	int nGen = 400;
	float pMut = 0.001;
	float pCross = 0.9;

	// Se crea el objeto genoma
	cout << "Creando prototipo para Genoma (" << genotypeLength << ")" << endl;
	GA1DBinaryStringGenome genoma(genotypeLength, Genotype::evaluator);

	// Lanzamiento del algoritmo genético
	cout << "Configurando el GAlib" << endl;
	GASimpleGA ga(genoma);
	ga.populationSize(popSize);
	ga.nGenerations(nGen);
	ga.pMutation(pMut);
	ga.pCrossover(pCross);
	ga.evolve(); // Launch

	// El wladi de la wea
	cout << "The GA found:\n" << ga.statistics().bestIndividual() << "\n";
}