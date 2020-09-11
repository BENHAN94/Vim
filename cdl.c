#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
}*head=NULL;

void create(int A[], int n){
	int i;
	struct Node *tail,*t;
	head=(struct Node *)malloc(sizeof(struct Node));
	head->next=head->prev=NULL;
	head->data=A[0];
	tail=head;
	for(i=1;i<n;i++){
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=tail->next;
		t->prev=tail;
		tail->next=t;
		tail=t;
	}
	tail->next=head;
	head->prev=tail;
}

void display(struct Node *p){
	do{
		printf("%d ",p->data);
		p=p->next;
	}while(p!=head);
}

int length(struct Node *p){
	int l;
	do{
		l++;
		p=p->next;
	}while(p!=head);
	return l;
}

void insert(struct Node *p, int index, int value){
	int i;
	if(index<0 || index>length(head)){
		return;
	}
	struct Node *t=(struct Node *)malloc(sizeof(struct Node));
	t->data=value;
	if(index==0){
		t->next=head;
		t->prev=head->prev;
		head->prev->next=t;
		head->prev=t;
		head=t;
	}else{
	for(i=0;i<index-1;i++){
		p=p->next;
	}
	t->next=p->next;
	t->prev=p;
	p->next=t;
	p->next->prev=t;
	}
}

int delete(struct Node *p,int index){
	int i,x;
	x=0;
	if(index<0 || index>length(p)){
		return -1;
	}
	if(index==0){
		p->next->prev=p->prev;
		p->prev->next=p->next;
		head=p->next;
		x=p->data;
		free(p);
	}else{
	for(i=0;i<index;i++){
		p=p->next;
	}
		p->next->prev=p->prev;
		p->prev->next=p->next;
		x=p->data;
		free(p);
	}
	return x;
}

void reverse(struct Node *p){
	struct Node *tmp;
	do{
		tmp=p->next;
		p->next=p->prev;
		p->prev=tmp;
		p=p->prev;
		}while(p!=head);
	head=p->next;
}

int main(){
	int A[]={1,2,3,4,5};
	create(A, 5);
	reverse(head);
	display(head);
	return 0;
}
