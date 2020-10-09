#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

struct stackNode{
	char data;
	struct stackNode *next;
}*top=NULL;

struct Node{
	char data;
	struct Node *lchild;
	struct Node *rchild;
	char pos;
	char parent;
}*root=NULL;

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


int isEmpty(struct Queue q){
	return q.front==q.rear;
}

void push(char x){
	struct stackNode *t;
	t=(struct stackNode *)malloc(sizeof(struct stackNode));

	if(t==NULL)
		printf("Stack Overflow\n");
	else{
		t->data=x;
		t->next=top;
		top=t;
	}
}

char pop(){
	struct stackNode *t;
	char x=-1; 
	if(top==NULL)
		printf("Stack is Empty\n");
	else{
		t=top;
		top=top->next;
		x=t->data;
		free(t);
	}
	return x;
}

void display(){
	struct stackNode *p;
	p=top;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

int isBalanced(char *exp){
	int i;
	for(i=0;exp[i]!='\0';i++){
		if(exp[i]=='(')
			push(exp[i]);
		else if(exp[i]==')'){
			if(top==NULL)
				return 0;
			pop();
		}
	}
	if(top==NULL)
		return 1;
	else
		return 0;
}

int pre(char x){
	if(x=='+' || x=='-')
		return 1;
	else if(x=='*' || x=='/')
		return 2;
	return 0;
}

int isOperand(char x){
	if(x=='+' || x=='-' || x=='*' || x=='/')
		return 0;
	else
		return 1;
}

char *InToPost(char *infix){
	int i=0,j=0;
	char *postfix;
	int len=strlen(infix);
	postfix=(char *)malloc((len+2)*sizeof(char)); 
	while(infix[i]!='\0'){
		if(isOperand(infix[i]))
			postfix[j++]=infix[i++];
		else{
			if(pre(infix[i])>pre(top->data))
				push(infix[i++]);
			else{
				postfix[j++]=pop();
			}
		}
	}
	while(top!=NULL)
		postfix[j++]=pop();
	postfix[j]='\0';
	return postfix;
}

void createTree(char *postfix){ 
	int n=strlen(postfix),i;
	char l,r;
	struct Node *rt,*lt,*tt;
	root=(struct Node *)malloc(sizeof(struct Node));
	root->data=postfix[0];
	root->lchild=root->rchild=NULL;
	for(i=1;i<n-1;i++){ 
		if(isOperand(postfix[i]))
			push(postfix[i]);
		else{ 
			r=pop();
			rt=(struct Node *)malloc(sizeof(struct Node));
			rt->data=r;
			rt->lchild=rt->rchild=NULL;
			tt=(struct Node *)malloc(sizeof(struct Node));
			tt->data=postfix[i];
			tt->lchild=root;
			tt->rchild=rt;
			root=tt;
			push(postfix[i]);
		}
	}
}

void levelOrder(struct Node *t){
	struct Queue q;
	create(&q, 100);
	enqueue(&q,t); 
	printf("%c ",t->data); 
	while(!isEmpty(q)){
			t=dequeue(&q);
			if(t->lchild){
				printf("%c ",t->lchild->data);
				enqueue(&q,t->lchild);
			}
			if(t->rchild){
				printf("%c ",t->rchild->data);
				enqueue(&q,t->rchild);
		} 
	}
}


int main(int argc, char *argv[]){
	char infix[100], ch, *fileName;
	int i=0;
	fileName=argv[1];
	FILE *input = fopen(fileName,"r"); 
	if(input){
		while(fscanf(input,"%c",&ch)!=EOF){ 
			if(ch!=' ')
				infix[i++]=ch;
		}
	}
	push('#');
	printf("%s",infix);
	char *postfix=InToPost(infix); 
	printf("%s",postfix);
	printf("\n");
	i=0;
	while(postfix[i]!='\0'){
		printf("%c, ",postfix[i++]);
	}
	return 0;
}
