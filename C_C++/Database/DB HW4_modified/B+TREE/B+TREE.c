#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>

#include "B+TREE.h"

void BPLUSTreeInit(int _t)
{
	root = NULL;
	t = _t;
}


void traverse()
{
	if (root != NULL)
		_traverse(root);
}


Node* search(int k)
{
	return (root == NULL) ? NULL : _search(root, k);
}


Node* _createNode(bool _leaf)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	int i;

	// Copy the given minimum degree and leaf property
	newNode->leaf = _leaf;

	// Allocate memory for maximum number of possible keys
	// and child pointers
	newNode->keys = (int*)malloc(sizeof(int) * t);
	newNode->child = (Node**)malloc(sizeof(Node*) * (t + 1));
	newNode->next = NULL;

	// Initialize child
	for (i = 0; i < t + 1; i++)
		newNode->child[i] = NULL;

	// Initialize the number of keys as 0
	newNode->n = 0;

	// Initialize parent
	newNode->parent = NULL;

	return newNode;
}


void _traverse(Node* present)
{
	// There are n keys and n+1 children, travers through n keys and first n children
	int i;
	for (i = 0; i < present->n; i++)
	{
		// If this is not leaf, then before printing key[i],
		// traverse the subtree rooted with child C[i].
		if (present->leaf == false)
			_traverse(present->child[i]);

		printf(" ");
		printf("%d", present->keys[i]);
	}

	// Print the subtree rooted with last child
	if (present->leaf == false)
		_traverse(present->child[i]);
}


Node* _search(Node* present, int k)
{
	// Find the first key greater than k
	int i = 0;
	while (i < present->n && k >= present->keys[i])
		i++;

	// If the found key is equal to k, return this node
	if (present->leaf && present->keys[i - 1] == k)
		return present;

	// If key is not found here and this is a leaf node
	if (present->leaf == true)
		return NULL;

	// Go to the appropriate child
	return _search(present->child[i], k);
}


void insertElement(int k)
{
	// Find key in this tree, and If there is a key, it prints error message.
	if (search(k) != NULL)
	{
		printf("The tree already has %d \n", k);
		return;
	}

	// If tree is empty
	if (root == NULL)
	{
		// Allocate memory for root
		root = _createNode(true);
		root->parent = NULL; // Init parent
		root->keys[0] = k;  // Insert key
		root->n = 1;  // Update number of keys in root
	}
	else // If tree is not empty
		_insert(root, k);
}


void _insert(Node* present, int k)
{
	// Initialize index as index of rightmost element
	int i = present->n;

	// If this is a leaf node
	if (present->leaf)
	{
		//-------------------------------------------------------------------------------------------------------
		//Write your code.
		if (present->n == 0)
			present->keys[0] = k;
		else if (present->n == 1) {
			if (present->keys[0] < k) present->keys[1] = k;
			else {
				present->keys[1] = present->keys[0];
				present->keys[0] = k;
			}
		}
		else {
			for (i -= 1; i >= 0; i--) {
				if (present->keys[i] < k) {
					present->keys[i + 1] = k;
					break;
				}
				present->keys[i + 1] = present->keys[i];
			}
		}
		present->n++;
		if (present->n == t) _balancing(present); //  && present->keys[i] > k

		//-------------------------------------------------------------------------------------------------------
	}
	else // If this node is not leaf
	{
		//-------------------------------------------------------------------------------------------------------
		//Write your code.

		if (present->n == 1) {
			if (present->keys[0] > k) _insert(present->child[0], k);
			else _insert(present->child[1], k);
		}
		else {
			for (i = 0; i < present->n; i++) {
				if (i == 0 && present->keys[0] > k) {
					_insert(present->child[0], k);
					break;
				}
				else if (i == present->n - 1) {
					_insert(present->child[i + 1], k);
					break;
				}
				else if (present->keys[i] <= k && present->keys[i + 1] > k) {
					_insert(present->child[i + 1], k);
					break;
				}
			}
		}
		if (present->n == t) _balancing(present);

		//-------------------------------------------------------------------------------------------------------
	}
}


void _balancing(Node* present)
{
	Node* parent;

	if (present->n <= t - 1)
		return;
	else if (present->parent == NULL)
	{
		root = _splitChild(present);
		return;
	}
	else
	{
		parent = _splitChild(present);
		_balancing(parent);
	}
}


