#if defined(_MSC_VER)
	#define _CRT_SECURE_NO_WARININGS
#endif

#include <stdio.h>
#include <stdlib.h>

typedef int BData;

typedef struct BTreeNode{
	BData item;
	struct BTreeNode* left_child;
	struct BTreeNode* right_child;
}BTreeNode;


BTreeNode* create_node(BData);
void destroy_node(BTreeNode*);
void create_left_subtree(BTreeNode*, BTreeNode*);
void create_right_subtree(BTreeNode*, BTreeNode*);


void print_leaf_node(BTreeNode* node){
	/* implement your answer here */

	if (node->left_child) print_leaf_node(node->left_child);
	if (node->right_child) print_leaf_node(node->right_child);
	if (!node->left_child && !node->right_child) printf("%d\t",node->item);
	
	//hint : printf("%d\t",node->item);
}

int main(){
	/* DO NOT modify main function*/
	BTreeNode *node1 = create_node(1);
	BTreeNode *node2 = create_node(2);
	BTreeNode *node3 = create_node(3);
	BTreeNode *node4 = create_node(4);
	BTreeNode *node5 = create_node(5);
	BTreeNode *node6 = create_node(6);
	BTreeNode *node7 = create_node(7);
	BTreeNode *node8 = create_node(8);
	BTreeNode *node9 = create_node(9);
	BTreeNode *node10 = create_node(10);
	BTreeNode *node11 = create_node(11);
	BTreeNode *node12 = create_node(12);

	create_left_subtree(node1, node2);
	create_right_subtree(node1, node3);

	create_left_subtree(node2, node4);
	create_right_subtree(node2, node5);
	create_right_subtree(node3, node6);

	create_left_subtree(node4, node7);
	create_right_subtree(node4, node8);
	create_left_subtree(node6, node9);
	create_right_subtree(node6, node10);

	create_left_subtree(node8, node11);
	create_right_subtree(node9, node12);

	print_leaf_node(node1);
	printf("\n");

	destroy_node(node1);
	destroy_node(node2);
	destroy_node(node3);
	destroy_node(node4);
	destroy_node(node5);
	destroy_node(node6);
	destroy_node(node7);
	destroy_node(node8);
	destroy_node(node9);
	destroy_node(node10);
	destroy_node(node11);
	destroy_node(node12);

	return 0;
	/* DO NOT modify main function */
}

BTreeNode* create_node(BData item){
	BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
	node->item = item;
	node->left_child = NULL;
	node->right_child = NULL;

	return node;
}
void destroy_node(BTreeNode* node){
	free(node);
}
void create_left_subtree(BTreeNode* node, BTreeNode* left){
	if(node->left_child != NULL)
		exit(1);
	
	node->left_child = left;
}
void create_right_subtree(BTreeNode* node, BTreeNode* right){
	if(node->right_child != NULL)
		exit(1);
	
	node->right_child = right;
}


