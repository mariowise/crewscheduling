#include <iostream>
#include <fstream>
#include <string>

#include <problem/Reader.h>

#include <Common.h>

using namespace std;

 // Lee la entrada y carga los datos correspondientes
 void Reader::readFile(const char * filename){

 	ifstream f(filename, ifstream::in);
 	string line;


 	if(!f){
 		cout << "Error en archivo" << endl;
 		exit(0);
 	}

 	while(!f.eof()){
 		getline(f, line);
 		cout << line << endl;
 	}
 	
 	
 	
}