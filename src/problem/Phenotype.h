#ifndef PHENOTYPE_H_
#define PHENOTYPE_H_

#include <iostream>
#include <vector>

#include <eda/Service.h>

using namespace std;

class Phenotype
{
public:
	
	vector<Service> services;

	Phenotype() {};
	
	void createServices(string genotype);	

	float fitness();
	
};
#endif