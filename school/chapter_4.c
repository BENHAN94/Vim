// 2015112637 한효범

#include <stdio.h>
#include <stdlib.h>

// tree용 노드
struct treeNode {
	int data,level;
	struct treeNode *leftChild;
	struct treeNode *rightChild; 
}*root=NULL;

// queue용 노드
struct QueueNode{
	struct treeNode *tree;
	struct QueueNode *next;
	int level;
}*front=NULL,*rear=NULL;

// queue가 가득찼을 시 0 리턴
int isFull(){
	struct QueueNode *t=(struct QueueNode *)malloc(sizeof(struct QueueNode));
	if(!t)
		return 1;
	return 0;
}

// queue가 비었을 시 0리턴
int isEmpty(){
	if(front==NULL)
		return 1;
	return 0;
}

// queue에 treeNode추가
void enqueue(struct treeNode *p){
	if(isFull())
		printf("Queue is Full\n");
	struct QueueNode *t=(struct QueueNode *)malloc(sizeof(struct QueueNode));
	t->tree=p; 
	t->next=NULL;
	if(!front)
		front=rear=t; 
	else{
		rear->next=t;
		rear=t;
	}
}

// queue에 treeNode와 해당 노드의 level추가
void enqueueLevel(struct treeNode *p,int l){
	if(isFull())
		printf("Queue is Full\n");
	struct QueueNode *t=(struct QueueNode *)malloc(sizeof(struct QueueNode));
	t->tree=p; 
	t->next=NULL;
	t->level=l;
	if(!front)
		front=rear=t; 
	else{
		rear->next=t;
		rear=t;
	}
}

// queue에서 front treeNode를 삭제하고 리턴
struct treeNode *dequeue(){
	struct treeNode *p=NULL;
	struct QueueNode *q;
		p=front->tree;
		q=front;
		front=front->next; 
		free(q);
	return p;
}
 

// 파일에서 int값을 읽어와 binary tree를 만듦
void fetchTxtCreateTree(){
	int value;
	char name[50];
	printf("파일명을 입력하세요: ");
	scanf("%s",name);
	FILE *input = fopen(name,"r"); 
	struct treeNode *p,*t;
	root=(struct treeNode *)malloc(sizeof(struct treeNode));
	fscanf(input,"%d",&value);
	root->data=value; // 첫번째 값을 루트 노드에 할당
	root->leftChild=root->rightChild=0;
	enqueue(root); 
	enqueue(root);
	while(fscanf(input,"%d",&value)!=EOF){ // txt파일이 끝날 때 까지 int값을 subtree에 할당
		p=dequeue();
		if(value<p->data){ // scan값이 부모노드의 값보다 작을 시 왼쪽 subtree에 삽입
			if(value!=-1){// scan값이 -1이라면 subtree NULL
				t=(struct treeNode *)malloc(sizeof(struct treeNode));
				t->data=value;
				t->leftChild=t->rightChild=NULL;
				p->leftChild=t;
				enqueue(t);
				enqueue(t);
			} 
		}else{ //scan값이 부모노드의 값보다 크거나 같을 시 오른쪽 subtree에 삽입
			if(value!=-1){
				t=(struct treeNode *)malloc(sizeof(struct treeNode));
				t->data=value;
				t->leftChild=t->rightChild=NULL;
				p->rightChild=t;
				enqueue(t); 
				enqueue(t);
			}
		}
	} 
}


// 레벨 별 가장 왼쪽에 있는 노드의 값과 레벨 값 프린트
void findLeftNode(struct treeNode *t){
	int l=1;
	t->level=l;
	enqueueLevel(t,t->level); 
	printf("(%d, %d) ", t->level, t->data); // root 값 프린트
	while(!isEmpty()){ 
		t=dequeue();
		if(t->level>l){ // dequeue한 노드의 레벨값이 처음으로 커졌을 때 해당 노드의 레벨과 값 프린트
			printf("(%d, %d) ", t->level, t->data); 
			l++;
		}
		if(t->leftChild!=NULL){ // subtree에 부모의 레벨보다 1큰 값을 할당하고 큐에 삽입
			t->leftChild->level=l+1;
			enqueueLevel(t->leftChild,l+1);
		}
		if(t->rightChild!=NULL){
			t->rightChild->level=l+1;
			enqueueLevel(t->rightChild,l+1);
		}
	}
}

int main(int argc, char* argv[]){ 

	//txt파일의 int값을 트리로 생성
	fetchTxtCreateTree(); 

	// 트리를 생성하는데 사용했던 queue를 초기화
	while(!isEmpty()){
		dequeue();
	} 
	// 레벨당 가장 왼쪽에 있는 값과 해당 레벨 출력
	findLeftNode(root);

	return 0;
}
