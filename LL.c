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


int main(){
    int A[]={3,5,7,10,15};
    create(A, 5);
    printf("%p",Rsearch(first, 15));
    return 0;
}





