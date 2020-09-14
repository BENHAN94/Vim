#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next; 
}*s1=NULL,*s2=NULL;

int isEmpty(struct Node *p){
	return p?0:1;
}

int isFull(){
	struct Node *t=(struct Node *)malloc(sizeof(struct Node));
	int r=t?0:1;
	free(t);
	return r;
}

void push(struct Node **p,int x){
	struct Node *t=(struct Node *)malloc(sizeof(struct Node));
	if(t==NULL){
		printf("Stack Overflow");
	}else{
		t->data=x;
		t->next=*p;
		*p=t;
	} 
}

int pop(struct Node **p){ 
	int x=-1;
	struct Node *tmp=*p; 
	if(isEmpty(*p)){
		printf("Stack Underflow\n");
		return x;
	} 
	*p=(*p)->next; 
	x=tmp->data;
	free(tmp);
	return x; 
}

int peek(struct Node *p,int pos){
	int i;
	for(i=0;p&&i<pos-1;i++){
		p=p->next;
	}
	if(p)
		return p->data;
	else
		return -1;
}

int stackTop(struct Node *p){
	if(p)
		return p->data;
	return -1;
}

void enqueue(int x){
	if(isFull()) 
		printf("Stack is Full\n");
	else{ 
		push(&s1,x);
	} 
}

int dequeue(){
	int x=-1;
	if(isEmpty(s2)){
		if(isEmpty(s1))
			printf("Queue is Empty\n");
		else{
		while(!isEmpty(s1)){
			push(&s2,pop(&s1));
		}
		x=pop(&s2);
		}
	}else{
		x=pop(&s2);
	}
	return x;
}


int main(){

	enqueue(1);
	enqueue(2);
	enqueue(3); 
	printf("%d is the top of s1\n",stackTop(s1));
	printf("%d is deleted from s2\n",dequeue()); 
	printf("%d is deleted from s2\n",dequeue()); 
	printf("%d is deleted from s2\n",dequeue()); 
	printf("%d is deleted from s2\n",dequeue()); 
	return 0;
}
