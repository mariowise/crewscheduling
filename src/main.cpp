#include <iostream>
#include <string>

#include <eda/DateTime.h>
#include <eda/TimeInterval.h>
#include <eda/Train.h>
#include <eda/Station.h>
#include <eda/Trip.h>

using namespace std;

int main(int argc, char * argv[]) {
	DateTime dt(1, 2);
	TimeInterval ti(1, "Etiqueta");
	Trip t(
		5,
		(string) "Linea 5",
		1,
		dt, 0,
		dt, 1,
		ti, ti
	);

	cout << t << endl;
	
	return 0;
}