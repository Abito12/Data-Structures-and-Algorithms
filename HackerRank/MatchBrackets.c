#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	char *symbol;
	struct Node *next;
};

struct Node *Push(struct Node *head, char *symbol){
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->symbol = symbol;
	newNode->next = NULL;
	if(head == NULL){
		head = newNode;
	}else{
		struct Node *iter = head;
		while(iter->next!= NULL){
			iter = iter->next;
		}
		iter->next = newNode;
	}
	return head;
}

char *Pop(struct Node *head){
	char *symbol;
	if(head == NULL)
		return NULL;
	else if(head->next == NULL){
		symbol = head->symbol;
		head = NULL;
	}
	else{
		struct Node *iter = head;
		while((iter->next)->next != NULL){
			iter = iter->next;
		}

		symbol = (iter->next)->symbol;
		iter->next = NULL;
		return symbol;
	}
}

int main(){
	int i;
	struct Node *head;
	char *symbols = malloc(10240 * sizeof(char));
	scanf("%s", symbols);
	i = 0;
	int flag = 0;
	while(i < strlen(symbols)){
		if(strcmp(&symbols[i], "(") || strcmp(&symbols[i], "{") || strcmp(&symbols[i], "[")){
			head = Push(head, &symbols[i]);
		}else{
			if(strcmp(&symbols[i], ")")==0){
				if(strcmp(Pop(head), "(")){
					flag++;
				}else if(strcmp(&symbols[i],"}")==0){
					if(strcmp(Pop(head), "{")){
						flag++;
					}
				}else{
					if(strcmp(Pop(head),"]"))
						flag++;
				}
			}
		}
	}

	if(flag == 0 && head==NULL)
		printf("TRUE\n");
	else
		printf("FALSE\n");

	return 1;
}
