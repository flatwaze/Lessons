#include <iostream>
#define N 2

class CComplexVector{
    public:
        CComplex *vector;
        CComplexVector();
        CComplexVector(const CComplexVector& other);
        CComplexVector(CComplex other[]);

        CComplex &operator[](int i);
        const CComplexVector operator+(const CComplexVector& other) const;
        const CComplexVector operator-(const CComplexVector& other) const;
        const CComplexVector operator*(const CComplexVector& other) const;
        const CComplexVector& operator=(const CComplexVector& other);

        friend std :: ostream& operator<<(std :: ostream &out, const CComplexVector& v);
};


