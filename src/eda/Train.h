#ifndef TRAIN_H_
#define TRAIN_H_

using namespace std;

class Train {
public:
	int id;
	string name;

	Train();
	Train(int id) :
		id(id) {};
	Train(int id, string name) :
		id(id), name(name) {};
	
	friend ostream & operator<<(ostream &, const Train &);
};

#endif