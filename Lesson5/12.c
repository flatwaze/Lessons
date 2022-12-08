#include "stdio.h"
#include "stdlib.h"

#define MAX_LEN 100

int main(void){
    double arr[MAX_LEN];
    double n, sum;
    int q, len = 0; /*Вспомогательная 
    переменная для проверки успешности ввода*/
    FILE *in = fopen("input.txt", "r");

    if(in != NULL){

        while((q = fscanf(in, "%lf", &n)) == 1){
            arr[len] = n;
            len++;
        }
        if(q == 0) return -1;

        printf("%lf ", arr[0]);
        for(int i = 1; i < len; i++){
            arr[i] += arr[i - 1];
            printf("%lf ", arr[i]);
        }

    }
    else return -1;


    return 0;
}
