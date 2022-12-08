#include <iostream>
#include "List.h"

int main(){
    List<int> list;
    list.push_front(1);
    list.push_front(2); 
    list.push_front(3);

    list.pop_front();

    list.push_front(52);
    list.push_back(45);
    list.push_back(57);
    list.pop_back();

    list.insert(1, 556);
    list.erase(2);

    list.front() = 2;

    std :: cout << list.insert(list.begin() + 1, 17) << std :: endl;


    for(int i = 0; i < list.size(); i++)
        std :: cout << list[i] << std :: endl;

    return 0;
}

