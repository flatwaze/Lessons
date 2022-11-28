#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define LEN 256


void conc(char *str1, char *str2, int len1, int len2);
int isFind(char *str1, char *str2, int len1, int len2);

int main(void){
    char str1[LEN];
    char str2[LEN]; 

    char tmp;
    int count1 = 0, count2 = 0;

    FILE *strin = fopen("string.txt", "r");
    FILE *in = fopen("input.txt", "r");
    
    if(strin != NULL && in != NULL){

        while(fscanf(in, "%c", &tmp) == 1){
            str1[count1] = tmp;
            ++count1;
        }

        str1[count1] = '\0';

        while(fscanf(strin, "%c", &tmp) == 1){
            str2[count2] = tmp;
            
            ++count2;
        }

        str2[count2] = '\0';
        
        
        printf("%d", isFind(str1, str2, count1, count2));
    }

    return 0;
}

void conc(char *str1, char *str2, int len1, int len2){
    for(int i = 0; i < len2; i++){
        str1[len1 + i] = str2[i];
    }

    str1[len1 + len2] = '\0';
}

int isFind(char *str1, char *str2, int len1, int len2){
    int j = 0;
    for(int i = 0; i < len1; i++){
        if(str1[i] == str2[j]) j++;
        else if(str1[i] != str2[j]) j = 0;

        if(j == len2) return i - j;
    }

    return -1;
}
