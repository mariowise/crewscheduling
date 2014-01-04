#ifndef SERVICE_H_
#define SERVICE_H_

#include <string>
#include <vector>

#include <eda/TimeInterval.h>

using namespace std;

class Service {
public:
	int id;
	vector<int> tripList;
	TimeInterval lunchTime;

	Service();
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
};

#endif