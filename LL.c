#include <stdio.h>
#include <stdlib.h>



struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
   
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void create2(int A[], int n)
{
    int i;
    struct Node *t,*last;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;
   
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void create3(int A[], int n)
{
    int i;
    struct Node *t,*last;
    third=(struct Node *)malloc(sizeof(struct Node));
    third->data=A[0];
    third->next=NULL;
    last=third;
   
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void Display(struct Node *p){
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
}
void RDisplay(struct Node *p)
{
    if(p){
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}
int Count(struct Node *p)
{
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}
int Sum(struct Node *p){
    int s=0;
    while(p){
        s+=p->data;
        p=p->next;
    }
    return s;
}
int Rsum(struct Node *p){
    if(p){
        return Rsum(p->next)+p->data;
    }
    return 0;
}
int Max(struct Node *p){
    int M;
    M=p->data;
    while(p){
        if(M<p->data){
            M=p->data;
        }
        p=p->next;
    }
    return M;
}
int Rmax(struct Node *p){
    int x=0;
    if(!p){
        return INT32_MIN;
    } 
    x=Rmax(p->next);
    if(x>p->data){
        return x;
    }else{
        return p->data;
    }
}
struct Node *Search(struct Node *p, int x){
    while(p){
        if(p->data==x){
            return p;
        }
        else{
            p=p->next;
        }
    }
    return p;
}
struct Node *Rsearch(struct Node *p, int x){
    if(p){
        if(p->data==x){
           return p; 
        }
        else{
            return Rsearch(p->next,x);
        }
    }
    return NULL;
}
struct Node *Isearch(struct Node *p, int x){
	struct Node *q;
	while(p){
		if(x==p->data){
			q->next=p->next;
			p->next=first;
			first=p;
			return p;
		}else {
			q=p;
			p=p->next;
		}
}
	return NULL;
}
void Insert(struct Node *p, int n, int x){
	int i;
	if(n<0||n>Count(p)){
		return;
	} 
	struct Node *t=(struct Node *)malloc(sizeof(struct Node));
	t->data=x;
	p=first;
	if(n==0){
		t->next=first;
		first=t;
	}else{
	for(i=0;i<n-2;i++){
		p=p->next;
	}
	t->next=p->next;
	p->next=t;
	}
}

void InsertLast(struct Node *p, int x){
	struct Node *t=(struct Node *)malloc(sizeof(struct Node));
	struct Node *last;
	t->data=x;
	t->next=NULL;
	if(first==NULL){
		first=last=t;
	}else{
		last->next=t;
		last=t;
	}
}
void InsertSorted(struct Node *p, int x){
	struct Node *t=(struct Node *)malloc(sizeof(struct Node));
	t->data=x;
	t->next=NULL;
	if(first==NULL){
		first=t;
	}else{
	if(x<first->data){
		t->next=first;
		first=t;
	}else{
	struct Node *q;
	p=first;
	while(p && p->data<x){
	q=p;
	p=p->next;	
	}
	t->next=p;
	q->next=t;
	}
	}
}
void Delete(struct Node *p, int index){
	struct Node *q;
	int i,x;
	if(index==0){
		q=first;
		x=first->data;
		free(first);
		first=q->next;
	}else{
		for(i=0;i<index;i++){
			q=p;
			p=p->next;
		}
		q->next=p->next;
		x=p->data;
		free(p);
	}	
} 
int IsSorted(struct Node *p){
	int m=INT32_MIN;
	while(p){
		if(m>p->data){
			return 0;
		}
		m=p->data;
		p=p->next; 
	}
	return 1;
}
void RemoveDuplicate(struct Node *p){
	p=first;
	struct Node *q=first->next; 
	while(q){
	if(p->data!=q->data){
		p=q;
		q=q->next;
	}else{
		p->next=q->next;
		free(q);
		q=p->next;
	}
	}
}
void Reverse(struct Node *p){
	int n=Count(p);
	int A[n];
	int i=0;
	while(p){
		A[i]=p->data;
		p=p->next;
		i++; 
	}
	p=first;
	for(i=n-1;i>=0;i--){
		p->data=A[i];
		p=p->next;
	} 
}
void ReverseP(struct Node *p){
	struct Node *q=NULL;
	struct Node *r=NULL;
	while(p){
		r=q;
		q=p;
		p=p->next;
		q->next=r; 
	}
	first=q;
}
void RreverseP(struct Node *p, struct Node *q){
	if(p){
		RreverseP(p->next,p);
		p->next=q;
	}else{
		first=q;
	}
}
void Concatnate(struct Node *p, struct Node *q){
	third=p;
	while(p->next){
		p=p->next;
	}
	p->next=q;
}
void Merge(struct Node *f, struct Node *s){
	struct Node *l;
	if(f->data<s->data){
		third=l=f;
		f=f->next;
		l->next=NULL;
	}else{
		third=l=s;
		s=s->next;
		l->next=NULL;
	}
	while(f && s){
	if(f->data>s->data){
		l->next=s;	
		l=s;
		s=s->next;
		l->next=NULL;	
	}else{
		l->next=f;
		l=f;
		f=f->next;
		l->next=NULL;
		}
	} 
	if(f){
		l->next=f;
	}else{
		l->next=s;
	}
}
int main(){
	int A[]={1,3,5,7,9,11}; 
	create(A,6); 
	int B[]={2,4,6,8,10};
	create2(B,5);
	Merge(first,second);
	Display(third);
    return 0;
}





