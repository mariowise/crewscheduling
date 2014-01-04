#ifndef COMMON_H_
#define COMMON_H_

#include <vector>
#include <map>
#include <string>

#include <eda/Trip.h>
#include <eda/Station.h>
#include <eda/Service.h>
#include <eda/DateTime.h>

extern vector<Trip> trips;

extern vector<Station> stations;

extern vector<Service> services;

extern map<string, DateTime> generalIntervals;

#endif