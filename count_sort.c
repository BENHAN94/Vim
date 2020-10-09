#include <stdio.h>
#include <stdlib.h>

int max(int A[],int n){
	int i;
	int x=INT32_MIN;
	for(i=0;i<n;i++){ 
		if(A[i]>x)
			x=A[i];
	}
	return x;
}

void countSort(int A[],int n){ 
	int m=max(A,n);
	int *B,i,j=0; 
	B=(int *)malloc(m*sizeof(int));
	for(i=0;i<m;i++)
		B[i]=0;
	for(i=0;i<n;i++){ 
		B[A[i]]++;
	}
	i=0;
	while(i<m+1){
		if(B[i]>0){ 
			A[j++]=i;
			B[i]--;
		}else
			i++;
	}
}

int main(){

	int i;

	int A[]={6,3,9,10,15,6,8,12,3,6},n=10;

	countSort(A,n);

	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	return 0;
}
