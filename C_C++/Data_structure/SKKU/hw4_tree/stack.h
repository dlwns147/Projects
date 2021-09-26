#pragma once

#include <stdbool.h>
#include "binary_tree.h"

#define MAX_STACK 100
typedef union {
    DATA_TYPE data;
	BTreeNode* node;
} Data;

typedef struct {
    Data items[MAX_STACK];
    int top;
} Stack;

//NOTE: Stack should be declared per data type.
//Don't Push BTreeNode and DATA_TYPE at one stack

// Make stack empty.
void InitStack(Stack* pstack);
// Check whether stack is full.
bool IsFull(Stack* pstack);
// check whether stack is empty.
bool IsEmpty(Stack* pstack);
// Read the item(Node) at the top.
BTreeNode* PeekNode(Stack* pstack);
// Insert an item(DATA_TYPE) at the top.
DATA_TYPE PeekData(Stack* pstack);
// Insert an item(Node) at the top.
void PushNode(Stack* pstack, BTreeNode* node);
// Insert an item(DATA_TYPE) at the top.
void PushData(Stack* pstack, DATA_TYPE item);
// Remove the item at the top.
void Pop(Stack* pstack);