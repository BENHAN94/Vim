#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
}*first=NULL,*head=NULL;

void create(int A[], int n){
	int i;
	struct Node *last;
	first=(struct Node *)malloc(sizeof(struct Node));
	first->data=A[0];
	first->next=first->prev=NULL;
	last=first;
	for(i=1;i<n;i++){
		struct Node *t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=last->next;
		t->prev=last;
		last->next=t;
		last=t;
	}
}

void display(struct Node *p){
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
}

int length(struct Node *p){
	int l=0;
	while(p){
		l++;
		p=p->next;
	}
	return l;
}

void insert(struct Node *p, int index, int x){
	int i;
	struct Node *t=(struct Node *)malloc(sizeof(struct Node));
	t->data=x;
	if(index==0){
		t->next=first;
		t->prev=NULL;
		first=t;
	}else{
		for(i=0;i<index-1;i++){
			p=p->next;
		}
		t->next=p->next;
		t->prev=p;
		p->next=t;
	}
}

int delete(struct Node *p, int index){
	int i,x;
	if(index<0 || index>length(first)){
		return -1;
	}
	if(index==0){
		first=first->next;
		if(first)first->prev=NULL;
		x=p->data;
		free(p);
	}else{
		for(i=0;i<index;i++){
			p=p->next;
		}
		p->prev->next=p->next;
		if(p->next)
			p->next->prev=p->prev;
		x=p->data;
		free(p);
	}
	return x;
}

void reverse(struct Node *p){
	struct Node *tmp;
	while(p){
			tmp=p->next;
			p->next=p->prev;
			p->prev=tmp;
			p=p->prev;
			if(p!=NULL && p->next==NULL)
				first=p;
		}
	}


int main(){
	int A[] = {10,20,30,40,50};
	create(A, 5);
	reverse(first);
	printf("length is %d\n",length(first));
	display(first);
	return 0;
}
