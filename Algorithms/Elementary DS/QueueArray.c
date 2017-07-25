#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int head, tail, n;

int isEmpty(int *queue){
	if(head == tail)
		return 1;
	else
		return 0;
}

void Enqueue(int *queue, int value){
	queue[tail] = value;
	if(tail == n - 1){
		tail = 0;
	}else
		tail += 1;
}

void Dequeue(int *queue){
	int value = queue[head];
	if(head = n -1){
		head = 0;
	}else
	 	head += 1;

	 return value;
}

void PrintQueue(int *queue){
	int i;
	for(i = head; i <= tail; i++)
}