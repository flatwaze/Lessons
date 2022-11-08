#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void) {
	int Data[7] = {20, 35, 41, 10, 37, 12, 12};
	struct node* root = NULL;
	for (int i = 0; i < 7; i++) {
		root = addToTree(root, Data[i]);
	}
	printTree(root);
	return 0;
}
