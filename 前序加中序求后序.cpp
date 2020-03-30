#include<stdio.h>
#include<stdlib.h>	//malloc
char preorder[27];
char inorder[27];
struct Tree{
	char name;
	Tree* LeftTree;
	Tree* RightTree;
};

int find_root(char inorder[],int n,char element){
	if(n==0)
		return -1;
	for(int i=0;i<n;i++){
		if(element == inorder[i]){
			return i;
		}
	}
	//not found
	return -1;
}
Tree* construct(char preorder[],char inorder[],int n){
	Tree* root;
	if(n==0)
		return NULL;
	root = (Tree*) malloc (sizeof(Tree));
	if(root==NULL){
		return root; 
	}
	
	root->name = preorder[0];
	int k;
	k = find_root(inorder,n,preorder[0]);
	if(k<0){
		return NULL;
	}
	root->LeftTree = construct(&preorder[1],inorder,k);
	root->RightTree = construct(&preorder[k+1],&inorder[k+1],n-k-1);
	return root;
}


void postfix(Tree *root){
	if(root==NULL)
		return;
	
	postfix(root->LeftTree);
	postfix(root->RightTree);
	printf("%c",root->name);
}

int main(){
	while(scanf("%s",preorder)!=EOF){
		if(scanf("%s",inorder)!=EOF){
					
		}
		int i=0;
		for(;preorder[i]!='\0';i++){	
		
		}
		Tree* root = construct(preorder,inorder,i);
		postfix(root);
		printf("\n");
	}
	return 0;
} 

