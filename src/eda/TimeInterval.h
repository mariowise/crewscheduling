#ifndef TIMEINTERVAL_H_
#define TIMEINTERVAL_H_

#include <eda/DateTime.h>
#include <string>

class TimeInterval {
public: 
	int id;
	std::string type;
	DateTime initTime;
	DateTime endTime;
	int fat;

	TimeInterval() {};
	TimeInterval(const TimeInterval & orig) {
		id = orig.id;
		type = orig.type;
		initTime = orig.initTime;
		endTime = orig.endTime;
		fat = orig.fat;
	};
	TimeInterval(int id, std::string type) : 
		id(id), type(type), initTime(0, 0), endTime(0, 0) {};
	TimeInterval(int id, std::string type, DateTime initTime, DateTime endTime, int fat) :
		id(id), type(type), initTime(initTime), endTime(endTime), fat(fat) {};
	TimeInterval(DateTime initTime, DateTime endTime) : 
		id(), type(), initTime(initTime), endTime(endTime) {};

	TimeInterval & operator=(const TimeInterval & orig) {
		id = orig.id;
		type = orig.type;
		initTime = orig.initTime;
		endTime = orig.endTime;
	}

	friend std::ostream & operator<<(std::ostream &, const TimeInterval &);

	DateTime length();
};

#endif