Node* _splitChild(Node* present)
{
	int i;
	int splitIdx;
	int risingKey;
	int parentIdx;
	Node* currentParent;
	Node* left;
	Node* right = _createNode(present->leaf);

	//-------------------------------------------------------------------------------------------------------
	//Write your code.

	splitIdx = t / 2;
	// splitIdx = (int)floor(((double)t + 1) / 2) - 1;
	risingKey = present->keys[splitIdx];
	right->next = present->next;

	left = present;
	left->n = splitIdx;
	left->next = right;

	int j = 0;
	if (present->leaf) {
		for (i = splitIdx; i < t; i++) {
			right->keys[j] = present->keys[i];
			j++;
			right->n++;
		}
	}
	
	else {
		j = 0;
		for (i = splitIdx + 1; i <= t; i++) {
			if (i < t) {
				right->keys[j] = present->keys[i];
				right->n++;
			}
			right->child[j] = present->child[i];
			right->child[j]->parent = right;
			left->child[i] = NULL;
			j++;
		}
	}
	
	if (present->parent) {
		currentParent = present->parent;
		right->parent = currentParent;
		for (i = currentParent->n - 1; i >= 0; i--) {
			if (currentParent->keys[i] < risingKey) {
				currentParent->keys[i + 1] = risingKey;
				currentParent->child[i + 2] = right;
				break;				
			}
			else if (currentParent->n == 1 && currentParent->keys[i] > risingKey) {
				currentParent->keys[1] = currentParent->keys[0];
				currentParent->child[2] = currentParent->child[1];
				currentParent->keys[0] = risingKey;
				currentParent->child[1] = right;
			}
			currentParent->keys[i + 1] = currentParent->keys[i];
			currentParent->child[i + 2] = currentParent->child[i + 1];
		}
		currentParent->n++;
	}

	//-------------------------------------------------------------------------------------------------------
	if (present->parent != NULL)
		return present->parent;
	else
	{
		root = _createNode(present->leaf);
		root->keys[0] = risingKey;
		root->n = 1;
		root->child[0] = left;
		root->child[1] = right;
		left->parent = root;
		right->parent = root;
		root->leaf = false;
		return root;
	}
}


void removeElement(int k)
{
	if (!root)
	{
		printf("The tree is empty\n");
		return;
	}

	// Call the remove function for root
	_remove(root, k);

	// If the root node has 0 keys, make its first child as the new root
	//  if it has a child, otherwise set root as NULL
	if (root->n == 0)
	{
		Node* tmp = root;
		if (root->leaf)
			root = NULL;
		else
		{
			root = root->child[0];
			root->parent = NULL;
		}

		// Free the old root
		free(tmp);
	}

	return;
}

void _remove(Node* present, int k)
{
	if (search(k) == NULL)
	{
		printf("error");
		return;
	}
	else {
		//-------------------------------------------------------------------------------------------------------
		//Write your code.

		// leaf node
		if (present->leaf) {
			for (int i = 0; i < (present->n - 1); i++)
				if (present->keys[i] >= k) present->keys[i] = present->keys[i + 1];
			present->n--;
			if (k < present->keys[0]) {
				for (int i = 0; present->n >= 1 && i < present->parent->n; i++) {
					if (present->parent->keys[i] == k) {
						present->parent->keys[i] = present->keys[0];
						break;
					}
				}
			}
			_balancingAfterDel(present);
			Node *ptr = present->parent;
			while (ptr != NULL) {
				for (int i = 0; i < ptr->n; i++) {
					if (ptr->keys[i] == k) {
						ptr->keys[i] = present->keys[0];
						break;
					}
				}
				ptr = ptr->parent;
			}
		}
		
		// inner node
		else {
			for (int i = 0; i < present->n; i++) {
				if (i == 0 && present->keys[0] > k) {
					_remove(present->child[0], k);
					break;
				}
				else if (i == present->n - 1) {
					_remove(present->child[i + 1], k);
					break;
				}
				else if (present->keys[i] <= k && present->keys[i + 1] > k) {
					_remove(present->child[i + 1], k);
					break;
				}
			}
		}

		//-------------------------------------------------------------------------------------------------------
	}
}

void _balancingAfterDel(Node* present) // repairAfterDelete
{
	int minKeys = (int)floor(((double)t + 1) / 2) - 1;

	Node* parent;
	Node* next;
	int parentIdx = 0;

	if (present->n < minKeys)
	{
		if (present->parent == NULL)
		{
			if (present->n == 0)
			{
				root = present->child[0];
				if (root != NULL)
					root->parent = NULL;
			}
		}
		else
		{
			parent = present->parent;
			for (parentIdx = 0; parent->child[parentIdx] != present; parentIdx++);

			if (parentIdx > 0 && parent->child[parentIdx - 1]->n > minKeys)
				_borrowFromLeft(present, parentIdx);
			else if (parentIdx < parent->n && parent->child[parentIdx + 1]->n > minKeys)
				_borrowFromRight(present, parentIdx);
			else if (parentIdx == 0)
			{
				// Merge with right sibling
				next = _merge(present);
				_balancingAfterDel(next->parent);
			}
			else
			{
				// Merge with left sibling
				next = _merge(parent->child[parentIdx - 1]);
				_balancingAfterDel(next->parent);
			}
		}
	}
}


