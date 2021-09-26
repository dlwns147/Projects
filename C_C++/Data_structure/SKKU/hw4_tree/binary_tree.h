#pragma once

#include <stdbool.h>

typedef char DATA_TYPE;

typedef struct _bTreeNode
{
    DATA_TYPE item;
    struct _bTreeNode * left_child;
    struct _bTreeNode * right_child;
} BTreeNode;


//Create a new node.
BTreeNode* CreateNode(DATA_TYPE item); 
//Destroy a node.
void DestroyNode(BTreeNode * node);

//Connect the root to a left-side node.
void CreateLeftSubtree(BTreeNode* root, BTreeNode* left);
//Connect the root to a right-side node.
void CreateRightSubtree(BTreeNode* root, BTreeNode* right);

//Inorder traversal: visiting left subtree -> root -> right subtree
void Inorder(BTreeNode* root);
//Preorder traversal: visiting root -> left subtree -> right subtree
void Preorder(BTreeNode* root);
//Postorder traversal: visiting left subtree -> right subtree -> root
void Postorder(BTreeNode* root);

//Caculateing expression tree.
int CalculateExpTree(BTreeNode* root);
//Building expression tree.
BTreeNode* MakeExpTree(char* exp, int len);
//Destroy expresiion tree.
void DestroyExpTree(BTreeNode* root);