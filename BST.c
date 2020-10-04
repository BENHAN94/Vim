#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{ 
	struct Node *lchild;
	struct Node *rchild;
	int data;
}*root=NULL;

struct Stack{
	struct Node **s; 
	int top; 
}*first;

void push(struct Node *p){ 
	first->top++;
	first->s[first->top]=p;
}

struct Node *pop(){ 
	struct Node *p;
	if(first->top!=-1){
		p=first->s[first->top--]; 
	}
	return p; 
}

int stackTop(){
	if(first->top!=-1)
		return first->s[first->top]->data;
	return INT_MAX;
}

void insert(int key){
	struct Node *t=root;
	struct Node *r,*p;
	if(!root){
		p=(struct Node *)malloc(sizeof(struct Node));
		p->lchild=p->rchild=NULL;
		p->data=key;
		root=p;
		return;
	} 
	while(t){ 
		r=t;
		if(t->data==key){
			printf("Same value is inserted\n");
			return;
		}else if(key<t->data){ 
			t=t->lchild;
		}else
			t=t->rchild;
	}
	p=(struct Node *)malloc(sizeof(struct Node));
	p->data=key;
	p->lchild=p->rchild=NULL;
	if(key<r->data)
		r->lchild=p;
	else
		r->rchild=p;
}

struct Node *Rinsert(struct Node *p, int key){
	struct Node *t=NULL;
	if(!p){
		t=(struct Node *)malloc(sizeof(struct Node));
		t->lchild=t->rchild=NULL;
		t->data=key;
		return t;
	} 
	if(key<p->data)
		p->lchild=Rinsert(p->lchild,key);
	else if(key>p->data)
		p->rchild=Rinsert(p->rchild,key); 

	return p;
}

void inorder(struct Node *p){
	if(p){
		inorder(p->lchild); 
		printf("%d ", p->data);
		inorder(p->rchild);
	}
}

struct Node *search(int key){
	struct Node *p;
	p=root; 
	while(p){
		if(key==p->data)
			return p; 
		else if(key<p->data)
			p=p->lchild;
		else
			p=p->rchild;
	}
	return NULL;
}

int height(struct Node *p){
	int x,y;
	if(p==NULL)return 0;
	x=height(p->lchild);
	y=height(p->rchild);
	return x>y?x+1:y+1;
}

struct Node *inPre(struct Node *p){
	while(p && p->rchild){
		p=p->rchild;
	}
	return p;
}

struct Node *inSucc(struct Node *p){
	while(p && p->lchild){
		p=p->lchild;
	}
	return p;
}

struct Node *delete(struct Node *p, int key){ 
	struct Node *q;
	if(!p)
		return NULL;
	if(!p->lchild && !p->rchild){
		if(p==root)
			root=NULL;
		free(p);
		return NULL;
	}
	if(key<p->data){ 
		p->lchild=delete(p->lchild,key);
	}else if(key>p->data){
		p->rchild=delete(p->rchild,key);
	}else{ 
		if(height(p->lchild)>height(p->rchild)){
			q=inPre(p->lchild);
			p->data=q->data;
			p->lchild=delete(p->lchild,q->data);
		}else{
			q=inSucc(p->rchild);
			p->data=q->data;
			p->rchild=delete(p->rchild,q->data); 
		}
	} 
	return p;
}

void createFromPre(struct Stack *st,int pre[], int size){ 
	int i=1;
	struct Node *p,*t;
	root=(struct Node *)malloc(sizeof(struct Node));
	root->rchild=root->lchild=NULL;
	root->data=pre[0];
	t=root;
	while(i<size-1){ 
		if(pre[i]<t->data){
			p=(struct Node *)malloc(sizeof(struct Node));
			p->rchild=p->lchild=NULL;
			p->data=pre[i++];
			t->lchild=p;
			push(t);
			t=p;
		}else{
			if(pre[i]<stackTop()){
				p=(struct Node *)malloc(sizeof(struct Node));
				p->rchild=p->lchild=NULL;
				p->data=pre[i++];
				t->rchild=p;
				t=p; 
			}else{
				t=pop();
			}
		} 
	}
}


int main(){

	int pre[]={30,20,10,15,25,40,50,45};
	int size=sizeof(pre)/sizeof(int); 
	first=(struct Stack *)malloc(sizeof(struct Stack));
	first->s=(struct Node **)malloc(size*sizeof(struct Node *)); 
	first->top=-1;

	createFromPre(first,pre,size);

	inorder(root);


	return 0;
}
