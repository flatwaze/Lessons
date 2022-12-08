#include "stdio.h"
#include "stdlib.h"

#include "sort.c"

int main(void){
    char filename[128];
    int len_a, len_b, q;
    double *a, *b;
    double num;
    FILE *in;

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter the length of array A: ");
    scanf("%d", len_a);

    printf("Enter the length of array B: ");
    scanf("%d", len_a);

    in = fopen(filename, "r");
    if(in == NULL) return -1;

    a = (double*)malloc(sizeof(double) * len_a);
    b = (double*)malloc(sizeof(double) * len_b);
    for(int i = 0; i < len_a; i++) fscanf(in, "%lf", &a[i]);
    for(int i = 0; i < len_b; i++) fscanf(in, "%lf", &b[i]);

    mergeSort(a, 0, len_a - 1);
    mergeSort(b, 0, len_b - 1);

    int ans = 1;
    for(int i = 0; i < len_a; i++){
        if(i == 0 || a[i] != a[i - 1]){
            if(binarySearch(a[i], b, len_b) == 0){
                ans = 0;
                break;
            }
        }
    }

    printf("%d", ans);

    return 0;
}
