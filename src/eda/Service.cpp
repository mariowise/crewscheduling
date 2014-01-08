#include <iostream>
#include <vector>

#include <eda/TimeInterval.h>
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

// Asigna descansos cuando se ha superado el tiempo de conducción y los resta del tiempo de 
// descanso máximo.	
int Service::restAssignment() {
	DateTime drivenTime("00:00");
	DateTime minRest("00:15");
	DateTime delta, initFat, endFat; //Holguras de inicio y fin de intervalo.
	remainingRest = generalIntervals.at("maxTimeRest"); //Tiempo de descanso restante.
	DateTime maxDrivenTime = generalIntervals.at("maxTimeTrip");//Tiempo máximo de conducción continua.
	TimeInterval rest;

	for (int i = 0; (i+1 < tripList.size()) && (remainingRest.toSeg() > 0); i++) {
		Trip init = trips.at(tripList.at(i)); //<!>
		Trip end = trips.at(tripList.at(i+1)); //<!>

		if ((drivenTime.toSeg() + init.length().toSeg() >= maxDrivenTime.toSeg()) && 
			(init.endTime.toSeg() + init.posFat().toSeg() != lunchTime.initTime.toSeg())) {
			rest.id = 200+id+i;

			// Se calculan las holguras que limitan al intervalo.
			initFat = init.posFat();
			endFat = end.preFat();

			rest.initTime = init.endTime + initFat; //<!> podrían incluirse en la función preFat o posFat
			rest.endTime =  end.initTime - endFat;

			if (rest.length().toSeg() >= minRest.toSeg()) {
				rest.type = "fullRest";
				drivenTime.setZero(); //Dado q rest>15 se reinicia el contador de tiempo continuo.	
			}

			else rest.type = "partialRest";
			
			delta = rest.length();
			remainingRest = remainingRest - delta;
			restList.push_back(rest);
			//drivenTime.setZero();		El tiempo de conducción solo se reinicia cuando rest>15	
		}

		else if (init.endTime.toSeg() + init.posFat().toSeg() == lunchTime.initTime.toSeg()) {
			drivenTime.setZero();
		}

		else if ((drivenTime.toSeg() + init.length().toSeg() < maxDrivenTime.toSeg()) && 
			(init.posFat().toSeg() != lunchTime.initTime.toSeg())){
			delta = end.initTime - init.initTime;
			drivenTime = drivenTime + delta;
		}
	}
	return 0;			 
}

// Asigna el almuerzo en el primer intervalo de tiempo ocioso que sea igual
// o mayor al tiempo de almuerzo máximo - se sugiere renombrarlo como mínimo.
int Service::lunchAssignment() {
	TimeInterval lunchInterval;
	bool lunchAssigned = false;	//Se asignó el horario de almuerzo?
	DateTime maxLunchTime = generalIntervals.at("maxLunchTime");
	DateTime initFat, endFat, delta; //Holguras de inicio y fin de intervalo.
	
	// Se recorren los trips de servicio, dado que se busca un intervalo entre 2 trips se
	// detiene el recorrido en i + 1 < total de trips en servicio. 
	for (int i = 0; (i+1 < tripList.size()) && (lunchAssigned == false); i++) { 
		Trip init = trips.at(tripList.at(i)); //<!>
		Trip end = trips.at(tripList.at(i+1)); //<!>

		// Se calculan las holguras que limitan al intervalo.
		initFat = init.posFat();
		endFat = end.preFat();

		end.initTime = end.initTime - endFat; //<!> podrían incluirse en la función preFat o posFat
		init.endTime = init.endTime + initFat;
		delta = end.initTime - init.endTime;
		
		if (delta >= maxLunchTime) {
			lunchInterval.id = 100+id;
			lunchInterval.type = "lunch";
			lunchInterval.initTime = init.endTime; 
			lunchInterval.endTime = init.endTime + maxLunchTime;
			lunchTime = lunchInterval;
			lunchAssigned = true;
		}
	}

	// En caso de no hallar un intervalo para el almuerzo se establece al servicio
	// como hambriento.
	if (lunchAssigned == false) {
		lunchTime.type = "hungry";
		lunchTime.id = -1;
		lunchTime.initTime = (DateTime)("-1:-1");
		lunchTime.endTime = (DateTime)("-1:-1"); 
	}
	return 0;
}

// Asigna descansos a intervalos de ocioso mientras quede tiempo por asignar. 
void Service::restCorrection() {
	bool restDetected;
	TimeInterval rest;
	DateTime initFat, endFat, delta;

	for (int i = 0; (i+1 < tripList.size()) && (remainingRest.toSeg() > 0); i++){

		restDetected = false;

		Trip init = trips.at( tripList.at( i ) );
		Trip end = trips.at( tripList.at( i+1 ) );

		for(int j = 0; j < restList.size() && restDetected == false; j++) {

			if(((init.endTime.toSeg() + init.posFat().toSeg()) != restList.at(j).initTime.toSeg()) && 
				((init.endTime.toSeg() + init.posFat().toSeg()) != lunchTime.initTime.toSeg())) {

				initFat = init.posFat();
				endFat = end.preFat();

				restDetected = true;
				rest.id = 300+i;
				rest.type = "partialRest";
				rest.initTime = init.endTime + initFat;
				rest.endTime = end.initTime - endFat;

				delta = rest.length();
				remainingRest = remainingRest - delta;
				restList.push_back(rest);
			}
		} 		 
	}	
}
