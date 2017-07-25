#include <stdio.h>
#include <stdlib.h>

int swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void PrintArray(int *arr, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int Partition(int *arr, int p, int r){
	int x,i,j;
	x = arr[r];
	i = p - 1;
	for(j=p; j < r; j++){
		if(arr[j] <= x){
			i++;
			if(i!=j)
				swap(arr+i, arr+j);
		}
	}
	swap(arr+i+1, arr+r);

	return i+1;
}


void QuickSort(int *arr, int p, int r){
	if(p < r){
		int q = Partition(arr, p, r);
		QuickSort(arr, p, q - 1);
		QuickSort(arr, q + 1, r);
	}
}


int main(){
	int n, i;
	printf("Enter size of array\n");
	scanf("%d", &n);
	int *arr = (int *)malloc(n * sizeof(int));
	for(i = 0;i < n; i++){
		scanf("%d", arr+i);
	}
	QuickSort(arr, 0, n-1);
	PrintArray(arr, n);
}
