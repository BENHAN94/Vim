#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void selectionSort(int A[],int n){ 
	int i,k,j; 
	for(i=0;i<n-1;i++){
		for(j=k=i;j<n;j++){ 
			if(A[j]<A[k])
				k=j;
		}
		swap(&A[i],&A[k]); 
	} 
}

int main(){
	int i;

	int A[]={8,6,3,2,5,4},n=6;

	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	
	selectionSort(A,n);

	printf("\n");

	for(i=0;i<n;i++)
		printf("%d ",A[i]);

	return 0;
}
