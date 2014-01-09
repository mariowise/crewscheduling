#ifndef SERVICE_H_
#define SERVICE_H_

#include <string>
#include <vector>

#include <eda/TimeInterval.h>
#include <eda/DateTime.h>

class Service {
public:
	int id;
	int partialFitness;
	DateTime remainingRest; //Tiempo de descanso restante.
	std::vector<int> tripList;
	std::vector<TimeInterval> restList; //std::Vector destinado al almacenamiento de descansos en el servicio
	TimeInterval lunchTime;

	Service() {}
	Service(const Service & orig) {
		id = orig.id;
		partialFitness = orig.partialFitness;
		remainingRest = orig.remainingRest;
		tripList = orig.tripList;
		lunchTime = orig.lunchTime;
	}
	Service(int id, std::vector<int> tripList, TimeInterval lunchTime) :
		id(id), tripList(tripList), lunchTime(lunchTime) {};
	Service(int id, TimeInterval lunchTime) :
	 	id(id), lunchTime(lunchTime), tripList() {};

	friend std::ostream & operator<<(std::ostream &, const Service &);

	DateTime length();
	// SIEMPRE SE DEBE ASIGNAR EL ALMUERZO ANTES QUE EL DESCANSO Y CORRECCION DESPUES DE DESCANSO
	void restAssignment(); 	//Asignación del descanso en restlist por conducción continua. 
	void lunchAssignment(); 	//Asignción del almuerzp en lunchTime.
	void restCorrection();	//Asignación del tiempo de descanso restante.   
};

#endif