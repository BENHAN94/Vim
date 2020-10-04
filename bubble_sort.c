#include <stdio.h>
#include <stdlib.h>

void swap(int *x,int *y){ 
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void bubbleSort(int A[],int n){ 
	int i,j,flag; 
	for(i=0;i<n-1;i++){ 
		flag=0;
		for(j=0;j<n-1-i;j++){ 
			if(A[j]>A[j+1]){
				swap(&A[j],&A[j+1]);
				flag=1;
			}
		}
	   	if(flag==0)
			return; 
	}
}

int main(){ 
	int i; 
	int A[]={3,7,9,10},n=4; 
	bubbleSort(A,n);
	for(i=0;i<n;i++){ 
		printf("%d ",A[i]);
	} 
	return 0;
}
