#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top;

int isEmpty(int *stack){
	if(top == -1)
		return 1;
	else
		return 0;
}

void Push(int *stack, int value){
	top += 1;
	stack[top] = value;
}

int Pop(int *stack){

	if(isEmpty(stack)){
		printf("Stack Underflow \n");
		return -1;
	}
	else{
		int value = stack[top];
		top -= 1;
		return value;
	}
}

void PrintStack(int *stack){
	int i;
	for(i=0; i<= top; i++)
		printf("%d ", stack[i]);
	printf("\n");
}


int main(){
	int n,value;
	top = -1;
	printf("Array Implementation of Stack\n");
	printf("----------------------------------\n");
	printf("Menu\n");
	printf("-------\n");
	printf("PUSH value\n");
	printf("POP\n");
	printf("SHOW\n");
	printf("EXIT\n");
	printf("\n");

	int *stack = (int *)malloc(sizeof(int)*1000);

	char option[5];

	while(1){
		scanf("%s", option);
		if(strcmp(option, "PUSH")==0){
			scanf("%d", &value);
			Push(stack, value);
		}else if(strcmp(option, "POP")==0){
			printf("%d\n", Pop(stack));
		}else if(strcmp(option, "SHOW")==0){
			PrintStack(stack);
		}else if(strcmp(option, "EXIT")==0){
			break;
		}else{
			printf("Invalid Command %s\n", option);
		}
	}
}