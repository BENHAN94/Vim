#include <stdio.h>
#include <stdlib.h>


struct Node{
	int data; 
	struct Node *next;
};


int max(int A[],int n){
	int x=INT32_MIN,i;
	for(i=0;i<n;i++){
		if(x<A[i])
			x=A[i];
	}
	return x;
}

int power(int x, int n){
	int i;
	if(n==0)
		x=1;
	else if(n==1)
		x=x;
	else{
		for(i=0;i<n-1;i++){
			x=x*x;
		}
	}
	return x;
}

int highestDigit(int x){
	int digit=0;
	while(x!=0){
		x=x/10;
		++digit;
	}
	return digit;
}

void radixSort(int A[],int n){ 
	int m=max(A,n),i,j,k=0;
	int digit=highestDigit(m);
	struct Node *B;
	struct Node *t,*p;
	B=(struct Node *)malloc(10*sizeof(struct Node));
	for(i=0;i<digit;i++){ 
		for(j=0;j<n;j++){ 
			t=B+((A[j]/power(10,digit))%10)*sizeof(struct Node);
			while(t->next){
				t=t->next;
			}
			p=(struct Node *)malloc(sizeof(struct Node));
			p->data=A[j];
			p->next=NULL;
			t->next=p;
		}
		j=0;k=0;
		t=B;
		while(t){ 
			if(t->data)
				p=t;
			while(p){
				A[j++]=p->data;
				p=p->next;
			}
			t+=sizeof(struct Node);
		}
	}
}

int main(){
	int A[]={237,146,259,348,152,163,235,48,36,62},n=10;

	radixSort(A,n);

	int i;
	for(i=0;i<n;i++)
		printf("%d ",A[i]);

	return 0;
}
