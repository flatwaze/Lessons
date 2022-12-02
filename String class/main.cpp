#include "CString.cpp"
#include <fstream>

using namespace std;

int main(){
    
    char string1[] = "Hello, ";
    char string2[] = "world!";

    CString str1(string1), str2, str3;
    str2 = string2;
    str3 = str1 + str2;

    cout << "The first string is: " << str1 << endl
    << "The second is: " << str2 << endl
    << "The third is: " << str3 << " length is: " << str3.size() << endl; 

    char string3[] = "The string with new length...";

    str3 = string3;


    cout << "The third has been changed: " << str3 << 
    " length is: " << str3.size() << endl;


    return 0;
}
