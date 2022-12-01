#include "CString.cpp"
#include <fstream>

using namespace std;

int main(){
    
    ifstream in("input.txt");
    ofstream out("output.txt");

    char string[LEN];
    in >> string;
    CString str1(string);
    out << "The first string is: " << str1 << endl;

    in >> string;
    CString str2(string);
    out << "The second string is: " << str2 << endl;

    CString str3;
    str3 = str1 + str2;
    out << "The first + second is: " << str3 << endl;

    CString str4(str3);
    out << "The copy of the previous concantenation is: " << str4 << endl << 
    "The size of the it is: " << str4.size() << endl;

    return 0;
}
