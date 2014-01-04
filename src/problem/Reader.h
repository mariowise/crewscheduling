#ifndef READER_H_
#define READER_H_

#include <string>

using namespace std;
class Reader {
public:
	string path;

	Reader();
	Reader(string path) : path(path) {};

	//bool isValid(string path);
	//void readFile(string path);	
};

#endif