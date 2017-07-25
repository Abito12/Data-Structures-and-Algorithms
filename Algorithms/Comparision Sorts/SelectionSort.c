#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void SelectionSort(int *arr, int n){
	int i,j,min_index;
	for(i=0 ;i<n ;i++){
		min_index = i;
		for(j=i+1;j<n;j++){
			if(*(arr + j) < *(arr + min_index))
				min_index = j;
		}
		if(min_index!=i)
			swap(arr+i,arr+min_index);
	}
}

int main(){
	int n,i;
	printf("Enter number of elements\n");
	scanf("%d", &n);
	int *arr = malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d", arr+i);
	SelectionSort(arr, n);
	printf("Sorted array is :");
	for(i=0;i<n;i++)
		printf("%d ", *(arr+i));
	printf("\n");
	
}