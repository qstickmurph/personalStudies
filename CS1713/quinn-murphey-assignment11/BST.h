typedef struct BSTNode{
	int val;
	struct BSTNode *left;
	struct BSTNode *right;
} BSTNode;

BSTNode* createNode(int v);
BSTNode* search(BSTNode *root, int v);
BSTNode* search(BSTNode *root, int v);
void printInOrder(BSTNode *cur);
void printPreOrder(BSTNode *cur);
void printPostOrder(BSTNode *cur);
BSTNode* destroyBST(BSTNode *root);
BSTNode* insertNode(BSTNode *root, BSTNode *n);
BSTNode* removeNode(BSTNode *root, int v);
BSTNode* findLeftMostChild(BSTNode* root);
BSTNode* findLeftestLowestChild(BSTNode* root);
