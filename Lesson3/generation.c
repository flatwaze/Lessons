#include "headers.h"

void generate(int* arr, int len){
    
    for(int i = 0; i < len; i++){
        arr[i] = rand() %  201 - 100;
    }
}
