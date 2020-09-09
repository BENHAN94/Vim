#include <stdio.h>
#include <stdlib.h>


struct Node{
	int data;
	struct Node *next;
}*head=NULL;

int length(struct Node *h){
	int l=0;
	do{
		l++;
		h=h->next;
	}while(h!=head);
	return l;
}
void create(int A[], int n){
	int i;
	struct Node *t,*last;
	head=(struct Node *)malloc(sizeof(struct Node));
	head->data=A[0];
	head->next=head;
	last=head;
	for(i=1;i<n;i++){
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=last->next;
		last->next=t;
		last=t;
	}
}
void display(struct Node *p){
	struct Node *q;
	q=p;
	do{ printf("%d ",p->data);
		p=p->next;
	}while(p!=q);
	printf("...");
}
void rdisplay(struct Node *p){
	static int flag=0;
	if(p!=head || flag==0){ 
		flag=1;
		printf("%d ",p->data);
		rdisplay(p->next);
	}
	flag=0;
}
void insert(struct Node *h, int index, int x){
	int i;
	struct Node *t=(struct Node *)malloc(sizeof(struct Node));
	t->data=x;
	if(index<0 || index >length(h)){
		return;
	}
	if(head==NULL){
		head=t;
		head->next=head;
	}
	if(index==0){
		index=length(h);
	}
	for(i=0;i<index-1;i++){
		h=h->next; 
	}
	t->next=h->next;
	h->next=t;
	
}
int isLoop(struct Node *f){
	struct Node *p,*q;
	p=q=f;
	do{
		p=p->next;
		q=q->next;
		q=q?q->next:NULL; 
	}while(p && q && p!=q);
	return p==q?1:0;
}
void delete(struct Node *p, int index){
	int i;
	struct Node *q;
	if(index==0){ 
		do{
			p=p->next;
		}while(p->next!=head);
		p->next=head->next;
		free(head);
		head=p->next;	
	}else{
		for(i=0;i<index;i++){
		q=p;
		p=p->next;
		}
		q->next=p->next;
		free(p);	
	}
}
int main(){ 
	int A[]={10,20,30,40,50};
	create(A,5);
	insert(head,0,5);
	delete(head,2);
	display(head);
	return 0;
}
