#include <stdio.h>
#include <stdlib.h>

void PrintArray(int *arr, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int FindMaxArray(int *arr, int n){
	int max, i;
	max = 0;
	for(i = 0; i < n; i++){
		if(max < arr[i])
			max = arr[i];
	}

	return max;
}

int * CountingSort(int *A, int n){
	int max,i,j;

	//Initialise Count Array
	max = FindMaxArray(A, n);
	int *C = (int *)malloc(sizeof(int) * (max+1));
	for(i=0; i<=max; i++){
		C[i] = 0;
	}

	//Count of each element in arr and store it in C
	for(i=0; i<n; i++){
		C[A[i]] += 1;
	}

	PrintArray(C, max+1);
	//Count number of elements less than or equal to element in A
	for(i = 1; i <=max; i++){
		C[i] += C[i-1]; 
	}
	PrintArray(C, max+1);

	int *B = (int *)malloc(n * sizeof(int));
	for(i=n-1; i>=0; i--){
		B[C[A[i]]-1] = A[i];
		C[A[i]] -= 1;
	}
	return B;
}

int main(){
	int n,i;
	printf("Enter size of array\n");
	scanf("%d", &n);
	int *arr = (int *)malloc(n * sizeof(arr));
	for(i=0; i<n; i++){
		scanf("%d", arr+i);
	}
	PrintArray(CountingSort(arr, n), n);
}