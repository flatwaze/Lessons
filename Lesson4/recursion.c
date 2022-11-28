#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

/*1, 1, 2, 3, 5, 8, 13, ...
  0  1  2  3  4  5  6

    a(0) = 1;
    a(1) = 1;
    ...
    a(n) = a(n - 1) + a(n - 2) = a(n - 2) + a(n - 3)

*/
int fib(int n, int* arr);
int fib_cycle(int n);

int main(void){
    int n;

    printf("Enter num: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(sizeof(int) * (n + 1));

    fib(n, arr);

    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    

    printf("%d", fib(n, arr));
    return 0;
}

int fib(int n, int *arr){
    if(n == 0 || n == 1){
        arr[0] = 1;
        arr[n] = 1;
    }
    else 
        arr[n] = fib(n - 1, arr) + fib(n - 2, arr);

    return arr[n];
}

