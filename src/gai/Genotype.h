#ifndef GENOTYPE_H_
#define GENOTYPE_H_

#include <iostream>
#include <ga/GASimpleGA.h>	// we're going to use the simple GA
#include <ga/GA1DBinStrGenome.h> // and the 1D binary string genome

class Genotype {
public:
	Genotype() {}

	static float evaluator(GAGenome &);
	static void main();
};

#endif