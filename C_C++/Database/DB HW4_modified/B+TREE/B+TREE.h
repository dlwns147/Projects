#ifndef BPLUSTREE_H_
#define BPLUSTREE_H_
#include <stdbool.h>

typedef struct BPLUSTreeNode {
	int* keys;  // An array of keys
	struct BPLUSTreeNode* parent; // An array of parent pointer
	struct BPLUSTreeNode** child; // An array of child pointers
	struct BPLUSTreeNode* next; 
	int n;     // Current number of keys
	bool leaf; // Is true when node is leaf. Otherwise false
} Node;

Node* root; // Pointer to root node
int t;  // Maximum degree


void traverse(); // A function to traverse all nodes in a subtree rooted with this node
Node* search(int k); // function to search a key in this tree
void insertElement(int k); // The main function that inserts a new key in this B-Tree
void removeElement(int k); // The main function that removes a new key in thie B-Tree
void BPLUSTreeInit(int _t); // Initializes tree as empty


Node* _createNode(bool _leaf);
void _insert(Node* present, int k);
void _balancing(Node* present);
void _balancingAfterDel(Node* present);


Node* _splitChild(Node* present);
void _traverse(Node* present);
Node* _search(Node* present, int k);
void _remove(Node* present, int k);


void _borrowFromRight(Node* present, int idx);
void _borrowFromLeft(Node* present, int idx);
Node* _merge(Node* present);

int _getLevel(Node* present);
void _getNumberOfNodes(Node* present, int* numNodes, int level);
void _mappingNodes(Node* present, Node*** nodePtr, int* numNodes, int level);
void printTree();

#endif /* BPLUSTREE_H_ */