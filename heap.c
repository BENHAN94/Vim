#include <stdio.h>
#include <stdlib.h>

void insert(int H[],int n){ 
	int i=n,temp;
	temp=H[i];
	while(i>1 && temp>H[i/2]){
		H[i]=H[i/2];
		i=i/2;
	}
	H[i]=temp;
} 

int delete(int H[],int n){
	int i,j,x,temp,val;
	val=H[1];
	x=H[n];
	H[1]=H[n];
	H[n]=val;
	i=1;j=i*2;

	while(j<n-1){
		if(H[j]<H[j+1])
			j=j+1;
		if(H[i]<H[j]){
			temp=H[i];
			H[i]=H[j];
			H[j]=temp;
			i=j;
			j=2*j;
			}
		else
			break;
	} 
	return val;
}

void swap(int *x, int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void heapify(int H[],int n){ 	
	int i,j,k; 
	for(i=n;i>=1;i--){
		j=i*2;
		k=i;
		if(j<=n){ 
			while(j<n){
				if(H[j+1] && H[j]<H[j+1])
					j=j+1;
				if(H[k]<H[j]){
					swap(&H[k],&H[j]);
					k=j;
					j=k*2;
				}		
			}
		}
	}
}

int main(){

	int H[]={0,5,10,30,20,35,40,15};
	// 40,25,35,10,5,20,30
	int i;

	for(i=1;i<=7;i++)
		printf("%d ", H[i]); 

	heapify(H,7);

	printf("\n");

	for(i=1;i<=7;i++)
		printf("%d ", H[i]); 

	return 0; 
}
