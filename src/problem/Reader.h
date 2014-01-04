#ifndef READER_H_
#define READER_H_

#include <string>
#include <vector>

class Reader {
public:
	std::string path;

	Reader() {}
	Reader(std::string path) : path(path) {}

	
	void readFile(const char * filename);	
	std::vector<std::string> split(std::string str, const char * delim);
	void testRead();

private:

	bool isPrivate(std::string line);
};

#endif