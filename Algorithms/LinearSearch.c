
#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *arr,int n, int key){
	int i;
	for(i=0;i<n;i++){
		if(*(arr+i)==key)
			return i;
	}
	return -1;
}

int main(){
	int n,key,result;
	printf("Enter size of array: ");
	scanf("%d", &n);
	int *ptr = (int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d", ptr+i);
	}
	printf("Enter the key to search: ");
	scanf("%d", &key);
	result = linearSearch(ptr,n,key);
	if(result>=0)
		printf("Found at position: %d\n", result);
	else
		printf("Not Found\n");
}