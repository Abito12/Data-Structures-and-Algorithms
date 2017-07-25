#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void PrintArray(int *arr, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}



int * CountingSort(int *A, int n, int d){
	int max,i,j;
	int index, div;

	div = pow(10, d-1); 

	//Initialise Count Array
	max = 9;
	int *C = (int *)malloc(sizeof(int) * (max+1));
	for(i=0; i<=max; i++){
		C[i] = 0;
	}

	//Count of each element in arr and store it in C
	for(i=0; i<n; i++){
		index = (A[i]/div) % 10;
		C[index] += 1;
	}

	//Count number of elements less than or equal to element in A
	for(i = 1; i <=max; i++){
		C[i] += C[i-1]; 
	}

	int *B = (int *)malloc(n * sizeof(int));
	for(i=n-1; i>=0; i--){
		index = (A[i]/div) % 10;
		B[C[index]-1] = A[i];
		C[index] -= 1;
	}
	return B;
}


int * RadixSort(int *arr, int n, int d){
	int i;
	int *result;
	result = arr;
	for(int i = 1; i <= d; i++)
		result = CountingSort(result, n, i);

	return result;
}



int main(){
	int n,i,d;
	printf("Enter size of array: ");
	scanf("%d", &n);

	int *arr = (int *)malloc(sizeof(int)*n);

	printf("Enter number of digits: ");
	scanf("%d", &d);
	for(i=0; i<n; i++)
		scanf("%d", arr+i);

	int *result = RadixSort(arr, n, d);
	PrintArray(result, n);
}


