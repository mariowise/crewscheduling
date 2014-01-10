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

int currentDude = 0;
int currentGen = 0;
int popSize = 500;
int cantGen = 500;

float PROGRESS = 0.0f;
float GPROGRESS = popSize * cantGen;
ofstream * sfy;
int sfyCount = 0;
float * bestOfAllTimes;

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


	currentGen = currentDude / popSize;
	if(fit < bestOfAllTimes[currentGen])
		bestOfAllTimes[currentGen] = fit;

	// *sfy << ++sfyCount << ";" << fit << ";\n";

	currentDude++;
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

	cout << "Configurando el GAlib" << endl;
	
	bestOfAllTimes = (float *) malloc(sizeof(float) * cantGen);
	for(int i = 0; i < cantGen; i++) bestOfAllTimes[i] = 10000.0;

	GASimpleGA ga(genoma);
	ga.populationSize(popSize);
	ga.nGenerations(cantGen);
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

	for(int i = 0; i < cantGen; i++)
		*sfy << i << ";" << bestOfAllTimes[i] << ";" << endl;
}
