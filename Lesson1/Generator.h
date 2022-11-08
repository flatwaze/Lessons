#include <stdlib.h>

/*генератор случайного массива*/
void generator(int* arr, int len) {
	for (int i = 0; i < len; i++)
		arr[i] = rand() % 200 - 99;
}
