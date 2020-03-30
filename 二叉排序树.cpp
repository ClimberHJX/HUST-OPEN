#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	node * LeftNode;
	node * RightNode; 
}; 
int input[101];

node* insertTree(node *root,int input){
	if(root == NULL){
		root = (node*) malloc (sizeof(node));
		if(root==NULL)
			printf("malloc fail");
		root->num = input;
		root->LeftNode = NULL;
		root->RightNode = NULL;
	}
	else if(input<root->num)
		root->LeftNode = insertTree(root->LeftNode,input);
	else if(input>root->num)
		root->RightNode = insertTree(root->RightNode,input);
	return root;
}
void preorder(node* root){
	if(root==NULL)
		return;
	printf("%d ",root->num);
	preorder(root->LeftNode);
	preorder(root->RightNode);
} 
void inorder(node* root){
	if(root==NULL)
		return;
		
	inorder(root->LeftNode);
	printf("%d ",root->num);
	inorder(root->RightNode);	
}
void postorder(node* root){
	if(root==NULL)
		return;
		
	postorder(root->LeftNode);
	postorder(root->RightNode);
	printf("%d ",root->num);
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&input[i]);
		}
		node *root = NULL;
		for(int i=0;i<n;i++){
			root = insertTree(root,input[i]);
		}
		preorder(root);
		printf("\n");
		inorder(root);
		printf("\n");
		postorder(root);
		printf("\n");
	} 
	return 0;
}



