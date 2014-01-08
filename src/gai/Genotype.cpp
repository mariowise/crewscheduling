#include <iostream>
#include <sstream>
#include <ctime>
#include <string>

#include <ga/GA1DBinStrGenome.h>
#include <ga/GASimpleGA.h>
#include <ga/GAGenome.h>
#include <problem/Phenotype.h>

#include <gai/Genotype.h>
#include <Common.h>

using namespace std;

float Genotype::evaluator(GAGenome & dude) {
	

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



	return p.fitness();
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
	GA1DBinaryStringGenome genoma(genotypeLength, Genotype::evaluator);

	// Lanzamiento del algoritmo genético
	GASimpleGA ga(genoma);
	ga.populationSize(popSize);
	ga.nGenerations(nGen);
	ga.pMutation(pMut);
	ga.pCrossover(pCross);
	ga.evolve(); // Launch

	// El wladi de la wea
	cout << "The GA found:\n" << ga.statistics().bestIndividual() << "\n";
}