#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *head;

struct Node *insertNode(int data){
	if(head==NULL){
		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
		newNode->data = data;
		newNode->next = NULL;
		head = newNode;
	}
	else{
		struct Node *iter = head;
		while(iter->next!=NULL)
			iter=iter->next;
		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
		newNode->data = data;
		newNode->next = NULL;
		iter->next = newNode;
	}
	return head;
}

struct Node *ReverseList(struct Node *head){
	struct Node *temp = head;
	struct Node *temp2 = head;
	if((temp->next)->next==NULL){
		head = temp->next;
		head->next = temp;
		return temp;
	}else{
		ReverseList(temp->next)->next = temp;
	}
	return head;
}


int main(){
	int n,data;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%d", &data);
		insertNode(data);
	}

	struct Node *iter = ReverseList(head);
	while(iter!=NULL){
		printf("%d \n", iter->data);
		iter = iter->next;
	}
	return 1;

}