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
    int mid = (left + right - 1)/2;
    if(left < right){
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, right);
    }
}


