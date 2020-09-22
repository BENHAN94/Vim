#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Node *root=NULL;

int n=0;

struct Stack{
	struct Node **p;
	int top;
	int size;
};

void createStack(struct Stack *st, int size){
	st->size=size;
	st->top=-1;
	st->p=(struct Node **)malloc(size*sizeof(struct Node *));
}

void push(struct Node *x, struct Stack *s){ 
	if(s->top==s->size-1){
		printf("Stack Overflow");
	}else{
		s->top++;
		s->p[s->top]=x;
	}
}

struct Node *pop(struct Stack *s){
	struct Node *t=NULL;
	if(s->top==-1)
		printf("Stack Underflow\n");
	else
		t=s->p[s->top--];
	return t;
}

void TreeCreate(){
	struct Node *p,*t;
	int x;
	struct Queue q;
	create(&q,100);

	printf("Enter root value \n");
	scanf("%d",&x);
	root=(struct Node *)malloc(sizeof(struct Node));
	root->data=x;
	root->lchild=root->rchild=NULL;
	enqueue(&q,root);

	while(!isEmpty(q)){ 
		p=dequeue(&q); 
		printf("Enter left child of %d: ",p->data);
		scanf("%d",&x);
		if(x!=-1){
			struct Node *t=(struct Node *)malloc(sizeof(struct Node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->lchild=t; 
			enqueue(&q,t);
		}
		printf("Enter right child of %d: ", p->data);
		scanf("%d",&x);
		if(x!=-1){
			struct Node *t=(struct Node *)malloc(sizeof(struct Node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->rchild=t; 
			enqueue(&q,t);
		}
	} 
}

void preorder(struct Node *p){
	if(p){
		printf("%d ",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void inorder(struct Node *p){
	if(p){ 
		inorder(p->lchild);
		printf("%d ",p->data);
		inorder(p->rchild);
	}
}

void postorder(struct Node *p){
	if(p){ 
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%d ",p->data);
	}
}

void IPreorder(struct Node *t){
	struct Stack st;
	createStack(&st,100);
	while(t || st.top!=-1){
		if(t){
			printf("%d ", t->data);
			push(t,&st);
			t=t->lchild;
		}else{
			t=pop(&st);
			t=t->rchild;
		}
	}
}

void IInorder(struct Node *t){
	struct Stack st;
	createStack(&st, 100);
	while(t || st.top!=-1){
		if(t){
			push(t,&st);
			t=t->lchild;
		}else{
			t=pop(&st);
			printf("%d ", t->data); 
			t=t->rchild;
		}
	}
}

void IPostorder(struct Node *t){
	struct Stack st;
	long int temp;
	createStack(&st, 100);
	while(t || st.top!=-1){
		if(t){
			push(t,&st);
			t=t->lchild;
		}else{
			temp=(long int)pop(&st);
			if(temp>0){
				push(((struct Node *)-temp),&st);
				t=((struct Node *)temp)->rchild;
			}else{
			printf("%d ",((struct Node *)-temp)->data);
			t=NULL;
			}
		}
 	}
}

void levelOrder(struct Node *t){
	struct Queue q;
	create(&q, 100);
	enqueue(&q,t); 
	printf("%d ",t->data); 
	while(!isEmpty(q)){
			t=dequeue(&q);
			if(t->lchild){
				printf("%d ",t->lchild->data);
				enqueue(&q,t->lchild);
			}
			if(t->rchild){
				printf("%d ",t->rchild->data);
				enqueue(&q,t->rchild);
		} 
	}
}

int count(struct Node *t){
	int x,y; 
	if(t){
		x=count(t->lchild);
		y=count(t->rchild);
		return x+y+1;
	}
	return 0;
} 

int height(struct Node *t){
	int x,y; 
	if(t){
		x=height(t->lchild);
		y=height(t->rchild);
		if(x>y)
			return x+1;
		else
			return y+1;
	}
	return 0;
}

int countLeaf(struct Node *t){
	int x,y; 
	if(t){
		x=countLeaf(t->lchild);
		y=countLeaf(t->rchild);
		if(!t->lchild && !t->rchild)
			return x+y+1;
		else
			return x+y;
	}
	return 0;
}

int countInternal(struct Node *t){
	int x,y; 
	if(t){
		x=countInternal(t->lchild);
		y=countInternal(t->rchild);
		if(t->lchild || t->rchild)
			return x+y+1;
		else
			return x+y;
	}
	return 0;
}

int countDegreeOne(struct Node *t){
	int x,y; 
	if(t){
		x=countDegreeOne(t->lchild);
		y=countDegreeOne(t->rchild);
		if(t->lchild != t->rchild)
			return x+y+1;
		else
			return x+y;
	}
	return 0;
}

int main(){ 
	TreeCreate(); 
	levelOrder(root);
	printf("\ncount: %d",count(root));
	printf("\nheight: %d",height(root));
	printf("\nleaf: %d",countLeaf(root));
	printf("\ninternal: %d",countInternal(root));

	return 0;
}

