#include <stdio.h>
#include <stdlib.h>

struct Queue{
	int *Q;
	int front;
	int rear;
	int size;
};

void enque(struct Queue *q,int x){
	if((q->rear+1)%q->size==q->front)
		printf("Queue Overflow\n");
	else{
		q->rear=(q->rear+1)%q->size;
		q->Q[q->rear]=x;
	} 
}

int  deque(struct Queue *q){
	int x=-1;
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
	q->Q=(int *)malloc(size*sizeof(int));
}

void display(struct Queue q){
	int i=q.front+1;
	do{
		printf("%d ",q.Q[i]);
		i=(i+1)%q.size; 
	}while(i!=(q.rear+1)%q.size);
	printf("\n");
}

int main(){
	struct Queue q;
	create(&q,7);

	enque(&q,3);
	enque(&q,6);
	enque(&q,9);
	enque(&q,12);
	enque(&q,15);
	deque(&q);
	deque(&q);
	deque(&q);
	enque(&q,18);
	enque(&q,21);
	enque(&q,24);
	enque(&q,27);


	display(q);

	return 0;
}
