#include <iostream>
#define N 2

class CComplex{
    private:
        double re, im;

    public:
        CComplex();
        CComplex(const CComplex& b);
        CComplex(double re, double im);

        double Re() const;
        double Im() const;

        CComplex& operator=(const CComplex& b);
        const CComplex operator+(const CComplex& b) const;
        const CComplex operator-(const CComplex& b) const;
        const CComplex operator*(const CComplex& b) const;
    
        friend std::ostream& operator<<(std::ostream& out, const CComplex& z);
};
