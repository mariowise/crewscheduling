#ifndef DATETIME_H_
#define DATETIME_H_

using namespace std;

class DateTime {
public:
	int h;
	int m;

	DateTime() {};
	DateTime(const DateTime & orig) {
		h = orig.h;
		m = orig.m;
	}
	DateTime(int h) : h(h), m(0) {};
	DateTime(int h, int m) : h(h), m(m) {};

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

	friend ostream & operator<<(ostream &, const DateTime &);
	
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