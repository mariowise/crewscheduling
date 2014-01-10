#include <iostream>
#include <sstream>
#include <ctime>
#include <string>
#include <cstdio>
#include <unistd.h>

#include <ga/GA1DBinStrGenome.h>
#include <ga/GASimpleGA.h>
#include <ga/GAGenome.h>
#include <problem/Phenotype.h>

#include <gai/Genotype.h>
#include <Common.h>

using namespace std;

float PROGRESS = 0.0f;
float GPROGRESS = 0.0f;
ofstream * sfy;
int sfyCount = 0;

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

	PROGRESS += 1 / GPROGRESS;
	printf("\rEvolucionando %.0f%%", PROGRESS * 100);

	*sfy << ++sfyCount << ";" << fit << ";\n";

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

	// Preparando el archivo de registro de fitness
	sfy = new ofstream("etc/output.csv");

	// Lanzamiento del algoritmo genético
	cout << "Configurando el GAlib" << endl;
	int popSize = 500
	  , genCant = 5;
	GPROGRESS = popSize * genCant;
	GASimpleGA ga(genoma);
	ga.populationSize(popSize);
	ga.nGenerations(genCant);
	ga.pMutation(0.03);
	ga.pCrossover(0.90);
	ga.evolve(); // Launch

	ostringstream wladi;
	wladi << ga.statistics().bestIndividual();

	Phenotype fwladi;
	fwladi.init(wladi.str());

	cout << "\nThe GA found: (" << fwladi.getFitness() << ")\n";	
	
	ofstream fout("www/js/rawData.js");
	fout << fwladi;
}
