#include <stdio.h>
#include <stdlib.h>



struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

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
	int i;
	int x;
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
int main(){
	int A[]={3,7,9,15,20}; 
	create(A,5);
	Display(first);
    return 0;
}





