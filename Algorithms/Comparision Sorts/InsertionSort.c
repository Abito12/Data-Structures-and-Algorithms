#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *arr,int n){
	int i,j,key;
	for(i=0;i<n;i++){
		key = *(arr + i);
		j = i - 1;
		while(j>=0 && *(arr+j)>key){
			*(arr+j+1) = *(arr+j);
			j--;
		}
		*(arr+j+1) = key;
	}
}

int main(){
	int n,i,j;
	printf("Enter the size of the array: \n");
	scanf("%d",&n);
	int *ptr = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d", ptr+i);
	}
	insertionSort(ptr,n);
	printf("Sorted array: ");
	for(i=0;i<n;i++){
		printf("%d ", *(ptr + i));
	}
	printf("\n");
	return 0;
}