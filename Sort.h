void indexSort(int* arr, int* ind, int len) {
	for (int i = 0; i < len; i++) ind[i] = i;

	int tmp;
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {

            
			if (arr[ind[i]] > arr[ind[j]]) {
				tmp = ind[i];
				ind[i] = ind[j];
				ind[j] = tmp;
			}

            printf("arr[ind[j]]: %d, arr[j]: %d\n", arr[ind[j]], arr[j]);
		}
	}
}

void printBound(int* arr, int left, int right){
    printf("-----\n");
    for(int i = left; i <= right; i++) printf("%d ", arr[i]);
    printf("\n");
}

/*right - left + 1*/

void merge(int* arr, int left, int right){
    int i, j, k, mid, n1, n2;

    mid = (left + right - 1)/2;

    n1 = mid - left + 1;
    n2 = right - mid;

    int* L = (int*)malloc(sizeof(int) * n1);
    int* R = (int*)malloc(sizeof(int) * n2);

    for (i = 0; i < n1; i++) L[i] = arr[left + i];
	for (i = 0; i < n2; i++) R[i] = arr[mid + 1 + i]; 


    i = 0; j = 0; k = left;
    
    
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

    while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

    free(L); free(R);
}

void mergeSort(int* arr, int left, int right){
    printBound(arr, left, right);
    int mid = (left + right - 1)/2;
    if(left < right){
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, right);
    }
}


