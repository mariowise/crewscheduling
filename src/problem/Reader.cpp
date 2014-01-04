#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

#include <problem/Reader.h>
#include <eda/DateTime.h>
#include <eda/TimeInterval.h>
#include <eda/Station.h>
#include <eda/Trip.h>

#include <Common.h>

using namespace std;

 // Lee la entrada y carga los datos correspondientes
 void Reader::readFile(const char * filename){

 	ifstream f(filename, ifstream::in);
 	string line;
 	vector<string> dataSep;
 	string status;

 	

 	if(!f){
 		cout << "Error en archivo" << endl;
 		exit(0);
 	}

 	while(!f.eof()){

 		getline(f, line);
 		
 		if(line.compare("GENERAL") == 0) {
			getline(f, line);
 			while(!isPrivate(line)) {
 				 dataSep = split(line, "\t");
 				 
 				 generalIntervals["maxTimeDriving"] = (DateTime) dataSep.at(0);
 				 generalIntervals["maxTimeTrip"] = (DateTime) dataSep.at(1);	
 				 generalIntervals["maxTimeRest"] = (DateTime) dataSep.at(2);
 				 generalIntervals["maxLunchTime"] = (DateTime) dataSep.at(3);

				 getline(f, line);
 				
 			}

 			dataSep.clear();
 		}

 		if (line.compare("FAT") == 0) {
 			getline(f, line);
 			while(!isPrivate(line)){

 				dataSep = split(line, "\t");
 				TimeInterval ti(atoi(dataSep.at(0).c_str()), dataSep.at(1), (DateTime) dataSep.at(2), (DateTime) dataSep.at(3), atoi(dataSep.at(4).c_str()) );
 				fats.push_back(ti);

 				getline(f, line);
 				dataSep.clear();

 				
 			}
 			dataSep.clear();
 		}

 		if(line.compare("STATION") == 0) {
 			getline(f, line);
 			while(!isPrivate(line)){

 				dataSep = split(line, "\t");
 				Station st(atoi(dataSep.at(0).c_str()), dataSep.at(1), atoi(dataSep.at(2).c_str()));
 				stations.push_back(st);

 				getline(f, line); 
 				dataSep.clear();
 				
 			}
 			dataSep.clear();
 		}

 		if(line.compare("TRIP") == 0){
 			getline(f, line);
 			while(!isPrivate(line)){

 				dataSep = split(line, "\t");
 				Trip t(atoi(dataSep.at(0).c_str()), dataSep.at(1), (DateTime) dataSep.at(2), atoi(dataSep.at(3).c_str()), (DateTime) dataSep.at(4), atoi(dataSep.at(5).c_str()));
 				trips.push_back(t);
 			
 				
 				if(getline(f, line)==NULL){
 					break;
 				}
 				
 				dataSep.clear();
 			
 			}
 			dataSep.clear();
 			
 		}
 		
 	}
 	
}

//Split usando C, devuelve un vector;
vector<string> Reader::split(string str, const char * delim){

	char* token = strtok((char *) str.c_str(), delim);

	vector<string> result;

	while(token != NULL){
		result.push_back(token);
		token = strtok(NULL, delim);
	}

	return result;
}

bool Reader::isPrivate(string str){

	if(	str.compare("GENERAL")==0 || 
		str.compare("FAT")==0 || 
		str.compare("STATION")==0 || 
		str.compare("TRIP")==0){

		return true;
	}
	return false;
}
//Leyendo todos los vectores globales
void Reader::testRead(){

	cout<<"================GENERAL================"<<endl;
	cout<<"Tiempo Maximo de Conduccion : "<<generalIntervals.at("maxTimeDriving")<<endl;
	cout<<"Tiempo de Conduccion Continua : "<<generalIntervals.at("maxTimeTrip")<<endl;
	cout<<"Tiempo maximo de Descanso : "<<generalIntervals.at("maxTimeRest")<<endl;
	cout<<"Tiempo maximo para Almorzar : "<<generalIntervals.at("maxLunchTime")<<endl;
	cout<<"======================================="<<endl;
	cout<<"================FAT===================="<<endl;
	for(int i = 0; i < fats.size(); i++){
		cout<<fats.at(i)<<endl;
	}
	cout<<"======================================="<<endl;
	cout<<"================STATION================"<<endl;
	for(int j = 0; j < stations.size(); j++){
		cout<<stations.at(j)<<endl;
	}
	cout<<"======================================="<<endl;
	cout<<"================TRIP==================="<<endl;
	for(int h = 0; h < trips.size(); h++){
		cout<<trips.at(h)<<endl;
	}
	cout<<"======================================="<<endl;
}