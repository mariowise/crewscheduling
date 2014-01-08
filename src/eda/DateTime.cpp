#include <iostream>
#include <eda/DateTime.h>

using namespace std;

ostream & operator<<(ostream & os, const DateTime & U) {
    os << "'" << U.h << ":" << "'" << U.m;
    return os;
}

bool operator> (DateTime &d1, DateTime &d2) {
	return d1.toSeg() > d2.toSeg();
}
    
bool operator<= (DateTime &d1, DateTime &d2) {
	return d1.toSeg() <= d2.toSeg();
}
 
bool operator< (DateTime &d1, DateTime &d2) {
	return d1.toSeg() < d2.toSeg();
}
    
bool operator>= (DateTime &d1, DateTime &d2) {
	return d1.toSeg() >= d2.toSeg();
}

int DateTime::setZero() {
	h = 00;
	m = 00;
	return 0;
}