#include <stdio.h>
#include <stdlib.h>

int Parent(int i){
	return i/2;
}

int LeftChild(int i){
	return 2*i+1;
}

int RightChild(int i){
	return 2*i+2;
}


void swap(int *a, int *b){
	int r;
	r = *a;
	*a = *b;
	*b = r;
}

void MaxHeapify(int *arr, int i, int heapsize){
	int left, right, largest;
	left = LeftChild(i);
	right = RightChild(i);
	largest = i;
	if(left < heapsize && arr[left] > arr[largest])
		largest = left;
	if(right < heapsize && arr[right] > arr[largest])
		largest = right;

	//Check if MaxHeap Property is violated
	if(largest != i){
		swap(arr + i, arr + largest);
		MaxHeapify(arr, largest, heapsize);
	}
}

void BuildMaxHeap(int *arr, int n){
	int heapsize = n;
	int mid = n/2;
	int i;
	for(i=mid;i>=0;i--){
		MaxHeapify(arr, i, heapsize);
	}
}

void HeapSort(int *arr, int n){
	int i;
	int heapsize = n;
	BuildMaxHeap(arr, n);
	for(i=n-1;i>=0;i--){
		swap(arr+i, arr);
		heapsize--;
		MaxHeapify(arr, 0, heapsize);
	}
}

int main(){
	int n,i;
	printf("Enter number of elements\n");
	scanf("%d", &n);
	int *arr = malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d", arr+i);
	HeapSort(arr, n);
	printf("Sorted array is :");
	for(i=0;i<n;i++)
		printf("%d ", *(arr+i));
	printf("\n");
	
}