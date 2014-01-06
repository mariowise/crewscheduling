#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <eda/DateTime.h>
#include <eda/TimeInterval.h>
#include <eda/Station.h>
#include <eda/Trip.h>
#include <eda/Service.h>

#include <problem/Reader.h>

using namespace std;

vector<Trip> trips;

vector<Station> stations;

vector<Service> services;

vector<TimeInterval> fats;

map<string, DateTime> generalIntervals;



int main(int argc, char * argv[]) {	

	 Reader rd;
	 rd.readFile("etc/EntradaPrototipe.txt");
	 rd.testRead();

	 Service serv;
	 serv.id = 1;
	 serv.tripList.push_back(0);
	 serv.tripList.push_back(1);
	 serv.tripList.push_back(3);
	 serv.tripList.push_back(4);
	 serv.lunchAssignment();
	 cout << serv.lunchTime << endl;
	 
	 serv.restAssignment();

	 for (int i = 0; i < serv.restList.size(); i++) {
	 	cout << serv.restList[i] << endl;
	 }

	 cout << serv.remainingRest << endl;
	return 0;
}