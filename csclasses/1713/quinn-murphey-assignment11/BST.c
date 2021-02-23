#include "BST.h"
#include <stdlib.h>
#include <stdio.h>

BSTNode* createNode(int v) {     
	BSTNode *n = (BSTNode*)malloc(sizeof(BSTNode));
	n->val = v;
	n->left = NULL;
	n->right = NULL;
	return n; 
}

/* BSTNode* search(BSTNode *root, int v) {     
	BSTNode *cur = root;
	while(cur != NULL){
		if(cur->val == v){
			return cur;
		}else if(v < cur->val){
			cur = cur->left;
		}
		else{
			cur = cur->right;
		}
	}
	return NULL; 
}*/

BSTNode* search(BSTNode *root, int v){
	if(root == NULL || root->val == v){
		return root;
	}else if(v < root->val){
		return search(root->left, v);
	}else{
		return search(root->right, v);
	}
}

void printInOrder(BSTNode *cur){
	if(cur == NULL){
		return;
	}
	printInOrder(cur->left);
	printf("%d ", cur->val);
	printInOrder(cur->right);
}

void printPreOrder(BSTNode *cur){
	if(cur == NULL){
		return;
	}
	printf("%d ", cur->val);
	printPreOrder(cur->left);
	printPreOrder(cur->right);
}

void printPostOrder(BSTNode *cur){
	if(cur == NULL){
		return;
	}
	printPostOrder(cur->left);
	printPostOrder(cur->right);
	printf("%d ", cur->val);
}

BSTNode* destroyBST(BSTNode *root){
	if(root == NULL){
		return NULL;
	}
	root->left = destroyBST(root->left);
	root->right = destroyBST(root->right);
	free(root);
	return NULL;
}

BSTNode* insertNode(BSTNode *root, BSTNode *n){
	if(root == NULL){
		return n;
	}else if(n->val <= root->val){
		root->left = insertNode(root->left, n);
	}else{
		root->right = insertNode(root->right, n);
	}
	return root; 
}

BSTNode* removeNode(BSTNode *root, int v){
	if(root == NULL){
		return NULL;
	}
	if(root->val > v){
		root->left = removeNode(root->left, v);
	}else if(root->val < v){
		root->right = removeNode(root->right, v);
	}else{
		if(root->left == NULL && root->right == NULL){
			free(root);
			return NULL;
		}else if(root->left == NULL || root->right == NULL){
			BSTNode *tmp;
			if(root->left == NULL){
				tmp = root->right;
			}else{
				tmp = root->left;
			}
			free(root);
			return tmp;
		}else{
			BSTNode *tmp = findLeftMostChild(root->right);
			root->val = tmp->val;
			root->right = removeNode(root->right, tmp->val);
		}
	}
	return root;
}

BSTNode* findLeftMostChild(BSTNode* root){
	if(root == NULL){
		return NULL;
	}else if(root->left != NULL){
		return findLeftMostChild(root->left);
	}return root;
}

BSTNode* findLeftestLowestChild(BSTNode* root){
	if(root == NULL){
		return NULL;
	}else if(root->left != NULL){
		printf("\tLooking left");
		return findLeftestLowestChild(root->left);
	}else if(root->right != NULL){
		printf("\tLooking left");
		return findLeftestLowestChild(root->right);
	}
	return root;
}
