// 2015112637 한효범

#include <stdio.h>
#include <stdlib.h>

int length=-1;
struct Stack *fetchTxt();
int *error;
int stackTop();
void push();
int isEmpty();
int pop();
int isAvailable();
int *target;
void display();
void popWhenMatch();

struct Stack{
	int size;
	int top;
	int *s;
};


// 목표값을 역으로 1,2,3 순으로 정렬할 수 있는지
// -> 목표값을 스택으로 쌓은 후 n,n-1,n-2,,,,의 역순으로 pop할 수 있는지
// 가능하면 yes, 불가능하면 no
//
// ==============절차===============
// 1. inputdata.txt의 값을 스택A로 저장.
// 2. A에서 tmp 스택으로 값을 보냄.
// 3. 보내는 동시에 3,2,1 역순으로 tmp에서 pop.
// 4. A가 빌 때 까지 작업 후 tmp도 비어있다면 Yes, 아니라면 No 출력 

int main(){

	//파일 가져와 스택 A에 적재
	char file[50];
	printf("파일명을 입력하세요: ");
	scanf("%s",file);
	struct Stack *A=fetchTxt(file);		

	if(*error){
	if(isAvailable(A)){
		display(target); 
		printf("Yes\n"); // 가능할 시 출력
	}else{
		display(target);
		printf("No\n"); // 불가능 시 출력
	} 
	}
	return 0;
}

// 목표값을 반대로 1,2,3 의 순서로 배열    
int isAvailable(struct Stack *st){
	int i,j,m;
	int s[length];
	int max=length;
	struct Stack *tmp; 
	tmp=(struct Stack *)malloc(sizeof(struct Stack));
	tmp->size=length;
	tmp->top=-1;
	tmp->s=(int *)malloc(tmp->size*sizeof(int));

	//inputdata.txt에서 받아온 스택 A가 빌 때 까지 작업 수행
	while(!isEmpty(*st)){
		while(stackTop(*tmp)!=max){ 
			m=pop(st);
			push(tmp,m); 
		}
		popWhenMatch(tmp,&max);// 1,2,3,,,n 중 n에서 부터 차레로 tmp에서 pop  
	}
	if(isEmpty(*tmp))
		return 1;
	else
		return 0; 
}

// 1,2,3,,,n 중 n에서 부터 차레로 tmp에서 pop
void popWhenMatch(struct Stack *st,int *max){
	if(stackTop(*st)==*max){
		pop(st); 
		*max=*(max)-1;
		popWhenMatch(st,max);
	}
}


//inputdata.txt의 값을 스택에 적재
struct Stack *fetchTxt(char file[]){
	error=(int *)malloc(sizeof(int));
	int value,i;
	FILE *input = fopen(file,"r");

	fscanf(input,"%d",&length); // 원소의 개수 입력 

	if(length<0){
		printf("정수의 개수가 음수입니다. 프로그램을 종료합니다.");
		*error=0;
		return NULL;
	}else
		*error=1; 

	
	struct Stack *B;
	B=(struct Stack *)malloc(sizeof(struct Stack));
	B->size=length;
	B->top=-1;
	B->s=(int *)malloc(B->size*sizeof(int));
	target=(int *)malloc(length*sizeof(int));

	//inputdata.txt의 값을 스택에 적재
	for(i=0;i<length;i++){
		fscanf(input,"%d",&value);
		target[i]=value; 
		push(B,value);
	}
	return B;	
}


// 답 출력 함수
void display(int *A){
	int i;
	printf("목표: ");
	for(i=0;i<length;i++){
		printf("%d ",A[i]);
	}
	printf(" -> ");
}

/*----------------------------------------------- stack 연산 함수들 */

int isEmpty(struct Stack st){
	if(st.top==-1){
		return 1;
	}
	return 0;
}

int isFull(struct Stack st){
	if(st.top==st.size-1){
		return 1;
	}
	return 0;
}

void push(struct Stack *st, int x){
	if(!isFull(*st)){
	st->top++;
	st->s[st->top]=x;
	}else{
		printf("Stack overflow\n");
	}
}

int pop(struct Stack *st){
	int x=-1;
	if(!isEmpty(*st)){
		x=st->s[st->top];
		st->top--;
	}else{
		printf("Stack underflow\n");
	}
	return x;
}

int stackTop(struct Stack st){
	if(st.top==-1){
		return -1;
	}else{
		return st.s[st.top];
	}
}
