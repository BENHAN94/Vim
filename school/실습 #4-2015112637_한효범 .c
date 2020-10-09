//2015112637 한효범

#include <stdio.h>
#include <stdlib.h>
#include<strings.h>

//Stack 노드
struct Node{
 	char data;
	struct tree *tree;
 	struct Node *next;
}*top=NULL;

//큐 노드
struct Queue{
	struct tree *tree;
	struct Queue *next;
}*front=NULL,*rear=NULL;

//트리 노드
struct tree{
	char data; 
	int level;
	struct tree *lchild;
	struct tree *rchild;
};

//큐에 삽입
void enqueue(struct tree *p){
	struct Queue *t=(struct Queue *)malloc(sizeof(struct Queue));
	t->tree=p;
	t->next=NULL;
	if(!front)
		front=rear=t;
	else{ 
		rear->next=t;
		rear=t;
	}
}


//큐에서 제거한 값 리턴
struct tree *dequeue(){
	struct tree *p;
	struct Queue *t;
	if(front){
		p=front->tree;
		t=front;
		front=front->next;
		free(t);
	}
	return p;
}


//스택에 삽입
void push(char x){
	 struct Node *t;
	 t=(struct Node*)malloc(sizeof(struct Node)); 
	 if(t==NULL)
	 	printf("stack is full\n");
	 else{
		t->data=x;
		t->next=top;
		top=t;
	 }

}

//스택에 트리노드 삽입
void pushTree(struct tree *p){
	 struct Node *t;
	 t=(struct Node*)malloc(sizeof(struct Node)); 
	 if(t==NULL)
	 	printf("stack is full\n");
	 else{
		t->tree=p;
		t->next=top;
		top=t;
	 }

}

//스택에서 제거한 값 리턴
char pop(){
	struct Node *t;
	char x=-1;

	if(top==NULL)
		printf("Stack is Empty\n");
	else{
		 t=top;
		 top=top->next;
		 x=t->data;
		 free(t);
	}
 	return x;
}

//스택에서 제거한 트리노드 리턴
struct tree *popTree(){
	struct Node *t;
	struct tree *p;

	if(top==NULL)
		printf("Stack is Empty\n");
	else{
		 t=top;
		 top=top->next;
		 p=t->tree;
		 free(t);
	}
 	return p;
}

// ()가 완벽히 채워졌는지 확인
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

//스택 밖에서의 수식 원소 지수
int outstackPre(char x){
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
	return -1;
}

//스택 안에서의 수식 원소 지수
int instackPre(char x){
	if(x=='+' || x=='-')
		return 2;
	else if(x=='*' || x=='/')
		return 4; 
	else if(x=='^')
		return 5;
	else if(x=='(')
		return 0;
	return -1;
}

//피연산자일 시 1 리턴
int isOperand(char x){
	 if(x=='+' || x=='-' || x=='*' || x=='/' || x=='(' || x==')' || x=='^')
	 	return 0;
	 else
	 	return 1; 
}

//infix를 postfix로 변환
char * InToPost(char *infix){
	 int i=0,j=0;
	 char *postfix;
	 static char temp;
	 int len=strlen(infix);
	 postfix=(char *)malloc((len+2)*sizeof(char));

	 while(infix[i]!='\0'){
	 	if(isOperand(infix[i]))
	 		postfix[j++]=infix[i++];
	 	else{
	 		if(outstackPre(infix[i])>instackPre(top->data))
	 			push(infix[i++]); 
	 		else{
				temp=pop();
				if(temp!= '(' && temp!= ')')
					postfix[j++]=temp;
	 		}
		}
	 }
	 while(top!=NULL){
		temp=pop();
		if(temp!= '(' && temp!= ')')
	 		postfix[j++]=temp;
		}
	 postfix[j]='\0';
	 return postfix;
}

//postfix에서 트리 생성
struct tree * create(char *postfix){ 
	struct tree *t,*t1,*t2;
	int i;

	for(i=0;i<strlen(postfix);i++){
		if(isOperand(postfix[i])){
			t=(struct tree *)malloc(sizeof(struct tree)); 
			t->data=postfix[i];
			t->lchild=t->rchild=NULL;
			pushTree(t); 
		}else{
			t=(struct tree *)malloc(sizeof(struct tree)); 
			t->data=postfix[i];
			t->lchild=t->rchild=NULL; 
			t1=popTree();
			t2=popTree();

			t->rchild=t1;
			t->lchild=t2;

			pushTree(t);
		}
	}
	t=popTree();

	return t;
}

//트리 level order로 print
void treeOutput(struct tree *t){ 
	struct tree *p;
	int l=1;
	printf("(Root, %c)\n",t->data); 
	t->level=l;
	enqueue(t);
	p=t;
	while(front){ 
		p=dequeue(); 
		if(p->level>l){
			l++;
			printf("\n");
		}
		if(p->lchild){
			printf("(%c,L,%c)",p->data,p->lchild->data); 
			p->lchild->level=l+1;
			enqueue(p->lchild);
		}
		if(p->rchild){
			printf("(%c,R,%c)",p->data,p->rchild->data);
			p->rchild->level=l+1;
			enqueue(p->rchild);
		}
	}
}

int main(int argc, char *argv[]){
	int i=0;
	char *infix,ch,temp[100];
	char *fileName=argv[1];

	//file에서 infix값 fetch
	FILE *input=fopen(fileName, "r");
	while(fscanf(input,"%c",&ch)!=EOF){ 
		if(ch!=' ')
			temp[i++]=ch;
	}
	infix=temp;

	push('#'); // 스택 empty상태 방지

	//infix 출력
	printf("%s\n",infix);

	//infix를 postfix로 변환
	char *postfix=InToPost(infix); 
	postfix[strlen(postfix)-1]='\0';// empty 방지로 넣었던 # 지우기
	printf("%s\n",postfix); 

	//postfix에서 트리 생성
	struct tree *t = create(postfix);

	//level order로 트리 출력
	treeOutput(t);
	
	return 0;
}
