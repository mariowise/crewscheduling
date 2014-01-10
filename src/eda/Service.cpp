#include <iostream>
#include <vector>

#include <eda/DateTime.h>
#include <eda/TimeInterval.h>
#include <eda/Trip.h>
#include <eda/Station.h>
#include <eda/Service.h>

#include <Common.h>

using namespace std;

ostream & operator<<(ostream & os, const Service & U) {
	os 	<< "{ id: '" << U.id << "', "
		<< "timeDriving: " << U.timeDriving << ", "
		<< "timeContinuosDriving: " << U.timeContinuosDriving << ", "
		<< "timeLeisure: " << U.timeLeisure << ", "
		<< "hasLunch: " << U.hasLunch << ", "
    	<< "blocks: [";

    for(int i = 0; i < U.blocks.size(); i++) {
    	os << U.blocks.at(i);
    	if(i != (U.blocks.size()-1))
    		os << ", ";
    }
    
    os 	<< "] }";
    return os;
}

// 	
// 
// length
// 	Retorna el largo del servicio calculando la diferenicia entre el final
//  del ultimo bloque y el comienzo del primero.
DateTime Service::length() {
	return 
	blocks.back().endTime - 
	blocks.front().initTime;
}

//
//
// push
//  Recibe un trip y lo intenta apilar en este servicio verificando las 
//  restricciones del problema. Si no lo puede apilar, retorna false. Si
//  lo logra apilar de forma exitosa retorna true.
bool Service::push(int daTrip) {
	Trip candidate = trips.at(daTrip);
	DateTime aux;

	// Si el blocks esta vacío entra como avión
	if(blocks.size() == 0) {
		// Carga del nuevo block (TimeInterval)
		_push("Trip", &candidate);
		_push("Fat", NULL);
		timeDriving = 
		timeContinuosDriving =
		candidate.length();
		return true;
	}
	// Blocks no esta vacío
	
	// ¿Acaso deberíamos insertar el Lunch?
	if(!hasLunch)
	if(timeDriving >= generalIntervals["maxTimeDrivingBeforeLunch"]) {
		hasLunch = true;
		_push("Lunch", NULL); // Se inserta el Lunch
		timeContinuosDriving = (DateTime) "0:0";
	}

	// ¿Acaso lleva demasiado tiempo conduciendo de forma continua?
	if(timeContinuosDriving >= generalIntervals["maxTimeContinuousDriving"]) {
		timeContinuosDriving = (DateTime) "0:0";	
		_push("Rest", NULL);
	}
	

	// ¿Acaso el Trip entrante cabe en el servicio?
	aux = candidate.length();
	aux = timeDriving + aux;
	if(!(aux < generalIntervals["maxTimeDriving"]))
		return false;
	// El Trip entrante si cabe en el servicio

	// ¿Acaso el Trip entrante esta a la derecha del ultimo bloque?
	if(!(blocks.back().endTime <= candidate.initTime))
		return false;
	// El Trip entrante si esta a la derecha


	/////////////////////////////////////////////////////////////////////
	// Comienza rutina de apilado (Acá se agregará si o si )/////////////
	/////////////////////////////////////////////////////////////////////
	// ¿Acaso al ingresar el Trip entrante se genera un espacio vacío?
	if(blocks.back().endTime < candidate.initTime) {
		_push("Leisure", &candidate.initTime);
		aux = blocks.back().length();
		timeLeisure =
			timeLeisure + aux;
	}

	// Antes de agregar el Trip que ya entra si o si, es necesario
	// incrementar el tiempo de conducción y el tiempo de conducción
	// continua. Si el bloque anterior != "Fat" entonces quiere decir
	// que antes hay un Rest o un Leisure o un Lunch, entonces el tiempo
	// de conducción continua vuelve a "0:0" (Resetea). De forma adicional
	// habrá que comprobar que el Leisure no sea un tiempo muy pequeño
	// en tal caso el tiempo de conducción continua volverá a cero cuando en
	// realidad el leisure solo actúa como corrector pequeño. Entonces para
	// lograr esto consideraremos como Fat aquellos Leisure demasiado pequeños
	// Lo anterior ocurre en el ..::Proxy::.. _push, // Leisure
	aux = candidate.length();
	timeDriving = 
		timeDriving + aux;
	if(blocks.back().type.compare("Fat") == 0) {
		aux = candidate.length();	
		timeContinuosDriving = 
			timeContinuosDriving + aux;
	}
	else 
		timeContinuosDriving = (DateTime) "0:0";
	_push("Trip", &candidate);
	_push("Fat", NULL);
	return true;
}

//
//
// _push ..::Proxy::..
//  Recibe un puntero puntero desconocido y según lo que sea determina
//  que tipo de bloque se va apilar, y finalmente lo apila. Los tipos de 
//  de bloque son: Trip, Rest, Fat, Leisure y Lunch
void Service::_push(string typeName, void * source) {
	TimeInterval candidate;
	
	// Trip
	if(typeName.compare("Trip") == 0) {
		Trip * tr = (Trip *) source;
		candidate.id = tr->id;
		candidate.type = "Trip";
		candidate.initTime = tr->initTime;
		candidate.endTime = tr->endTime;
		candidate.cc = timeContinuosDriving;
		candidate.c = timeDriving;
		blocks.push_back(candidate);
		return;
	}

	// Rest => source == NULL
	else if(typeName.compare("Rest") == 0) {
		DateTime base = blocks.back().endTime;
		DateTime next = base + generalIntervals["restLength"];
		candidate.id = -1;
		candidate.type = "Rest";
		candidate.initTime = base;
		candidate.endTime = next;
		blocks.push_back(candidate);
		return;
	}

	// Fat => source == NULL
	else if(typeName.compare("Fat") == 0) {
		TimeInterval daFat(fats, blocks.back().endTime);
		daFat.type = "Fat";
		daFat.id = -1;
		blocks.push_back(daFat);
		return;
	}

	// Leisure
	else if(typeName.compare("Leisure") == 0) {
		DateTime * leend = (DateTime *) source;
		candidate.id = -1;
		candidate.type = "Leisure";
		candidate.initTime = blocks.back().endTime;
		candidate.endTime = *leend;
		if(candidate.length().toSeg() < 20*60)
			candidate.type = "Fat";
		blocks.push_back(candidate);
		return;
	}

	// Lunch => source == NULL
	else if(typeName.compare("Lunch") == 0) {
		DateTime base = blocks.back().endTime;
		DateTime next = base + generalIntervals["lunchLength"];
		candidate.id = -1;
		candidate.type = "Lunch";
		candidate.initTime = base;
		candidate.endTime = next;
		blocks.push_back(candidate);
		return;
	}

	else {
		cout << "* Error: Se ha llamado al proxy Service::_push con una opción inválida '" << typeName << "'" << endl;
		exit(1);
	}
}
