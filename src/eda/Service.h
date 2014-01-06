#ifndef SERVICE_H_
#define SERVICE_H_

#include <string>
#include <vector>

#include <eda/TimeInterval.h>
#include <eda/DateTime.h>

using namespace std;

class Service {
public:
	int id;
	int partialFitness;
	DateTime remainingRest; //Tiempo de descanso restante.
	vector<int> tripList;
	vector<TimeInterval> restList; //Vector destinado al almacenamiento de descansos en el servicio
	TimeInterval lunchTime;

	Service() {}
	Service(const Service & orig) {
		id = orig.id;
		tripList = orig.tripList;
		lunchTime = orig.lunchTime;
	}
	Service(int id, vector<int> tripList, TimeInterval lunchTime) :
		id(id), tripList(tripList), lunchTime(lunchTime) {};
	Service(int id, TimeInterval lunchTime) :
	 	id(id), lunchTime(lunchTime), tripList() {};

	friend ostream & operator<<(ostream &, const Service &);

	DateTime length();
	// SIEMPRE SE DEBE ASIGNAR EL ALMUERZO ANTES QUE EL DESCANSO
	int restAssignment(); 	//Asignación del descanso en restlist 
	int lunchAssignment(); 	//Asignción del almuerzp en lunchTime  
};

#endif