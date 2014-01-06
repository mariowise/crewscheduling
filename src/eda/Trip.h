#ifndef TRIP_H_
#define TRIP_H_

#include <eda/DateTime.h>
#include <eda/TimeInterval.h>
#include <string>

using namespace std;

class Trip {
public:
	int 			id;
	string 			line;	
	
	DateTime 		initTime;
	int 			initStation;
	
	DateTime 		endTime;
	int 			endStation;	

	Trip();
	Trip(int id, string line, DateTime initTime, int initStation, DateTime endTime, int endStation) :
		id(id), line(line), initTime(initTime), initStation(initStation), endTime(endTime), endStation(endStation) {};

	friend ostream & operator<<(ostream &, const Trip &);

	DateTime length();
};

#endif