#include "stack.h"
#include <stdio.h>

// Make stack empty.
void InitStack(Stack* pstack)
{
	pstack->top = -1;
}
// Check whether stack is full.
bool IsFull(Stack* pstack)
{
    return pstack->top == MAX_STACK - 1;
}
// check whether stack is empty.
bool IsEmpty(Stack* pstack)
{
	return pstack->top == -1;
}
// Read the item(node) at the top.
BTreeNode* PeekNode(Stack* pstack)
{
	if (IsEmpty(pstack))
		return NULL;

	return pstack->items[pstack->top].node;
}
// Read the item(DATA_TYPE) at the top.
DATA_TYPE PeekData(Stack* pstack)
{
	if (IsEmpty(pstack))
		return '\0';

	return pstack->items[pstack->top].data;
}
// Insert an item(node) at the top.
void PushNode(Stack* pstack, BTreeNode* node)
{
	if (IsFull(pstack))
		return;

	pstack->items[++(pstack->top)].node = node;
}
// Insert an item(DATA_TYPE) at the top.
void PushData(Stack* pstack, DATA_TYPE item)
{
	if (IsFull(pstack))
		return;

	pstack->items[++(pstack->top)].data = item;
}

// Remove the item at the top.
void Pop(Stack* pstack)
{
	if (IsEmpty(pstack))
		return;

	--(pstack->top);
}
