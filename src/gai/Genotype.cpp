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


// 
// 
// evaluator
//  Se ejecuta por cada individuo de la población para obtener el fitness
float Genotype::evaluator(GAGenome & dude) {
	GA1DBinaryStringGenome & realDude = ((GA1DBinaryStringGenome &) dude);
	string genome;
	ostringstream os;

	for(int i = 0; i < trips.size(); i++)
		os << realDude.gene(i);
	genome = os.str();

	Phenotype p;
	p.init(genome);
	float fit = p.getFitness();
	return 1/fit;
}

// 
// 
// main
//  Corresponde al cuerpo del algoritmo genético en base a GAlib
void Genotype::main() {
	GARandomSeed(time(NULL));

	// Se crea el objeto genoma
	cout << "Creando prototipo para Genoma (" << trips.size() << ")" << endl;
	GA1DBinaryStringGenome genoma(trips.size(), Genotype::evaluator);

	// Lanzamiento del algoritmo genético
	cout << "Configurando el GAlib" << endl;
	GASimpleGA ga(genoma);
	ga.populationSize(500);
	ga.nGenerations(1000);
	ga.pMutation(0.01);
	ga.pCrossover(0.9);
	ga.evolve(); // Launch

	ostringstream wladi;
	wladi << ga.statistics().bestIndividual();

	Phenotype fwladi;
	fwladi.init(wladi.str());

	cout << "\nThe GA found: (" << fwladi.getFitness() << ")" << wladi.str() << "\n";	
	cout << fwladi << endl;
}
