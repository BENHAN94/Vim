#include <stdio.h>
#include <stdlib.h>

struct Stack{
	int size;
	int top;
	int *s;
};

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

int peek(struct Stack st, int pos){
	int x=-1;
	int index=st.top-pos+1;
	if(index<0){
		printf("Invalid position\n");
	}else{
		x=st.s[index]; 
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

int main(){
	struct Stack st;
	printf("Enter size of stack \n");
	scanf("%d",&st.size);
	st.s=(int *)malloc(sizeof(int));
 	st.top=-1;
	return 0;
}
