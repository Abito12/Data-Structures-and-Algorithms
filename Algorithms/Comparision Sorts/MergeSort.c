#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void Merge(int *arr, int p, int q, int r){
	int n1,n2,i,j,k;
	n1 = q - p + 1;
	n2 = r - q;
	int *left = (int *)malloc(sizeof(int)*(n1+1));
	int *right = (int *)malloc(sizeof(int)*(n2+1));

	for(i=0;i<n1;i++){
		*(left+i) = *(arr+ p + i );
	}

	for(i=0;i<n2;i++)
		*(right+i) = *(arr+ q+i+1 );

	left[n1] = 999999;
	right[n2] = 999999;

	i = j = 0;

	for(k=p;k<=r;k++){
		if(left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		}else{
			arr[k] = right[j];
			j++;
		}		
	}
}

void MergeSort(int *arr, int p, int r){
	int q;
	if(p<r){
		q = ((p+r)/2);
		MergeSort(arr,p,q);
		MergeSort(arr,q+1,r);
		Merge(arr,p,q,r);
	}
}

int main(){
	int n,i;
	printf("Enter number of elements\n");
	scanf("%d", &n);
	int *arr = malloc(sizeof(int)*(n+1));
	for(i=0;i<n;i++)
		scanf("%d", arr+i);
	arr[n] = 999999;
	MergeSort(arr, 0, n);
	printf("Sorted array is : ");
	for(i=0;i<n;i++)
		printf("%d ", *(arr+i));
	printf("\n");
	
}