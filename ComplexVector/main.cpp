#include <iostream>
#define N 2

#include "CComplex.cpp"
#include "CComplexVector.cpp"

int main(){  
    CComplex arr1[N];
    arr1[0] = CComplex(1, 1);
    arr1[1] = CComplex(2, 2);
    CComplexVector vec1(arr1);
    
    CComplex arr2[N];
    arr2[0] = CComplex(1, -1);
    arr2[1] = CComplex(-2.5, 2);
    CComplexVector vec2(arr2);

    std :: cout << vec1 << "\n";
    std :: cout << vec2 << "\n";

    CComplexVector vec3 = vec1 + vec2;
    CComplexVector vec4 = vec1 - vec2;
    CComplexVector vec5 = vec1 * vec2;

    std :: cout << vec3 << "\n" << vec4 << "\n" << vec5 << "\n";

    return 0;
}
