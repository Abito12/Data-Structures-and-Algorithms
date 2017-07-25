#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	int value;
	struct Node *next;
};

struct Node *head, *tail;

void Enqueue(int value){
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));
	new->value = value;
	if(head == NULL){
		new->next = NULL;
		head = new;
		tail = new;
	}else{
		tail->next = new;
		tail = new;
		tail->next = NULL;
	}

}

int Dequeue(){

	int ret = -1;
	if(head!=NULL){
		ret = head->value;
		head = head->next;
	}
	return ret;
}

void PrintQueue(){
	if(head!=NULL){
		struct Node *iter = head;
		while(iter){
			printf("%d ", iter->value);
			iter = iter->next;
		}
		printf("\n");
	}
}


int main(){
	int value;

	printf("Linked List Implementation of Queue\n");
	printf("----------------------------------\n");
	printf("Menu\n");
	printf("-------\n");
	printf("ENQUEUE value\n");
	printf("DEQUEUE\n");
	printf("SHOW\n");
	printf("EXIT\n");
	printf("\n");

	int *stack = (int *)malloc(sizeof(int)*1000);

	char option[10];

	while(1){
		scanf("%s", option);
		if(strcmp(option, "ENQUEUE")==0){
			scanf("%d", &value);
			Enqueue(value);
		}else if(strcmp(option, "DEQUEUE")==0){
			printf("%d\n", Dequeue());
		}else if(strcmp(option, "SHOW")==0){
			PrintQueue();
		}else if(strcmp(option, "EXIT")==0){
			break;
		}else{
			printf("Invalid Command %s\n", option);
		}
	}
}