void _borrowFromRight(Node* present, int parentIdx)  ////////////
{
	int i;

	Node* rightSib;
	Node* parent = present->parent;

	rightSib = parent->child[parentIdx + 1];
	present->n++;

	if (present->leaf)
	{
		present->keys[present->n - 1] = rightSib->keys[0];
		parent->keys[parentIdx] = rightSib->keys[1];
	}
	else
	{
		present->keys[present->n - 1] = parent->keys[parentIdx];
		parent->keys[parentIdx] = rightSib->keys[0];
	}

	if (!present->leaf)
	{
		present->child[present->n] = rightSib->child[0];
		present->child[present->n]->parent = present;

		for (i = 1; i < rightSib->n + 1; i++)
			rightSib->child[i - 1] = rightSib->child[i];
	}

	for (i = 1; i < rightSib->n; i++)
		rightSib->keys[i - 1] = rightSib->keys[i];

	rightSib->n--;
}


void _borrowFromLeft(Node* present, int parentIdx) /////////
{
	Node* leftSib;
	Node* parent = present->parent;
	present->n++;

	for (int i = present->n - 1; i > 0; i--)
		present->keys[i] = present->keys[i - 1];

	leftSib = parent->child[parentIdx - 1];

	if (present->leaf)
	{
		present->keys[0] = leftSib->keys[leftSib->n - 1];
		parent->keys[parentIdx - 1] = leftSib->keys[leftSib->n - 1];
	}
	else
	{
		present->keys[0] = parent->keys[parentIdx - 1];
		parent->keys[parentIdx - 1] = leftSib->keys[leftSib->n - 1];
	}

	if (!present->leaf)
	{
		for (int i = present->n; i > 0; i--)
			present->child[i] = present->child[i - 1];

		present->child[0] = leftSib->child[leftSib->n];
		leftSib->child[leftSib->n] = NULL;
		present->child[0]->parent = present;
	}

	leftSib->n--;
}


Node* _merge(Node* present)  //////
{
	Node* parent = present->parent;
	int parentIdx = 0;
	int fromParentIdx;

	for (parentIdx = 0; parent->child[parentIdx] != present; parentIdx++);

	Node* rightSib = parent->child[parentIdx + 1];

	if (!present->leaf)
		present->keys[present->n] = parent->keys[parentIdx];

	fromParentIdx = present->n;

	for (int i = 0; i < rightSib->n; i++)
	{
		int insertIdx = present->n + 1 + i;

		if (present->leaf)
			insertIdx -= 1;

		present->keys[insertIdx] = rightSib->keys[i];
	}

	if (!present->leaf)
	{
		for (int i = 0; i <= rightSib->n; i++)
		{
			present->child[present->n + 1 + i] = rightSib->child[i];
			present->child[present->n + 1 + i]->parent = present;
		}
		present->n = present->n + rightSib->n + 1;
	}
	else
	{
		present->n = present->n + rightSib->n;
		present->next = rightSib->next;
	}

	for (int i = parentIdx + 1; i < parent->n; i++)
	{
		parent->child[i] = parent->child[i + 1];
		parent->keys[i - 1] = parent->keys[i];
	}

	parent->n--;

	return present;
}


int _getLevel(Node* present)
{
	int i;
	int maxLevel = 0;
	int temp;
	if (present == NULL) return maxLevel;
	if (present->leaf == true)
		return maxLevel + 1;

	for (i = 0; i < present->n + 1; i++)
	{
		temp = _getLevel(present->child[i]);

		if (temp > maxLevel)
			maxLevel = temp;
	}

	return maxLevel + 1;
}

void _getNumberOfNodes(Node* present, int* numNodes, int level)
{
	int i;
	if (present == NULL) return;

	if (present->leaf == false)
	{
		for (i = 0; i < present->n + 1; i++)
			_getNumberOfNodes(present->child[i], numNodes, level + 1);
	}
	numNodes[level] += 1;
}

void _mappingNodes(Node* present, Node*** nodePtr, int* numNodes, int level)
{
	int i;
	if (present == NULL) return;

	if (present->leaf == false)
	{
		for (i = 0; i < present->n + 1; i++)
			_mappingNodes(present->child[i], nodePtr, numNodes, level + 1);
	}

	nodePtr[level][numNodes[level]] = present;
	numNodes[level] += 1;
}


void printTree()
{
	int level;
	int* numNodes;
	int i, j, k;

	level = _getLevel(root);
	numNodes = (int*)malloc(sizeof(int) * (level));
	memset(numNodes, 0, level * sizeof(int));

	_getNumberOfNodes(root, numNodes, 0);

	Node*** nodePtr;
	nodePtr = (Node***)malloc(sizeof(Node**) * level);
	for (i = 0; i < level; i++) {
		nodePtr[i] = (Node**)malloc(sizeof(Node*) * numNodes[i]);
	}

	memset(numNodes, 0, level * sizeof(int));
	_mappingNodes(root, nodePtr, numNodes, 0);

	for (i = 0; i < level; i++) {
		for (j = 0; j < numNodes[i]; j++) {
			printf("[");

			for (k = 0; k < nodePtr[i][j]->n; k++)
				printf("%d ", nodePtr[i][j]->keys[k]);

			printf("] ");
		}
		printf("\n");
	}

	for (i = 0; i < level; i++) {
		free(nodePtr[i]);
	}
	free(nodePtr);
}