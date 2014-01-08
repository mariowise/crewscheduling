#include <iostream>
#include <vector>

#include <eda/TimeInterval.h>
#include <eda/Trip.h>
#include <eda/Station.h>
#include <eda/Service.h>
#include <problem/Phenotype.h>
#include <problem/ProblemChecks.h>

#include <Common.h>

using namespace std;

float ProblemChecks::uniqueTrip(Phenotype dude) {
	bool valid = true;
	float fitness = 0;

	// Para cada servicio en el individuo.
	for (int i = 0; i < (dude.services.size()) && (valid == true); i++) {

		// Para cada viaje en el servicio i.
		for (int j = 0; j < dude.services.at(i).tripList.size(); j++) {

			Trip tripI = trips.at(dude.services.at(i).tripList.at(j)); 

			// Para cada servicio k a partir del servicio i.
			for (int k = i+1; k < dude.services.size(); k++) {

				//Comparar con cada viaje l del servicio k (posterior a i).
				for (int l = 0; l < dude.services.at(k).tripList.size(); l++) {

					Trip tripL = trips.at(dude.services.at(k).tripList.at(l));

					if (tripI.initTime.toSeg() == tripL.initTime.toSeg()) {
						valid = false;
						dude.services.at(i).partialFitness += -5000;
						fitness += (float)(-5000);
					}
				}
			}
		}
	}
	return fitness;
} 
