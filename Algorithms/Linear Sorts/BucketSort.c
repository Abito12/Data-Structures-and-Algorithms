#include <stdio.h>a
#include <stdlib.h>

struct Node{
	int key;
	struct Node *next;
};


void InsertionSort(struct Node *head, int n){
	int key;

	struct Node *i, *j;

	i = head;

	while(i!=NULL){
		key = i->key;
		j

	}



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


struct Node * appendToList(struct Node * node, int val){
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->key = val;
	temp->next = NULL;

	//Append Node to the list
	if(node->next == NULL{
		node->next = temp;
	}else{
		struct Node *iter = node->next;
		while(iter->next!=NULL){
			iter = iter->next;
		}
		iter->next = temp;
	}

	return node;
}


int * BucketSort(int *arr,int n){
	int i,index;
	struct Node *Bucket = (struct Node *)malloc(sizeof(struct Node) * 10);
	for(i = 0; i < 10; i++){
		Bucket[i].key = 0;
		Bucket[i].next = NULL;
	}

	for(i=0; i<n; i++){
		index = arr[i]*n;
		Bucket[i].key += 1;
		Bucket[index].next = appendToList(Bucket[index], arr[i]);
	}

	for(i=0;i<10;i++){
		InsertionSort(Bucket[i].next, Bucket[i].key);
	}

}


int main(){
	BucketSort();
}