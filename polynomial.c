#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
	int coeff;
	int exp;
	struct Node *next;	
}*poly=NULL;

struct Poly{
	int n;
	struct Node *term;
};

// 4x3 + 9x2 + 6x + 7

void create(struct Poly *p){
	int i;
	struct Node *last,*t;

	printf("Enter number of terms\n");
	scanf("%d",&p->n);
	
	printf("Enter terms\n");
	for(i=0;i<p->n;i++){ 
		t=(struct Node *)malloc(sizeof(struct Node));
		scanf("%d%d",&t->coeff,&t->exp); 
		t->next=NULL;
		if(poly==NULL){
			poly=last=t;
		}else{
			last->next=t;
			last=t;
		}
	} 
}

void display(struct Node *p){
	while(p){
		printf("%dx%d + ", p->coeff,p->exp);
		p=p->next;
		}
}

double evaluate(struct Node *p,int x){
	int result=0;
	while(p){
		result+=p->coeff*pow(x,p->exp); 
		p=p->next;
		}
	return result;
}

int main(){

	struct Poly *p;
	create(p);
	display(poly);
	printf("= %f",evaluate(poly,2)); 
	return 0;
}
