#ifndef STATION_H_
#define STATION_H_

using namespace std;

class Station {
public:
	int id;
	string name;
	bool restAllowed;

	Station();
	Station(int id, string name, bool restAllowed) :
		id(id), name(name), restAllowed(restAllowed) {};

	friend ostream & operator<<(ostream &, const Station &);
};

#endif