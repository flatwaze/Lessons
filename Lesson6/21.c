#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main(void){
    int num, len, q, count, tmp;
    int arr[MAX];
    FILE *in;

    in = fopen("data/input.txt", "r");
    len = 0;

    while((q = fscanf(in, "%d", &num)) == 1){
        arr[len] = num;
        len++;
    }
    if(q == 0) return -1;

    /*Возможно можно без count*/
    count = 0;
    for(int i = len - 1; i >= 0; i--){
        if(i%2 == 1){
            for(int j = i; j < len - count - 1; j++){
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
            count++;
        }
    }
    
    for(int i = 0; i < len; i++) printf("%d ", arr[i]);

    return 0;
}
