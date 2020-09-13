#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
	int size;
	int top;
	char *c;
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

void push(struct Stack *st, char x){
	if(!isFull(*st)){
	st->top++;
	st->c[st->top]=x;
	}else{
		printf("Stack overflow\n");
	}
}

char pop(struct Stack *st){
	char x=-1;
	if(!isEmpty(*st)){
		x=st->c[st->top];
		st->top--;
	}else{
		printf("Stack underflow\n");
	}
	return x;
}

char peek(struct Stack st, int pos){
	char x=-1;
	int index=st.top-pos+1;
	if(index<0){
		printf("Invalid position\n");
	}else{
		x=st.c[index]; 
	}
	return x; 
}

char stackTop(struct Stack st){
	if(st.top==-1){
		return -1;
	}else{
		return st.c[st.top];
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
 
char *convert(char *infix){
	struct Stack st; 
	int i=0,j=0;
	char *postfix=(char *)malloc((strlen(infix)+2)*sizeof(char));
	while(infix[i]!='\0'){
		if(isOperand(infix[i]))
			postfix[j++]=infix[i++];
		else{
			if(pre(infix[i]>pre(st.top)))
				push(&st,infix[i++]);
			else
				postfix[j++]=pop(&st);
		}
	}
	while(!isEmpty(st)){
		postfix[j++]=pop(&st);
	}
	postfix[j]='\0';
	return postfix; 
}

int main(){
	char *infix="a+b*c-d/e"; 
	char *postfix=convert(infix);
	printf("%s ",postfix);
	return 0;
}
