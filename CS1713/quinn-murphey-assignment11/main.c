#include<stdio.h>
#include"BST.h"

void printMenu(){
	printf("\nMENU\n-------\n");
	printf("1 - Insert Node\n");
	printf("2 - Remove Node\n");
	printf("3 - Print Tree\n");
	printf("4 - Count Tree Nodes\n");
	printf("0 - Exit\n");
	printf("Enter your choice : ");
}

int main(int argc, char *argv[]){
	BSTNode *root = NULL;
	int input;
	printMenu();	
	scanf("%d", &input);
	while(input != 0){
		int secondInput;
		BSTNode *temp;
		int numNodes;
		switch(input){
			case 1:
				printf("\n");
				printf("Input a value : ");
				scanf("%d", &secondInput);
				insertNode(root, createNode(secondInput));
				break;
			case 2:
				printf("\n");
				printf("Input a value : ");
				scanf("%d", &secondInput);
				removeNode(root, secondInput);
				break;
			case 3:
				printf("\n");
				printf("1 - In Order Traversal\n");
				printf("2 - Pre Order Traversal\n");
				printf("3 - Post Order Traversal\n");
				printf("Input a value : ");
				scanf("%d", &secondInput);
				switch(secondInput){
					case 1:
						printInOrder(root);
						break;
					case 2:
						printPreOrder(root);
						break;
					case 3:
						printPostOrder(root);
						break;
					default:
						break;
				}
				break;
			case 4:
				temp = root;
				numNodes = 0;
				while(temp != NULL){
					numNodes++;
					removeNode(temp, findLeftestLowestChild(temp)->val);
				}
				printf("\nNumber of nodes: %d", numNodes);
				break;
			case 0:
			default:
				break;
		}
		printMenu();
		scanf("%d", &input);
	}
	destroyBST(root);
	return 0;
}
