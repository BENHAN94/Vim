#include<stdio.h>
#include<stdlib.h>

struct Queue{ 
	int data;
	struct Queue *next;
}*front=NULL,*rear=NULL;

struct Stack{
	int data;
	struct Stack *next;
}*top=NULL;

int n=6;

void push(int x){
	struct Stack *s;
	s=(struct Stack *)malloc(sizeof(struct Stack));
	s->data=x;
	s->next=NULL;
	if(!top)
		top=s;
	else{
		s->next=top;
		top=s;
	}
}

int pop(){
	struct Stack *s;
	int x=-1;
	if(top){
		x=top->data;
		s=top; 
		top=top->next;
		free(s);
	}
	return x;
}

void enqueue(int x){ 
	struct Queue *q;
	q=(struct Queue *)malloc(sizeof(struct Queue));
	q->data=x;
	q->next=NULL;
	if(!front)
		front=rear=q;
	else{ 
		rear->next=q;
		rear=q;
	}
}

int dequeue(){ 
	int x=-1;
	struct Queue *q;
	if(front){ 
		x=front->data; 
		q=front;
		front=front->next;
		free(q);
	}
	return x;
}

void BFS(int i, int G[][n+1]){ 
	int j;
	int visited[]={0,0,0,0,0,0,0};
	printf("%d ",i);
	enqueue(i);
	visited[i]=1;
	while(front){ 
		i=dequeue(); 
		for(j=1;j<=n;j++){ 
			if(G[i][j]==1 && visited[j]==0){ 
				printf("%d ",j);
				enqueue(j); 
				visited[j]=1;
			}
		}
	}
}

void DFS(int i, int G[][n+1]){
	int j,temp;
	int visited[]={0,0,0,0,0,0,0};
	printf("%d ",i);
	push(i);
	visited[i]=1; 
	while(top){ 
		temp=i;
		for(j=1;j<=n;j++){ 
			if(G[i][j]==1 && visited[j]==0){
				printf("%d ",j);
				push(i);
				visited[j]=1;
				i=j;
				break;
			}
		}
		if(i==temp)
			i=pop();
	}
}

void rDFS(int G[][n+1], int start){
	static int visited[7]={0}; 
	int i;
	if(visited[start]==0){
		printf("%d ",start);
		visited[start]=1;
		for(i=1;i<=n;i++){
			if(G[start][i]==1 && visited[i]==0){
				push(start);
				rDFS(G,i);
			}
		}
	}
}

int main(){

	int G[7][7]={
		{0,0,0,0,0,0,0},
		{0,0,1,1,0,0,0},
		{0,1,0,0,1,0,0},
		{0,1,0,0,1,0,0},
		{0,0,1,1,0,1,1},
		{0,0,0,0,1,0,0},
		{0,0,0,0,1,0,0},
	};

	BFS(5,G);
	printf("\n");
	DFS(3,G);
	printf("\n");
	rDFS(G,1);

	return 0;
}
