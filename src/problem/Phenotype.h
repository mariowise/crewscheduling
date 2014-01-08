#ifndef PHENOTYPE_H_
#define PHENOTYPE_H_

#include <iostream>
#include <vector>

#include <eda/Service.h>

class Phenotype
{
public:
	std::vector<Service> services;

	Phenotype() {};
	
	void createServices(std::string genotype);	

	float fitness();
	
	friend std::ostream & operator<<(std::ostream &, const Phenotype &);
};
#endif