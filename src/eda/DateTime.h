#ifndef DATETIME_H_
#define DATETIME_H_

#include <string>
#include <cstdlib>

class DateTime {
public:
	int h;
	int m;

	DateTime() {}
	DateTime(std::string sf) {
		int i = sf.find(":", 0);
		std::string _h = sf.substr(0, sf.length() - i-1);
		std::string _m = sf.substr(i+1, sf.length() - i);

		h = atoi(_h.c_str());
		m = atoi(_m.c_str());
	}
	DateTime(const DateTime & orig) {
		h = orig.h;
		m = orig.m;
	}
	DateTime(int h) : h(h), m(0) {}
	DateTime(int h, int m) : h(h), m(m) {}

	DateTime & operator=(const DateTime & orig) {
		h = orig.h;
		m = orig.m;
	}

	const DateTime operator+(DateTime & other) {
		return toDateTime(
			this->toSeg() + other.toSeg()
		);
	}

	const DateTime operator-(DateTime & other) {
		return toDateTime(
			this->toSeg() - other.toSeg()
		);		
	}

	friend std::ostream & operator<<(std::ostream &, const DateTime &);
	
	friend bool operator> (DateTime &d1, DateTime &d2);
    
    friend bool operator<= (DateTime &d1, DateTime &d2);
 
    friend bool operator< (DateTime &d1, DateTime &d2);
    
    friend bool operator>= (DateTime &d1, DateTime &d2);


private:
	int toSeg() {
		return 60 * ( m  + h * 60);
	}	

	DateTime toDateTime(int seg) {
		DateTime res
			(seg / (60 * 60), (seg % (60 * 60)) / 60);
		return res;
	}	
};

#endif