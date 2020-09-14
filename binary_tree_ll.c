#include <stdio.h>
#include <stdlib.h>

struct treeNode {
	int data;
	struct treeNode *leftChild;
	struct treeNode *rightChild; 
}*root=NULL;

struct QueueNode{
	struct treeNode *tree;
	struct QueueNode *next;
}*front=NULL,*rear=NULL;

int isFull(){
	struct QueueNode *t=(struct QueueNode *)malloc(sizeof(struct QueueNode));
	if(!t)
		return 1;
	return 0;
}

int isEmpty(){
	if(front==NULL)
		return 1;
	return 0;
}

void enqueue(struct treeNode *p){
	if(isFull())
		printf("Queue is Full\n");
	struct QueueNode *t=(struct QueueNode *)malloc(sizeof(struct QueueNode));
	t->tree=p; 
	t->next=NULL;
	if(!front)
		front=rear=t; 
	else{
		rear->next=t;
		rear=t;
	}
}

struct treeNode *dequeue(){
	struct treeNode *p=NULL;
	struct QueueNode *q;
	if(isEmpty())
		printf("Queue is Empty\n");
	else{ 
		p=front->tree;
		q=front;
		front=front->next; 
		free(q);
	}
	return p;
}
 
void create(){ 
	struct treeNode *p,*t;
	int x;
	printf("Enter root value\n");
	scanf("%d",&x);
	root=(struct treeNode *)malloc(sizeof(struct treeNode));
	root->data=x;
	root->leftChild=root->rightChild=0;
	enqueue(root); 
	while(!isEmpty()){ 
		p=dequeue();
		printf("Enter Left Child\n");
		scanf("%d",&x);
		if(x!=-1){
			t=(struct treeNode *)malloc(sizeof(struct treeNode));
			t->data=x;
			p->leftChild=t;
			enqueue(t);
		}else
			p->leftChild=NULL; 
		printf("Enter Right Child\n");
		scanf("%d",&x);
		if(x!=-1){
			t=(struct treeNode *)malloc(sizeof(struct treeNode));
			t->data=x;
			p->rightChild=t;
			enqueue(t);
		}else
			p->rightChild=NULL; 
	}
}

int main(){

	create();


	return 0;
}
