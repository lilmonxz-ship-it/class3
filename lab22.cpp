#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		friend ComplexNumber operator+(const ComplexNumber &, const ComplexNumber &);
		friend ComplexNumber operator-(const ComplexNumber &, const ComplexNumber &);
		friend ComplexNumber operator*(const ComplexNumber &, const ComplexNumber &);
		friend ComplexNumber operator/(const ComplexNumber &, const ComplexNumber &);
		friend bool operator==(const ComplexNumber &, const ComplexNumber &);
		friend ostream& operator<<(ostream&, const ComplexNumber&);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber operator+(const ComplexNumber &c1, const ComplexNumber &c2){
	return ComplexNumber(c1.real+c2.real,c1.imag+c2.imag);
}

ComplexNumber operator-(const ComplexNumber &c1, const ComplexNumber &c2){
	return ComplexNumber(c1.real-c2.real,c1.imag-c2.imag);
}

ComplexNumber operator*(const ComplexNumber &c1, const ComplexNumber &c2){
	return ComplexNumber((c1.real * c2.real) - (c1.imag * c2.imag), 
                         (c1.real * c2.imag) + (c1.imag * c2.real));
}

ComplexNumber operator/(const ComplexNumber &c1, const ComplexNumber &c2){
	double denominator = (c2.real * c2.real) + (c2.imag * c2.imag);
	return ComplexNumber(((c1.real * c2.real) + (c1.imag * c2.imag)) / denominator, 
                         ((c1.imag * c2.real) - (c1.real * c2.imag)) / denominator);
}

bool operator==(const ComplexNumber &c1, const ComplexNumber &c2){
	return (c1.real == c2.real) && (c1.imag == c2.imag);
}
//Write your code here.
double ComplexNumber::abs(){
	return sqrt((real * real) + (imag * imag));
}

double ComplexNumber::angle(){

	return atan2(imag, real) * 180.0 / acos(-1.0); 
}


ostream& operator<<(ostream& os, const ComplexNumber& c){
    if (c.real == 0 && c.imag == 0) {
        os << 0;
    } else if (c.real == 0) {
        os << c.imag << "i";
    } else if (c.imag == 0) {
        os << c.real;
    } else {
        os << c.real;
        if (c.imag > 0) {
            os << "+";
        }
        os << c.imag << "i";
    }
    return os;
}
