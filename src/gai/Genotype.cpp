#include <iostream>
#include <ctime>

#include <gai/Genotype.h>
#include <Common.h>

using namespace std;

float Genotype::evaluator(GAGenome & dude) {

	return 0.0f;
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