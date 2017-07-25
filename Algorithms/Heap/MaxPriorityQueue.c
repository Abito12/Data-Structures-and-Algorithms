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
	return 2*i+1;
}

int RightChild(int i){
	return 2*i+2;
}


void MaxHeapify(int *arr, int i){
	int right,left,largest;
	left = LeftChild(i);
	right = RightChild(i);
	largest = i;
	if(left < heapsize && arr[left] > arr[largest])
		largest = left;
	if(right < heapsize && arr[right] > arr[largest])
		largest = right;
	if(largest != i){
		swap(arr+i, arr + largest);
		MaxHeapify(arr, largest);
	}
}

void BuildMaxHeap(int *arr, int n){
	int heapsize = n;
	int mid = n/2;
	int i;
	for(i=mid;i>=0;i--){
		MaxHeapify(arr, i);
	}
}


int Maximum(int *heap){
	return heap[0];
}

int HeapExtractMax(int *heap){
	if(heapsize < 1){
		printf("Heap Underflow\n");
		return 0;
	}else{
		int max = heap[0];
		heap[0] = heap[heapsize-1];
		heapsize--;
		MaxHeapify(heap, 0);
		return max;
	}
}


void HeapIncreaseKey(int *heap, int i, int key){
	if(heap[i] > key){
		printf("New key is smaller than current key\n");
		return;
	}else if(i > heapsize-1){
		printf("Invalid Index\n");
		return;
	}else{
		heap[i] = key;
		while(i > 0 && heap[Parent(i)] < heap[i]){
			swap(heap + Parent(i), heap + i);
			i = Parent(i);
		}
	}
}

void MaxHeapInsert(int *heap, int key){
	heapsize++;
	heap[heapsize-1] = -999999;
	HeapIncreaseKey(heap, heapsize-1, key);
}

void PrintHeap(int *arr){
	int i;
	for(i=0;i<heapsize;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}



int main(){
	int n,i;
	printf("Enter the size of the array\n");
	scanf("%d", &n);
	int *arr = malloc(sizeof(int) * 10240);
	for(i=0;i<n;i++)
		scanf("%d", arr+i);
	heapsize = n;
	BuildMaxHeap(arr, n);
	printf("Max Heap: ");
	PrintHeap(arr);

	//Menu
	int option, choice, key, index;
	while(1){
		printf("\nOptions\n");
		printf("1. Maximum\n");
		printf("2. HeapExtractMax\n");
		printf("3. MaxHeapInsert\n");
		printf("4. HeapIncreaseKey\n");
		printf("5. Exit\n");
		printf("Enter your option\n");
		scanf("%d", &option);
		switch(option){
			case 1:
				printf("Maximum : %d\n", Maximum(arr));
				printf("____________________________________\n");
				break;
			case 2:
				printf("%d\n", HeapExtractMax(arr));
				PrintHeap(arr);
				printf("____________________________________\n");
				break;
			case 3:

				printf("Enter the value to insert\n");
				scanf("%d", &key);
				MaxHeapInsert(arr, key);
				PrintHeap(arr);
				printf("____________________________________\n");
				break;
			case 4:
				printf("Enter index \n");
				scanf("%d", &index);
				printf("Enter the new value\n");
				scanf("%d", &key);
				HeapIncreaseKey(arr, index, key);
				PrintHeap(arr);
				printf("____________________________________\n");
				break;
			case 5:
				exit(1);
			default:
				printf("Enter a valid choice\n");
				break;
		}
	}
	return 0;
}






































