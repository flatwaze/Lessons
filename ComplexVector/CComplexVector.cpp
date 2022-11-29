#include <iostream>
#define N 2

#include "CComplexVector.hpp"


CComplex& CComplexVector :: operator[](int i){
    return vector[i];
}

CComplexVector :: CComplexVector(){
    vector = new CComplex[N];
}

CComplexVector :: CComplexVector(CComplex other[]){
    vector = new CComplex[N];
    for(int i = 0; i < N; i++) vector[i] = other[i];
}

CComplexVector :: CComplexVector(const CComplexVector& other){
    vector = new CComplex[N];
    for(int i = 0; i < N; i++){
        vector[i] = other.vector[i];
    }
}

const CComplexVector CComplexVector :: operator+(const CComplexVector& other) const{
    CComplexVector ans;

    for(int i = 0; i < N; i++){
        ans.vector[i] = other.vector[i] + vector[i];
    }

    return ans;
}

const CComplexVector CComplexVector :: operator-(const CComplexVector& other) const{
    CComplexVector ans;

    for(int i = 0; i < N; i++){
        ans.vector[i] = other.vector[i] - vector[i];
    }

    return ans;
}

const CComplexVector CComplexVector :: operator*(const CComplexVector& other) const{
    CComplexVector ans;

    for(int i = 0; i < N; i++){
        ans.vector[i] = other.vector[i] * vector[i];
    }

    return ans;
}

const CComplexVector& CComplexVector :: operator=(const CComplexVector& other){
    if(vector == NULL) vector = new CComplex[N];
    for(int i = 0; i < N; i++) vector[i] = other.vector[i];

    return *this;
}

std :: ostream& operator<<(std :: ostream &out, const CComplexVector& v){
    out << "( ";
    for(int i = 0; i < N - 1; i++) out << v.vector[i] << ", ";
    out << v.vector[N - 1];
    out << " )";

    return out;
}
