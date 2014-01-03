#ifndef TIMEINTERVAL_H_
#define TIMEINTERVAL_H_

#include <eda/DateTime.h>
#include <string>

using namespace std;

class TimeInterval {
public: 
	int id;
	string type;
	DateTime initTime;
	DateTime endTime;

	TimeInterval() {};
	TimeInterval(const TimeInterval & orig) {
		id = orig.id;
		type = orig.type;
		initTime = orig.initTime;
		endTime = orig.endTime;
	};
	TimeInterval(int id, string type) : 
		id(id), type(type), initTime(0, 0), endTime(0, 0) {};
	TimeInterval(int id, string type, DateTime initTime, DateTime endTime) :
		id(id), type(type), initTime(initTime), endTime(endTime) {};

	TimeInterval & operator=(const TimeInterval & orig) {
		id = orig.id;
		type = orig.type;
		initTime = orig.initTime;
		endTime = orig.endTime;
	}

	friend ostream & operator<<(ostream &, const TimeInterval &);
};

#endif