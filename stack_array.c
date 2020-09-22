#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
	int size;
	int top;
	int *s;
};

struct StackC{
	int size;
	int top;
	char *s;
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

int isOperand(char x){
	if(x=='+'||x=='-'||x=='*'||x=='/')
		return 0;
	else
		return 1;
}

int pre(char x){
	if(x=='+'||x=='-')
		return 1;
	else if(x=='*'||x=='/')
		return 2;
	return 0;
}
 
int main(){
	char infix[]="a+b*c-d/e";
	return 0;
}
