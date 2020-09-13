#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Node{
	int  data;
	struct Node *next; 
}*top=NULL;

int isEmpty(){
	return top?0:1;
}

int isFull(){
	struct Node *t=(struct Node *)malloc(sizeof(struct Node));
	int r=t?1:0;
	free(t);
	return r;
}

void push(char x){
	struct Node *t=(struct Node *)malloc(sizeof(struct Node));
	if(t==NULL){
		printf("Stack Overflow");
	}else{
		t->data=x;
		t->next=top;
		top=t;
	} 
}

int pop(){
	
	int x=-1;
	struct Node *tmp=top;

	if(isEmpty()){
		printf("Stack Underflow");
		return x;
	}
	top=top->next;
	x=tmp->data;
	free(tmp);
	return x;

}

int peek(int pos){
	int i;
	struct Node *p=top;
	for(i=0;p&&i<pos-1;i++){
		p=p->next;
	}
	if(p)
		return p->data;
	else
		return -1;
}

int  stackTop(){
	if(top)
		return top->data;
	return -1;
}

int isBalanced(char *exp){
	int i;
	for(i=0;exp[i]!='\0';i++){
		if(exp[i]=='(')
			push(exp[i]); 
		else if(exp[i]==')'){
			if(top==NULL)
				return 0;
			pop();
		}
	}
	if(top==NULL)
		return 1;
	else
		return 0;
}

int outPre(char x){
	if(x=='+' || x=='-')
		return 1;
	else if(x=='*' || x=='/')
		return 3;
	else if(x=='^')
		return 6;
	else if(x=='(')
		return 7;
	else if(x==')')
		return 0;
	return 0;
}

int inPre(char x){
if(x=='+' || x=='-')
		return 2;
	else if(x=='*' || x=='/')
		return 4;
	else if(x=='^')
		return 5;
	else if(x=='(')
		return 0;
	return 0;
}


int isOperand(char x){
	if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='(' || x==')')
		return 0;
	else
		return 1;
}

char * inToPost(char *infix){
	char *postfix;
	int len=strlen(infix);
	int i=0;
	int j=0;
	postfix=(char *)malloc((len+2)*sizeof(char));

 	while(infix[i]!='\0'){
		if(isOperand(infix[i]))
			postfix[j++]=infix[i++];
		else{
			if(outPre(infix[i])>inPre(top->data))
				push(infix[i++]);
			else if(outPre(infix[i])==inPre(top->data)){
				pop();
				i++;
			}
			else
				postfix[j++]=pop();
		}
	}
	while(top->data!='#')
		postfix[j++]=pop();
	postfix[j]='\0';
	
	return postfix; 
}

int operate(int x,int y,char op){ 
	if(op=='+')
		return x+y;
	else if(op=='-')
		return x-y;
	else if(op=='*')
		return x*y;
	else if(op=='/')
		return x/y;
	else if(op=='^')
		return pow(x,y);
	return 0; 
}

int evaluation(char *postfix){
	int i,x,y; 
	int result;
	for(i=0;postfix[i]!='\0';i++){ 
		if(isOperand(postfix[i]))
			push(postfix[i]-'0');
		else{ 
			y=pop();
			x=pop();
			result=operate(x,y,postfix[i]);
			push(result); 
		} 
	} 
	return top->data;
}



int main(){ 
	char *infix="((1+2)*3)-2^2^1";
	char *postfix;
	push('#');
	postfix=inToPost(infix);
	printf("%s ",postfix); 
	printf("\nResult is %d",evaluation(postfix));
	return 0;
}
