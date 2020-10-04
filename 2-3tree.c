#include <stdio.h>
#include <stdlib.h>

struct Node {
	int *k1;
	int *k2;
	struct Node *lchild;
	struct Node *rchild;
	struct Node *mchild;
}*root=NULL;

void insert(struct Node *p, int key){
	if(!p){
		p=(struct Node *)malloc(sizeof(struct Node));
		p->k1=(int *)malloc(sizeof(int));
		*(p->k1)=key;
		p->lchild=p->rchild=p->mchild=NULL;
		root=p;
	}
	if(p->k1 && key>*(p->k1) && !p->k2){
		p->k2=(int *)malloc(sizeof(int));
		*(p->k2)=key;
		}
	else if(p->k1 && p->k2 && key>*(p->k2)){ 
		if(!p->rchild){
		struct Node *l=(struct Node *)malloc(sizeof(struct Node));
		l->k1=(int *)malloc(sizeof(int));
		l->k1=p->k1;
		l->lchild=l->mchild=l->rchild=NULL;
		p->lchild=l;
		struct Node *m=(struct Node *)malloc(sizeof(struct Node));
		m->k1=(int *)malloc(sizeof(int));
		m->k1=p->k2;
		m->lchild=m->mchild=m->rchild=NULL; 
		p->mchild=m;
			*(p->k1)=*(p->k2);
			free(p->k2);
		}
	}
}

int main(){

	return 0;
}
