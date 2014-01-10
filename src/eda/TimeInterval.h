#ifndef TIMEINTERVAL_H_
#define TIMEINTERVAL_H_

#include <eda/DateTime.h>
#include <string>
#include <vector>

class TimeInterval {
public: 
	int id;
	std::string type;
	DateTime initTime;
	DateTime endTime;
	DateTime cc;
	DateTime c;
	int fat;

	TimeInterval() {}
	TimeInterval(const TimeInterval & orig) {
		id = orig.id;
		type = orig.type;
		initTime = orig.initTime;
		endTime = orig.endTime;
		fat = orig.fat;
		cc = orig.cc;
		c = orig.c;
	}
	TimeInterval(int id, std::string type) : 
		id(id), type(type), initTime(0, 0), endTime(0, 0), cc(0, 0), c(0, 0) {};
	TimeInterval(int id, std::string type, DateTime initTime, DateTime endTime, int fat) :
		id(id), type(type), initTime(initTime), endTime(endTime), fat(fat) {};
	TimeInterval(DateTime initTime, DateTime endTime) : 
		id(), type(), initTime(initTime), endTime(endTime) {};
	TimeInterval(std::vector<TimeInterval> daFats, DateTime now) {
		int i;
		DateTime lb, ub, final;

		for(i = 0; i < daFats.size(); i++) {
			lb = daFats.at(i).initTime;
			ub = daFats.at(i).endTime;
			if(now >= lb && now <= ub) {
				DateTime final(0, daFats.at(i).fat);
				initTime = now;
				endTime = now + final;				
				return;
			}
		}
		endTime = (DateTime) "0:5";
		initTime = now;
		endTime = now + endTime;
	}

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