#ifndef Queue_h
#define Queue_h

struct Node{
	struct Node *lchild;
	struct Node *rchild;
	int data;
};

struct Queue{
	int front;
	int rear;
	int size;
	struct Node **Q;
};

void enqueue(struct Queue *q,struct Node *x){
	if((q->rear+1)%q->size==q->front)
		printf("Queue Overflow\n");
	else{
		q->rear=(q->rear+1)%q->size;
		q->Q[q->rear]=x;
	} 
}

struct Node * dequeue(struct Queue *q){
	struct Node *x=NULL;
	if(q->rear==q->front)
		printf("Queue Undeflow\n");
	else{
		q->front=(q->front+1)%q->size;
		x=q->Q[q->front];
	}
	return x;
}

void create(struct Queue *q, int size){
	q->size=size;
	q->front=q->rear=0;
	q->Q=(struct Node **)malloc(q->size*sizeof(struct Node *));
}

void display(struct Queue q){
	int i=q.front+1;
	do{
		printf("%p ",q.Q[i]);
		i=(i+1)%q.size; 
	}while(i!=(q.rear+1)%q.size);
	printf("\n");
}

int isEmpty(struct Queue q){
	return q.front==q.rear;
}

#endif
