// #include <iostream>
// #include <vector>
// #include <cstring>


// #include <eda/TimeInterval.h>
// #include <eda/Trip.h>
// #include <eda/Station.h>
// #include <eda/Service.h>
// #include <problem/Phenotype.h>
// #include <problem/ProblemChecks.h>

// #include <Common.h>

// using namespace std;

// // Revisa la validez del individuo según los viajes en sus servicios sean únicos 
// // o no. 
// float ProblemChecks::uniqueTrip(Phenotype & dude) {
// 	bool valid = true;
// 	float fitness = 0;

// 	// Para cada servicio en el individuo.
// 	for (int i = 0; i < (dude.services.size()) && (valid == true); i++) {

// 		// Para cada viaje en el servicio i.
// 		for (int j = 0; j < dude.services.at(i).tripList.size(); j++) {

// 			Trip tripI = trips.at(dude.services.at(i).tripList.at(j)); 

// 			// Para cada servicio k a partir del servicio i.
// 			for (int k = i+1; k < dude.services.size(); k++) {

// 				//Comparar con cada viaje l del servicio k (posterior a i).
// 				//Agregado && (valid == true)
// 				for (int l = 0; l < (dude.services.at(k).tripList.size()) && (valid == true); l++) { 

// 					Trip tripL = trips.at(dude.services.at(k).tripList.at(l));

// 					if (tripI.initTime.toSeg() == tripL.initTime.toSeg()) {
// 						valid = false;
// 						dude.services.at(i).partialFitness += 5000;
// 						fitness += 5000;
// 					}
// 				}
// 			}
// 		}
// 	}
// 	return fitness;
// } 

// float ProblemChecks::validRest(Phenotype & dude) {

// 	float fitness = 0;
// 	DateTime zero("00:00");

// 	// Para cada servicio en el individuo.
// 	for (int i = 0; i < dude.services.size(); i++) {
// 		DateTime initFat, endFat, delta;
// 		DateTime totalLazyTime("00:00");
// 		TimeInterval rest;

// 		if (dude.services.at(i).remainingRest < zero) {			
			
// 			dude.services.at(i).partialFitness += 1;
// 			fitness += 1;
// 		}

// 		else {
// 			// Para cada viaje j del servicio i
// 			for (int j = 0; j + 1 < dude.services.at(i).tripList.size(); j++) {

// 				Trip init = trips.at(dude.services.at(i).tripList.at(j));
// 				Trip end = trips.at(dude.services.at(i).tripList.at(j+1));

// 				initFat = init.posFat();
// 				endFat = end.preFat();

// 				// Si el intervalo no tiene un almuerzo
// 				if (init.initTime.toSeg() + initFat.toSeg() != dude.services.at(i).lunchTime.initTime.toSeg()) {
					
// 					// Sumo el intervalo al tiempo ocioso total.
// 					rest.initTime = init.endTime + endFat;
// 					rest.endTime = end.initTime - endFat;
// 					delta = rest.length();
// 					totalLazyTime = totalLazyTime + delta;
// 				}
// 			}
// 		}

// 		// Si el tiempo ocioso total es mayor al máximo del descanso, se penaliza al servicio.
// 		if (totalLazyTime > generalIntervals.at("maxTimeRest")) {
// 			dude.services.at(i).partialFitness += 1;
// 			fitness += 1;
// 		} 
// 	}

// 	return fitness;
// }

// float ProblemChecks::validLunch(Phenotype & dude){

// 	DateTime tarde("17:00");
// 	float fitness = 0;
// 	int idTrip;


// 	for(int i = 0; i < dude.services.size(); i++){
// 		if(dude.services.at(i).tripList.size() > 0){
// 			idTrip =dude.services.at(i).tripList.at(0); 

// 			if(trips.at(idTrip).initTime.h <= tarde.h && dude.services.at(i).lunchTime.type.compare("lunch")!=0){
// 				fitness += 1;
// 				dude.services.at(i).partialFitness += 1;
// 			}
// 		}
// 	}
// 	return fitness;
// }

// float ProblemChecks::validWladi(Phenotype & dude) {
// 	int count = 0;
// 	for(int i = 0; i < dude.services.size(); i++) 
// 		count += dude.services.at(i).tripList.size();	
// 	return (count == trips.size()) ? 0 : 5000;
// }

// float ProblemChecks::serviceLimit(Phenotype & dude) {
// 	bool valid = true;
// 	float fitness = 0;

// 	for (int i = 0; (i < dude.services.size()) && (valid == true); i++) {
// 		if (dude.services.at(i).length().toSeg() > generalIntervals.at("maxTimeDriving").toSeg()) {
// 			valid = false;
// 			dude.services.at(i).partialFitness += 500;
// 			fitness += 500;
// 		} 
// 	}
// 	return fitness;
// } 
