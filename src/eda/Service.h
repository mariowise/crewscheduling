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
	TimeInterval time;

	Service();
	Service(const Service & orig) {
		id = orig.id;
		tripList = orig.tripList;
		time = orig.time;
	}
	Service(int id, vector<int> tripList, TimeInterval time) :
		id(id), tripList(tripList), time(time) {};
	Service(int id, TimeInterval time) :
	 	id(id), time(time), tripList() {};

	friend ostream & operator<<(ostream &, const Service &);
};

#endif