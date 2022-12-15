#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int binaryFind(int num, int *arr, int len){
    int left = 0;
    int right = len - 1;
    int ans; /*заметим, что ans в точности ответ.*/

    while(left < right){
        ans = (left + right)/2;
        if(arr[ans] < num){
            left = ans + 1;
        }
        else if(arr[ans] > num){
            right = ans - 1;
        }
        else
            break;
    }

    return ans;
}

/*Оптимизированный метод под добавления*/
int binaryInsert(int num, int *arr, int len){
    int left = 0;
    int right = len - 1;
    int ans; /*заметим, что ans в точности ответ.*/
    
    while(left <= right){
        ans = (left + right)/2;
        printf("The ans is %d\n", ans);
        if(arr[ans] < num){
            left = ans + 1;
        }
        else if(arr[ans] > num){
            right = ans - 1;
        }
        else
            break;
    }

    /*Если num не равен никакому элементу из массива, 
    то надо понять куда мы его можем вставить*/

    /*Почему вот тут не будет выхода за границу и почему это действительно так*/
    if(left > right){
        ans = left;
    }

    /*Так как элементов в массиве меньше 100 по условию, 
    то мы можем сдвинуть все элементы на 1 позицию вправо, начиная с arr[ans]*/
    for(int i = len; i > ans; i--)
        arr[i] = arr[i - 1];

    arr[ans] = num;

    return ans;
}

int main(void){
    int num, len, q;
    int arr[MAX];
    FILE *in;

    len = 0;
    in = fopen("data/input.txt", "r");
    
    while((q = fscanf(in, "%d", &num)) == 1){
        arr[len] = num;
        len++;
    }
    if(q == 0) return -1;

    printf("Enter number: ");
    scanf("%d", &num);

    printf("index: %d\n", binaryInsert(num, arr, len));

    for(int i = 0; i < len + 1; i++) printf("%d ", arr[i]);

    return 0;
}
