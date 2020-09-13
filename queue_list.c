#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
}*front=NULL,*rear=NULL;

int isEmpty(){
	if(!front)
		return 1;
	return 0;
}

int isFull(){
	struct Node *t=(struct Node *)malloc(sizeof(struct Node));
	if(!t)
		return 1;
	free(t);
	return 0;
}

void enqueue(int x){ 
	if(isFull()){ 
		printf("Queue is Full");
	}else{ 
			struct Node *t=(struct Node *)malloc(sizeof(struct Node));
			t->data=x;
			t->next=NULL;
		if(isEmpty()){
			front=t;
			rear=t;
		}else{ 
			rear->next=t;
			rear=t;
		}	
	}
}

int dequeue(){
	int x=-1;
	if(isEmpty())
		printf("Queue is Empty");
	else{
		struct Node *p=front;
		front=front->next;
		x=p->data;
		free(p); 
	} 
	return x;
}

void display(){
	struct Node *p=front;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	} 
}

int main(){

	enqueue(10);
	printf("%d is deleted\n", dequeue());
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	display();

	return 0;
}
