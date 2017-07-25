#include <stdio.h>
#include <stdlib.h>

struct Node{
	int left;
	int right;
	int max;
};

struct Node *FindMaxCrossingSubArray(int *arr, int low, int mid, int high){
	int leftSum = -99999;
	int rightSum = -99999;
	int sum = 0;
	int i,leftMax,rightMax;

	//Left Subarray
	for(i = mid; i >= low; i--){
		sum += arr[i];
		if(sum > leftSum){
			leftSum = sum;
			leftMax = i;
		}
	}
	sum = 0;
	//Right Subarray
	for(i = mid+1;i <= high; i++){
		sum += arr[i];
		if(sum > rightSum){
			rightSum = sum;
			rightMax = i;
		}
	}

	//A struct to hold all return values
	struct Node *result = (struct Node *)malloc(sizeof(struct Node));
	result->left = leftMax;
	result->right = rightMax;
	result->max = leftSum + rightSum;

	return result;
}

struct Node *FindMaxSubArray(int *arr, int low, int high){
	int mid;
	if(high == low){
		struct Node *result = (struct Node *)malloc(sizeof(struct Node));
		result->left = low;
		result->right = high;
		result->max = arr[low];
		return result;
	}else{
		mid = (low + high)/2;
		struct Node *leftMax =  FindMaxSubArray(arr, low, mid);
		struct Node *rightMax = FindMaxSubArray(arr, mid+1, high);
		struct Node *crossMax = FindMaxCrossingSubArray(arr, low, mid, high);
		if(leftMax->max >= rightMax->max && leftMax->max >= crossMax->max)
			return leftMax;
		else if(rightMax->max >= leftMax->max && rightMax->max >= crossMax->max)
			return rightMax;
		else
			return crossMax;

	}
}

int main(){
	int n,i;
	printf("Enter number of elements\n");
	scanf("%d", &n);
	int *arr = malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d", arr+i);
	struct Node *result = FindMaxSubArray(arr, 0, n-1);
	printf("%d %d %d\n", result->left, result->right, result->max);
}