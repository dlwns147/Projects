#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* FYI, predefined macro and data types are as below.  */
/*
typedef char DATA_TYPE;

typedef struct _bTreeNode
{
    DATA_TYPE item;
    struct _bTreeNode * left_child;
    struct _bTreeNode * right_child;
} BTreeNode;
*/


BTreeNode* CreateNode(DATA_TYPE item)
{
    BTreeNode* node;
    /* write your own code here. */
    node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->item = item;
    node->left_child = 0;
    node->right_child = 0;

    return node;
}

void DestroyNode(BTreeNode* node)
{
    /* write your own code here. */
    free(node);
}

void CreateLeftSubtree(BTreeNode* root, BTreeNode* left)
{
    /* write your own code here. */
    if (root->left_child) printf("left subtree exists already! %d %d\n", root->item, left->item);
    else root->left_child = left;
}

void CreateRightSubtree(BTreeNode* root, BTreeNode* right)
{
    /* write your own code here. */
    if (root->right_child) printf("right subtree exists already! %d %d\n", root->item, right->item);
    else root->right_child = right;
}

void Inorder(BTreeNode* root)
{
    /* write your own code here. */
    if (root->left_child) Inorder(root->left_child);
    printf("%d ", root->item);
    if (root->right_child) Inorder(root->right_child);
}

void Preorder(BTreeNode* root)
{
    /* write your own code here. */
    printf("%d ", root->item);
    if (root->left_child) Preorder(root->left_child);
    if (root->right_child) Preorder(root->right_child);
}

void Postorder(BTreeNode* root)
{
    /* write your own code here. */
    if (root->left_child) Postorder(root->left_child);
    if (root->right_child) Postorder(root->right_child);
    printf("%d ", root->item);
}

int CalculateExpTree(BTreeNode* root)
{
    int ret;
    /* write your own code here. */
    int res_left, res_right;
    if (!root) ret = 0;
    else if (!root->left_child && !root->right_child) ret = (root->item - '0');
    else {
        if (root->left_child) res_left = CalculateExpTree(root->left_child);
        if (root->right_child) res_right = CalculateExpTree(root->right_child);

        if (root->item == '*') ret = res_left * res_right;
        else if (root->item == '/') ret = res_left / res_right;
        else if (root->item == '+') ret = res_left + res_right;
        else if (root->item == '-') ret = res_left - res_right;
        else if (root->item == '@') ret = (res_left << res_right);
        else if (root->item == '#') ret = (res_left >> res_right);

        // printf("%d %c %d %d\n", res_left, root->item, res_right, ret);
    }
    
    return ret;
}

BTreeNode* MakeExpTree(char* exp, int len)
{
    BTreeNode* ret;
    /* write your own code here. */
    Stack stack;
    InitStack(&stack);
    for (int i = 0; i < len; i++) {
        if (exp[i] >= '0' && exp[i] <= '9') {
            PushNode(&stack, CreateNode(exp[i]));
        }
        else {
            BTreeNode* node = CreateNode(exp[i]);
            CreateRightSubtree(node, PeekNode(&stack));
            Pop(&stack);
            CreateLeftSubtree(node, PeekNode(&stack));
            Pop(&stack);
            PushNode(&stack, node);
        }
    }
    ret = PeekNode(&stack);
    return ret;
}

void DestroyExpTree(BTreeNode* root)
{
    /* write your own code here. */
    if (root->left_child) DestroyNode(root->left_child);
    if (root->right_child) DestroyNode(root->right_child);
    free(root);
}

//DO NOT define main function
