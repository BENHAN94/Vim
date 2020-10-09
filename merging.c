#include <stdio.h>
#include <stdlib.h>


int *merge(int A[], int B[], int m, int n){
	int i=0,j=0,k=0;
	int *C;
	C=(int *)malloc((m+n)*sizeof(int));
	while(i<m && j<n){
		if(A[i]>B[j]) 
			C[k++]=B[j++]; 
		else
			C[k++]=A[i++];
	}
	for(;i<m;i++)
		C[k++]=A[i];
	for(;j<n;j++)
		C[k++]=B[j];
	return C;
}

void mergeSingle(int A[],int l, int m, int h){
	int B[h+1];
	int i=l, j=m+1, k=l; 
	while(i<=m && j<=h){
		if(A[i]<A[j])
			B[k++]=A[i++];
		else
			B[k++]=A[j++]; 
	}
	for(;i<=m;i++)
		B[k++]=A[i];
	for(;j<=h;j++)
		B[k++]=A[j];
	for(i=l;i<=h;i++)
		A[i]=B[i];
}

void RmergeSort(int A[],int l,int h){
	int mid;
	if(l<h){
		mid=(l+h)/2;
		RmergeSort(A,l,mid);
		RmergeSort(A,mid+1,h);
		mergeSingle(A,l,mid,h);
	}
}

void mergeSort(int A[],int n){ 
	int i,p,h,mid,l;
	for(p=2;p<=n;p=2*p){
		for(i=0;i+p-1<n;i=i+p){ 
			l=i;
			h=i+p-1;
			mid=(l+h)/2;
			mergeSingle(A,l,mid,h);
		}
	}
	if(p/2<n)
		mergeSingle(A,0,p/2-1,n-1);
}


int main(){

	int i;
	int A[]={1,3,5,7};
	int B[]={2,4,6,8,10,12};
	int *C=merge(A,B,4,6);
	for(i=0;i<10;i++)
		printf("%d ",C[i]);
	printf("\n");
	int D[]={8,4,7,5,12,1,10,2,6,3};
	mergeSort(D,10);
	for(i=0;i<10;i++)
		printf("%d ",D[i]);



	return 0;
}
