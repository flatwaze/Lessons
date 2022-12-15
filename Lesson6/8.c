#include "stdio.h"
#include "stdlib.h"

#define MAX 100

int main(void){
    int num, len, q, isFind;

    int arr[MAX]; /*Сами числа*/
    int count[MAX]; /*на i-ом индексе этого массива написано кол-во элементов*/

    FILE *in;

    len = 0;
    in = fopen("data/input.txt", "r");
    
    /*Будем проверять встречался ли элемент в массиве сразу, если встречался то добавляем, */
    while((q = fscanf(in, "%d", &num)) == 1){
        isFind = -1;
        for(int i = 0; i < len; i++){
            if(arr[i] == num){
                isFind = i;
                break;
            }
        }
        if(isFind == -1){
            arr[len] = num;
            count[len] = 1;
            len++;
        }
        else
            count[isFind]++;
    }
    if(q == 0) return -1;

    for(int i = 0; i < len; i++){
        printf("%d %d\n", arr[i], count[i]);
    }

    return 0;
}
