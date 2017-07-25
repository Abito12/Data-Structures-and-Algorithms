#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct for the Queue
struct Node{
	int value;
	struct Node *next;
};

//Struct for the Breadth First Tree
struct TNode{
	int data;
	struct TNode *left;
	struct TNode *right;
	struct Tnode *parent;
};

struct TNode *root;



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

