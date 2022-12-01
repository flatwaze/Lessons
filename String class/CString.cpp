#include "CString.hpp"

char& CString :: operator[](int i){
    return str[i];
}

CString :: CString(){
    str = new char[LEN];
    length = 0;

    str[length] = '\0';
}

CString :: CString(char other[]){
    str = new char[LEN];
    length = 0;

    while(other[length] != '\0'){
        str[length] = other[length];
        length++;
    }

    str[length] = '\0';
}

CString :: CString(const CString& other){
    length = other.length;
    for(int i = 0; i < other.length; i++){
        str[i] = other.str[i];
    }

    str[length] = '\0';
}

std :: ostream& operator<<(std :: ostream &out, const CString& s){
    out << s.str;
    return out;
}

std :: istream& operator>>(std :: istream &in, CString& s){
    in >> s.str;
    s.length = 0;

    while(s.str[s.length] != '\0')
        s.length++;
    
    return in;
}

const CString CString :: operator+(const CString& other) const{
    CString ans;

    ans.length = length + other.length;

    for(int i = 0; i < length; i++) ans[i] = str[i];
    for(int i = 0; i < other.length; i++) ans[length + i] = other.str[i];
    ans[length + other.length] = '\0';

    return ans;
}

const CString& CString :: operator=(const CString& other){
    length = other.length;
    for(int i = 0; i < other.length; i++){
        str[i] = other.str[i];
    }

    str[length] = '\0';

    return *this;
}
