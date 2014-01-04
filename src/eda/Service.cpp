#include <iostream>
#include <eda/Trip.h>
#include <eda/Station.h>
#include <eda/Service.h>

#include <Common.h>

using namespace std;

ostream & operator<<(ostream & os, const Service & U) {
	os 	<< "{ id: '" << U.id << "', "
    	<< "tripList: '" << U.tripList.size() << "', "
    	<< "time: " << U.lunchTime << " }";
    return os;
}

// 	
// 
// length
// 	Retorna el largo del Servicio a traves de la diferencia		
// 	entre el inicio del primer Trip y el fin del último
DateTime Service::length() {
	Trip init = trips.at(tripList.front());
	Trip end = trips.at(tripList.back());
	return end.endTime - init.initTime;
}