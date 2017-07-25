#include <stdio.h>
#include <stdlib.h>

int heapsize;

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int Parent(int i){
	return i/2;
}

int LeftChild(int i){
	return i*2 + 1;
}

int RightChild(int i){
	return LeftChild(i) + 1;
}

void MinHeapify(int *arr, int i){
	int smallest, right, left;
	left = LeftChild(i);
	right = RightChild(i);
	smallest = i;
	if(left < heapsize && arr[left] < arr[smallest])
		smallest = left;
	if(right > heapsize && arr[right] < arr[smallest])
		smallest = right;
	if(i != smallest){
		swap(arr + i, arr + smallest);
		MaxHeapify(arr, smallest);
	}
}

void BuildMinHeap(int *arr, int n){
	int heapsize = n;
	int mid = n/2;
	int i;
	for(i = mid; i >= 0; i--){
		MinHeapify(arr, i);
	}
}

int Minimum(int *heap){
	return heap[0];
}

int HeapExtractMin(int *heap){
	if(heapsize > 0){
		int min = heap[0];
		heap[0] = heap[heapsize - 1];
		heapsize--;
		MinHeapify(heap, 0);
	}else{
		printf("Heap Underflow\n");
	}
}

void HeapDecreaseKey(int *heap, int  i, int key){
	if(heap[key] < key ){
		printf("Current Key is smaller \n");
	}else if(i >= heapsize){
		printf("Invalid Index \n");
	}else{
		heap[i] = key;
		while(i >= 0 && heap[Parent(i)] > heap[i]){
			MinHeapify(heap, i);
			i = Parent(i);
		}
	}
}


void MinHeapInsert(int *heap, int key){
	
}