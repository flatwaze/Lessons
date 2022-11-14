#include "headers.h"
#include "bit.c"
#include "generation.c"

int main(void){
    int arr[LEN];
    char filename[128];
    FILE* out;
    
    printf("Input filename: ");
    scanf("%s", filename);
    out = fopen(filename, "w");

    generate(arr, LEN);

    fprintf(out, "The Array is: \n");
    print(arr, LEN, out);
    fprintf(out, "\n");

    fprintf(out, "The Sorted Array is: \n");
    bitSort(arr, LEN);
    print(arr, LEN, out);
    
    return 0;
}
