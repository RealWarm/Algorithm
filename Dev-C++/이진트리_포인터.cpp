#include <iostream>
using namespace std;
const int number=15;
typedef struct node *treePointer;
typedef struct node{
	int data;
	treePointer leftChild, rightChild;
} node;

// 전위순회
void preorder(treePointer ptr){
	if(ptr){
		printf("%d ", ptr->data);
		preorder(ptr->leftChild);		
		preorder(ptr->rightChild);
	}//if
}//preorder

// 중위순회
void inorder(treePointer ptr){
	if(ptr){
		inorder(ptr->leftChild);
		printf("%d ", ptr->data);
		inorder(ptr->rightChild);
	}//if
}//inorder

// 후위순회
void postorder(treePointer ptr){
	if(ptr){
		postorder(ptr->leftChild);		
		postorder(ptr->rightChild);
		printf("%d ", ptr->data);
	}//if
}//postorder

int main(){
	node nodes[number+1];
	for(int i=1; i<=number; i++){
		nodes[i].data=i;
		nodes[i].leftChild=NULL;
		nodes[i].rightChild=NULL;
	}//for-i
	
	for(int i=1; i<=number; i++){
		if(i%2==0){
			nodes[i/2].leftChild=&nodes[i];
		}else{
			nodes[i/2].rightChild=&nodes[i];
		}//if
	}//for-i
	preorder(&nodes[1]);
	printf("\n");
	inorder(&nodes[1]);
	printf("\n");
	postorder(&nodes[1]);
	
	
	
	return 0;
}//main





































