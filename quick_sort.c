#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *x, int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

int partition(int A[],int l,int h){
	int pivot=A[l];
	int i=l,j=h;
	do{ 
		do{i++;}while(A[i]<=pivot);
		do{j--;}while(A[j]>pivot);
		if(i<j)swap(&A[i],&A[j]);
	}while(i<j);
	swap(&A[l],&A[j]);
	return j;
}

void quickSort(int A[],int l, int h){ 
	int j;
	if(l<h){
		j=partition(A,l,h);
		quickSort(A,l,j);
		quickSort(A,j+1,h);
	}
}

int main(){

	int A[]={11,13,7,12,16,9,24,5,10,3,INT32_MAX},n=11,i;

	for(i=0;i<n-1;i++)
		printf("%d ", A[i]);
	
	quickSort(A,0,n-1);

	printf("\n");

	for(i=0;i<n-1;i++)
		printf("%d ", A[i]);


	return 0;
}
