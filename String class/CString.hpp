#include <iostream>
#include <fstream>

class CString{
    private:
        char *str;
        int length;

    public:
        CString();
        ~CString(){
            delete[] str;
        }

        CString(char other[]);
        CString(const CString& other);

        int size(){
            return length;
        }

        const CString operator+(const CString& other) const;
        const CString& operator=(const CString& other);
        const CString& operator=(char other[]);

        char& operator[](int i);
        friend std :: ostream& operator<<(std :: ostream &out, const CString& s);
        friend std :: istream& operator>>(std :: istream &out, CString& s);
};
