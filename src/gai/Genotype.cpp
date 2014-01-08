#include <ga/GAGenome.h>
#include <ga/GASimpleGA.h>
#include <ga/std_stream.h>
#include <ga/ga.h>

#include <gai/Genotype.h>
#include <Common.h>

using namespace std;

void Genotype::stripInitializer(GAGenome & genoma) {
	
}

float Genotype::stripEvaluator(GAGenome & genoma) {
	return 0.0f;
}

int Genotype::stripCrossover(const GAGenome& father, const GAGenome& mother, GAGenome* brother, GAGenome* sister) {
	return 0;
}

int Genotype::stripMutator(GAGenome & genoma, float pmut) {
	return 0;
}