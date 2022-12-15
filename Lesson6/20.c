#include "stdio.h"
#include "stdlib.h"

#define MAX 100

/*Подсказка вспомнить функцию merge*/
/*a & b - неубывающие массивы*/

void merge(int *a, int *b, int lena, int lenb, int *c){
    int i = 0, j = 0, k = 0;

    while(i < lena && j < lenb){
        if(a[i] <= b[j]){
            c[k] = a[i];
            i++;
        }
        else{
            c[k] = b[j];
            j++;
        }
        k++;
    }

    /*Один из массивов еще не полностью записан в С, другой полностью, 
    из двух while снизу вызовется только один*/
    while(i < lena){
        c[k] = a[i];
        i++;
        k++;
    }

    while(j < lenb){
        c[k] = b[j];
        j++;
        k++;
    }
}

int main(void){
    int num, lena, lenb, lenc, q;
    int a[MAX], b[MAX], c[MAX];
    FILE *ina, *inb;

    lena = 0; lenb = 0;
    ina = fopen("data/a.txt", "r");
    inb = fopen("data/b.txt", "r");

    while((q = fscanf(ina, "%d", &num)) == 1){
        a[lena] = num;
        lena++;
    }
    if(q == 0) return -1;

    while((q = fscanf(inb, "%d", &num)) == 1){
        b[lenb] = num;
        lenb++;
    }
    if(q == 0) return -1;

    merge(a, b, lena, lenb, c);

    lenc = lena + lenb;

    for(int i = 0; i < lenc; i++) printf("%d ", c[i]);

    return 0;
}
