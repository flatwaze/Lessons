#include <iostream>
#define N 2

#include "CComplex.hpp"

CComplex :: CComplex() : re(0), im(0){
}

CComplex :: CComplex(double re, double im) : re(re), im(im){
}

CComplex :: CComplex(const CComplex& b){
    re = b.Re();
    im = b.Im();
}

double CComplex :: Re() const{
    return re;
}

double CComplex :: Im() const{
    return im;
}

CComplex& CComplex :: operator=(const CComplex& b){
    re = b.Re();
    im = b.Im();
    return *this;
}

const CComplex CComplex :: operator+(const CComplex& b) const{
    CComplex ans(re + b.Re(), im + b.Im());
    return ans;
}

const CComplex CComplex :: operator-(const CComplex& b) const{
    CComplex ans(re - b.Re(), im - b.Im());
    return ans;
}

const CComplex CComplex :: operator*(const CComplex& b) const{
    CComplex ans(re * b.Re() - im * b.Im(), re*b.Im() + im*b.Re());
    return ans; 
}

std :: ostream& operator<<(std :: ostream &out, const CComplex& z){
    if(z.Im() >=0 ) out << z.Re() << "+" << z.Im() << "i";
    else  out << z.Re() << "" << z.Im() << "i";
	return out;
}
