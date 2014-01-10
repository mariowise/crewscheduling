#ifndef SERVICE_H_
#define SERVICE_H_

#include <string>
#include <vector>

#include <eda/TimeInterval.h>
#include <eda/DateTime.h>

class Service {
public:
	int id;
	std::vector<TimeInterval> blocks; 	// Intervalos de Trip, Rest, Fat, Leisure y Lunch
	DateTime timeDriving;
	DateTime timeContinuosDriving;
	DateTime timeLeisure;
	bool hasLunch;

	Service() : 
		timeDriving("0:0"), 
		timeContinuosDriving("0:0"), 
		timeLeisure("0:0"), 
		hasLunch(false) {}
	Service(const Service & orig) {
		id = orig.id;
		blocks = orig.blocks;
		timeDriving = orig.timeDriving;
		timeContinuosDriving = orig.timeContinuosDriving;
		hasLunch = orig.hasLunch;
		timeLeisure = orig.timeLeisure;
	}

	friend std::ostream & operator<<(std::ostream &, const Service &);

	DateTime length();
	bool push(int);

private:
	void _push(std::string, void *);

	// SIEMPRE SE DEBE ASIGNAR EL ALMUERZO ANTES QUE EL DESCANSO Y CORRECCION DESPUES DE DESCANSO
	// void restAssignment(); 	//Asignación del descanso en restlist por conducción continua. 
	// void lunchAssignment(); 	//Asignción del almuerzp en lunchTime.
	// void restCorrection();	//Asignación del tiempo de descanso restante.   
};

#endif