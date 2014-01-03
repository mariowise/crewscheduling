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
	int 			trainId;
	
	DateTime 		initTime;
	int 			initStation;
	
	DateTime 		endTime;
	int 			endStation;
	
	TimeInterval 	initFatTime;
	TimeInterval 	endFatTime;

	Trip();
	// Trip(int id, string line) : 
	// 	id(id), line(line) {};
	Trip(int id, string line, int trainId, DateTime initTime, int initStation, DateTime endTime, int endStation, TimeInterval initFatTime, TimeInterval endFatTime) :
		id(id), line(line), trainId(trainId), initTime(initTime), initStation(initStation), endTime(endTime), endStation(endStation), initFatTime(initFatTime), endFatTime(endFatTime) {};

	friend ostream & operator<<(ostream &, const Trip &);
};

#endif