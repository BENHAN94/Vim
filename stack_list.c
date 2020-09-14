#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next; 
}*top=NULL;

int isEmpty(){
	return top?0:1;
}

int isFull(){
	struct Node *t=(struct Node *)malloc(sizeof(struct Node));
	int r=t?1:0;
	free(t);
	return r;
}

void push(int x){
	struct Node *t=(struct Node *)malloc(sizeof(struct Node));
	if(t==NULL){
		printf("Stack Overflow");
	}else{
		t->data=x;
		t->next=top;
		top=t;
	} 
}

int pop(){
	
	int x=-1;
	struct Node *tmp=top;

	if(isEmpty()){
		printf("Stack Underflow");
		return x;
	}
	top=top->next;
	x=tmp->data;
	free(tmp);
	return x;

}

int peek(int pos){
	int i;
	struct Node *p=top;
	for(i=0;p&&i<pos-1;i++){
		p=p->next;
	}
	if(p)
		return p->data;
	else
		return -1;
}

int stackTop(){
	if(top)
		return top->data;
	return -1;
}

int main(){

	push(8);
	
	printf("%d ",stackTop());


	return 0;
}
