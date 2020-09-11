#include <stdio.h>
#include <stdlib.h>

struct Node {
	int col;
	int value;
	struct Node *next;
};

struct Sparse {
	int m;
	int n;
	int num;
	struct Node **p;
};

void create(struct Sparse *s){
	int i,j,m,n,x;

	printf("Enter dimensions\n");
	scanf("%d%d",&s->m,&s->n); 
	s->p=(struct Node **)malloc(s->m*sizeof(struct Node));

	printf("Enter number of non-zero elements\n");
	scanf("%d",&(s->num));

	printf("Enter non-zero elements\n");	
	for(i=0;i<s->num;i++){
		scanf("%d%d%d",&m,&n,&x); 
		if(s->p[m]==NULL){
			s->p[m]=(struct Node *)malloc(sizeof(struct Node));
			s->p[m]->col=n; 
			s->p[m]->value=x;
			s->p[m]->next=NULL;
		}else{
			struct Node *tmp;
			tmp=s->p[m];
			struct Node *t=(struct Node *)malloc(sizeof(struct Node));
			while(tmp->next){
				tmp=tmp->next;
			}
			t->col=n;
			t->value=x;
			t->next=NULL;
			tmp->next=t;
		}
	} 
}

void display(struct Sparse s){
	int i,j;
	for(i=0;i<s.m;i++){
		for(j=0;j<s.n;j++){
			if(s.p[i] && s.p[i]->col==j){
				printf("%d ", s.p[i]->value);
				s.p[i]=s.p[i]->next;
			}else{
				printf("0 ");
			} 
		}
		printf("\n");
	}
} 

struct Sparse *add(struct Sparse s1, struct Sparse s2){
	int i,j;
	struct Sparse *new;
	new=(struct Sparse *)malloc(sizeof(struct Sparse));
	new->m=s1.m;
	new->n=s1.n;
	new->p=(struct Node **)malloc(new->m*sizeof(struct Node));
	for(i=0;i<s1.n;i++){
		struct Node *s1p=s1.p[i];
		struct Node *s2p=s2.p[i];
		new->p[i]=(struct Node *)malloc(sizeof(struct Node)); 
		new->p[i]->next=NULL;
		if(s1p->col<s2p->col){
			new->p[i]->col=s1p->col;
			new->p[i]->value=s1p->value; 
			s1p=s1p->next;
		}else if(s1p->col>s2p->col){
			new->p[i]->col=s2p->col;
			new->p[i]->value=s2p->value; 
			s2p=s2p->next; 
		}else{
			new->p[i]->col=s1p->col;
			new->p[i]->value=s1p->value+s2p->value;
			s1p=s1p->next;
			s2p=s2p->next; 
		}
		struct Node *newp=new->p[i];
		struct Node *last;
		last=newp;
		while(s1p && s2p){
			if(s1p<s2p){
				struct Node *t=(struct Node *)malloc(sizeof(struct Node));
				t->col=s1p->col;
				t->value=s1p->value; 
				last->next=t;
				last=t;
				s1p=s1p->next;
			}else if(s1p>s2p){
				struct Node *t=(struct Node *)malloc(sizeof(struct Node));
				t->col=s1p->col;
				t->value=s1p->value; 
				last->next=t;
				last=t;
				s1p=s1p->next;
			}else{
				struct Node *t=(struct Node *)malloc(sizeof(struct Node));
				t->col=s2p->col;
				t->value=s1p->value+s2p->value; 
				last->next=t;
				last=t;
				s1p=s1p->next;
				s2p=s2p->next; 
			}

		}
	}
	return new;
}
int main(){
	struct Sparse *s1,*s2,*s3;
	s1=(struct Sparse *)malloc(sizeof(struct Sparse)); 
	s2=(struct Sparse *)malloc(sizeof(struct Sparse));
	create(s1);
	printf("\n");
	display(*s1);
	return 0;
}
