#include <stdio.h>
#include <stdlib.h>


void insert(int A[],int index, int value){
	int i;
	for(i=5-1;i>index-1;i--){
		A[i+1]=A[i];
	}
	A[index]=value;
}

void display(int A[]){
	int i;
	for(i=0;i<6;i++){
		printf("%d ",A[i]);
	}
}

int delete(int index,int A[]){
	int i,x;
	x=A[index];
	for(i=index;i<5;i++){
		A[i]=A[i+1];
	}
	return x;
}

int main(){
	int A[5]={1,2,3,4,5};
	
	insert(A,1,7);
	display(A);
	printf("%d is deleted\n", delete(2,A));
	display(A);

	return 0;
}
