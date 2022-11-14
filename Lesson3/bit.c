#include "headers.h"

int bitCount(int a){
    int count = 0;
    for(int i = 0; i < 32; i++){
        count += (a & 1);
        a >>= 1;
    }

    return count;
}

int binaryPrint(int a, FILE* out){
    int bit;
    for(int i = 0; i < 32; i++){
        if(i%8 == 0 && i != 0) fprintf(out, " ");
        bit = a & (1 << 31);
        if(bit != 0) bit = 1;
        fprintf(out, "%d", bit);
        a <<= 1;
    }


}

void bitSort(int* arr, int len){
    int tmp;
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            if(bitCount(arr[i]) > bitCount(arr[j])){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            else if(bitCount(arr[i]) == bitCount(arr[j]) && arr[i] > arr[j]){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void print(int* arr, int len, FILE* out){
    
    for(int i = 0; i < len; i++){
        fprintf(out, "%d binary: ", arr[i]);
        binaryPrint(arr[i], out);
        fprintf(out, "\n");
    }
}
