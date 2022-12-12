/*Циклический сдвиг массива*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void reverse(int* array, int len){
    int tmp;
    for(int i = 0; i < len/2; i++){
        tmp = array[i];
        array[i] = array[len - i - 1];
        array[len - i - 1] = tmp;
    }
}

int main(void){
    int len, shift, num, q;
    int arr[MAX];
    FILE *in, *out;

    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    len = 0;

    while((q = fscanf(in, "%d", &num)) == 1){
        arr[len] = num;
        len++;
    }
    if(q == 0) return -1; /*Invalid data*/

    printf("Enter the shift count: ");
    scanf("%d", &shift);

    reverse(arr, len - shift);
    reverse(arr + len - shift, shift);
    reverse(arr, len);

    for(int i = 0; i < len; i++) fprintf(out, "%d", arr[i]);

    return 0;
}
