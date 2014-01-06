#include <iostream>
#include <eda/Trip.h>

#include <Common.h>

using namespace std;

ostream & operator<<(ostream & os, const Trip & U) {
    os << "{" 
    	<< "  id: '" << U.id << "', " 
    	<< "  line: '" << U.line << "', " 
    	<< "  initTime: '" << U.initTime << "', " 
    	<< "  initStation: '" << U.initStation << "', " 
    	<< "  endTime: '" << U.endTime << "', " 
    	<< "  endStation: '" << U.endStation << "' " 
    	<< "}" ;
	return os;
}

DateTime Trip::length() {
    return endTime - initTime;
}

// Establece la holgura en el intervalo anterior al viaje.
DateTime Trip::preFat() {
    bool detected = false; // Se ha encontrado la holgura?
    DateTime out;

    for (int i = 0; i < fats.size() && detected == false; i++) {
        if ((initTime > fats.at(i).initTime) && (initTime <= fats.at(i).endTime)) { 
            DateTime temp(00,fats.at(i).fat);
            out = temp;
            detected = true;
        }
    }
    // Holgura predeterminada a 3 min.
    if (detected == false) {
        DateTime temp(00,03);
        out = temp;
    }
    return out;
}

// Establece la holgura en el intervalo posterior al viaje.
DateTime Trip::posFat() {
    bool detected = false; // Se ha encontrado la holgura?
    DateTime out;

    for (int i = 0; i < fats.size() && detected == false; i++) {
        if ((endTime >= fats.at(i).initTime) && (endTime < fats.at(i).endTime)) { 
            DateTime temp(00,fats.at(i).fat);
            out = temp;
            detected = true;
        }
    }
    // Holgura predeterminada a 3 min.
    if (detected == false) {
        DateTime temp(00,03);
        out = temp;
    }
    return out;
}