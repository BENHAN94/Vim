// 2015112637 한효범

#include <stdio.h>
#include <stdlib.h>

// global variables
int length=0; // 파일에서 추출한 정수값의 갯수
int fixedLength=0;
int *error; //정수 개수가 음수일 시 분기

int *fetchTxt();
int **countEachValue();
void Display();

int main(){	

	// txt파일에서 가져온 원소를 배열 A에 저장
	char file[50];
	printf("파일명을 입력하세요: ");
	scanf("%s",file);
	int *A=fetchTxt(file);		

	if(*error){ // 정수의 개수가 음수일 시 프로그램 종료
	int **B=countEachValue(A); // 2차원 배열에 원소와 각 원소의 나타난 횟수 입력
	Display(B); // 결과값 출력
	}

	return 0;
}
// .txt 파일에서 정수값 배열로 할당
int *fetchTxt(char file[]){
	error=(int *)malloc(sizeof(int));
	int value,i,*A;
	FILE *input = fopen(file,"r");

	fscanf(input,"%d",&length); // 원소의 개수 입력 
	if(length<0){
		printf("정수의 개수가 음수입니다. 프로그램을 종료합니다.");
		*error=0;
		return error;
	}else{
		*error=1;
	}

	A=(int *)malloc(length*sizeof(int));
	for(i=0;i<length;i++){
		fscanf(input,"%d",&value);
		A[i]=value;
	}
	return A;	
}


// 각각의 값이 나타나는 횟수
int numOfElement(int *A, int x){
	int i,n;
	n=0;
	for(i=0;i<length;i++){
		if(A[i]==x){
			n++;
		}	
	}
	return n;
}

// 중복되는 원소 제거
int *removeDup(int *B){
	int i,j,k;
	int *A=(int *)malloc(length*sizeof(int));
	for(i=0;i<length;i++){
		A[i]=B[i];
	}
	fixedLength=length;
	for(i=0;i<fixedLength;i++){
		for(j=i+1;j<fixedLength;){
			if(A[j]==A[i]){
				for(k=j;k<fixedLength;k++){
					A[k]=A[k+1]; 
				}
				fixedLength--;
			}else{
				j++;
			}
			}
		}
	return A;
	}

// txt에서 추출한 값과 그 값이 나타나는 횟수의 이차원 배열 리턴
int **countEachValue(int *A){
	int i,j,count; 
	int **B;
	int *C;

	B=(int **)malloc(2*sizeof(int));
	B[0]=(int *)malloc(length*sizeof(int));
	B[1]=(int *)malloc(length*sizeof(int)); 

	C=removeDup(A);
	for(i=0;i<fixedLength;i++){ // 1행에 txt에서 받아온 원소 입력 2행에 각 원소의 개수 입력 
		B[0][i]=C[i];	
		B[1][i]=numOfElement(A,C[i]);
	}
	return B;
}

// 결과값 출력
void Display(int **A){
	int i;
	for(i=0;i<fixedLength;i++){ 
		if(i<fixedLength-1)
			printf("%d: %d번, ",A[0][i],A[1][i]);
		else
			printf("%d: %d번",A[0][i],A[1][i]);
	}
}

