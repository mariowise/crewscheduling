#ifndef GENOTYPE_H_
#define GENOTYPE_H_

#include <iostream>
#include <ostream>
#include <vector>

class Genotype : public GAGenome {
public:
	std::vector<int> genoma;

	GADefineIdentity("Genotype", 201);
	static void stripInitializer(GAGenome &);
	static float stripEvaluator(GAGenome &);
	static int stripCrossover(const GAGenome&, const GAGenome&, GAGenome*, GAGenome*);
	static int stripMutator(GAGenome &, float);

	Genotype() {
		initializer(stripInitializer);
		evaluator(stripEvaluator);
		crossover(stripCrossover);
		mutator(stripMutator);
	}
	
	Genotype(const Genotype & orig) {
		copy(orig);
	}

	virtual ~Genotype() {}

	Genotype & operator=(const GAGenome & orig) {
		copy(orig);
		return *this;
	}

	virtual void copy(const GAGenome & orig) {
		GAGenome::copy(orig);
		Genotype & theOrig = (Genotype &) orig; // Cast
		genoma = theOrig.genoma;
	}
	
	virtual GAGenome * clone(GAGenome::CloneMethod) const {
		return new Genotype(*this);
	}

	virtual int write(std::ostream & stream) const {
		int i;
		stream << "[";
		for(i = 0; i < genoma.size(); i++) {
			stream << (genoma.at(i)+1);
			if(i != (genoma.size() - 1))
				stream << ", ";
		}
		stream << "]";
	}
};

#endif