#include <stdio.h>
#include <stdlib.h>

struct Node{ struct Node *lchild;
	struct Node *rchild;
	int height;
	int data;
}*root=NULL;

int height(struct Node *p){
	int x,y;
	if(p==NULL)return 0;
	x=height(p->lchild);
	y=height(p->rchild);
	return x>y?x+1:y+1;
}

struct Node *inPre(struct Node *p){
	while(p->rchild){
		p=p->rchild;
	}
	return p;
}

struct Node *inSucc(struct Node *p){
	while(p->lchild){
		p=p->lchild;
	}
	return p;
}

int nodeHeight(struct Node *p){
	int hl,hr;
	hl=p && p->lchild?p->lchild->height:0;
	hr=p && p->rchild?p->rchild->height:0;
	return hl>hr?hl+1:hr+1;
}

struct Node *LLrotation(struct Node *p){
	struct Node *pl=p->lchild;
	struct Node *plr=pl->rchild;

	pl->rchild=p;
	p->lchild=plr;
	p->height=nodeHeight(p);
	pl->height=nodeHeight(pl);

	if(root==p)
		root=pl;

	return pl;
}

struct Node *LRrotation(struct Node *p){
	struct Node *pl=p->lchild;
	struct Node *plr=pl->rchild; 

	pl->rchild=plr->lchild;
	p->lchild=plr->rchild;
	plr->lchild=pl;
	plr->rchild=p;

	pl->height=nodeHeight(pl);
	plr->height=nodeHeight(plr);
	p->height=nodeHeight(p);

	if(root==p)
		root=plr; 

return plr;
}

struct Node *RRrotation(struct Node *p){
	struct Node *pr=p->rchild;
	struct Node *prl=pr->lchild;

	pr->lchild=p;
	p->rchild=prl;
	p->height=nodeHeight(p);
	pr->height=nodeHeight(pr);
	
	if(root==p)
		root=pr;
	return pr;
}

struct Node *RLrotation(struct Node *p){
	struct Node *pr=p->rchild;
	struct Node *prl=pr->lchild;

	p->rchild=prl->lchild;
	pr->lchild=prl->rchild;
	prl->lchild=p;
	prl->rchild=pr;
	p->height=nodeHeight(p);
	pr->height=nodeHeight(pr);
	prl->height=nodeHeight(prl);

	if(root==p)
		root=prl;
	return prl; 
}

int balanceFactor(struct Node *p){
	if(p){
		if(p->lchild && !p->rchild)
			return p->lchild->height; 
		else if(!p->lchild && p->rchild)
			return -p->rchild->height;
		else if(p->lchild && p->rchild)
			return p->lchild->height-p->rchild->height;
		else
			return 0;
	}
	return -99;
}

struct Node *fetchUnbalanceNode(struct Node *p){
	if(p){
		fetchUnbalanceNode(p->lchild);
		fetchUnbalanceNode(p->rchild);
		if(balanceFactor(p)==2)
			return p; 
	}
	return NULL;
}

struct Node *delete(struct Node *p,int key){

	struct Node *q;
	if(!p)
		return NULL;
	if(!p->lchild && !p->rchild){ 
		if(p==root)
			root=NULL;
		free(p);
		return NULL;
	}
	if(key<p->data)
		p->lchild=delete(p->lchild,key);
	else if(key>p->data)
		p->rchild=delete(p->rchild,key);
	else{
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
	p->height=nodeHeight(p);
	if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1)
		return LLrotation(p);
	else if(balanceFactor(p)==2 && balanceFactor(p->lchild)==-1)
		return LRrotation(p);
	else if(balanceFactor(p)==2 && balanceFactor(p->lchild)==0)
		return LLrotation(p);
	else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==-1)
		return RRrotation(p);
	else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==1)
		return RLrotation(p);
	else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==0)
		return RRrotation(p);
	return p; 
}

struct Node *insert(struct Node *p, int x){ 
	if(!p){ 
		p=(struct Node *)malloc(sizeof(struct Node));
		p->data=x;
		p->height=1;
		p->lchild=p->rchild=NULL;
	}else{
		if(x<p->data){
			p->lchild=insert(p->lchild,x);
			}
		else if(x>p->data){ 
			p->rchild=insert(p->rchild,x);
			}
		else
			return NULL;
	}
	p->height=nodeHeight(p);
	if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1)
		return LLrotation(p);
	else if(balanceFactor(p)==2 && balanceFactor(p->lchild)==-1)
		return LRrotation(p);
	else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==-1)
		return RRrotation(p);
	else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==1)
		return RLrotation(p);
	return p;
}

struct Node *inOrder(struct Node *p){ 
	if(p){
		inOrder(p->lchild);
		printf("(%d, %d, ",p->height,p->data);
		printf("%d)",balanceFactor(p));
		inOrder(p->rchild); 
	}
	return NULL;
}

int main(){

	printf("(height, data, balanceFactor)\n");
	root=insert(root,10);
	insert(root,20);
	insert(root,15);
	insert(root,25);
	insert(root,30);
	insert(root,40);
	insert(root,35);
	insert(root,45);

	delete(root,30);

	inOrder(root);

 	return 0;
}
