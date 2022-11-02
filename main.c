#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Sort.h"
#include "Generator.h"

#define LEN 10

/*Рекурсивной называется функция, которая вызывает сама себя
Самое главное в создании рекурсивной функции - проработать правило выхода из рекурсии,
ведь если функция будет бесконечно раз вызывать сама себя, то программа будет исполняться 
бесконечно.
*/

/*немного сложный алгоритм на языке указателей, стоит помнить,
что массив задается указателем на свою первую ячейку. 
С реализацией разберемся позже.
*/

int main(void) {
    int arr[LEN];

    char filename[128];
    clock_t start, stop;

    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *out = fopen(filename, "w");
    
    generator(arr, LEN);

    fprintf(out, "The array was generated:\n");
    for(int i = 0; i < LEN; i++) fprintf(out, "%d ", arr[i]);
    fprintf(out, "\n");

    start = clock();
    mergeSort(arr, 0, LEN - 1);
    stop = clock();

    double dur = (double)(stop - start) / CLOCKS_PER_SEC;

    fprintf(out, "The array was sorted by %lf sec:\n", dur);
    for(int i = 0; i < LEN; i++) fprintf(out, "%d ", arr[i]);

    return 0;
}
