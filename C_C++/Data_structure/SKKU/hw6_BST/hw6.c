#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* predefined data types and functions are as below.  */
typedef int Key;
typedef struct _BSTNode{Key key; struct _BSTNode * left_child; struct _BSTNode * right_child;} BSTNode;

BSTNode * CreateNode(Key key);					// Create a new node.
void DestroyNode(BSTNode * node);				// Destroy a node.
bool Verify(BSTNode* root, int min, int max);	// Verify whether the tree is a binary search tree or not.
BSTNode* Search(BSTNode* root, Key key);		// Search an item in BST.
void Insert(BSTNode* root, Key key);			// Insert an item to BST.
void Remove(BSTNode* node, Key key);			// Remove an item from BST.

int invalid;
int num_1st, num_2nd;
int invalid_edge_1 = 0;
int invalid_edge_2 = 0;
int count = 0;

BSTNode *root_1st_1, *root_2nd_1;
BSTNode *root_1st_2, *root_2nd_2;
BSTNode *node_1st, *node_2nd;

char keys_1st[60];
char keys_2nd[60];
char leaf_1st[60];
char leaf_2nd[60];
char func[60];
char leaf_len_1 = 0;
char leaf_len_2 = 0;

void function1 (int degree, int cur, int start) {
	// printf("f1 degree : %d cur : %d\n", degree, cur);
	if (cur <= degree) {
		for (int i = start; leaf_len_1 >= degree && i < leaf_len_1 - (degree - cur); i++) {
			Remove(root_1st_1, leaf_1st[i]);
			func[cur - 1] = leaf_1st[i];
			function1(degree, cur + 1, i + 1);
			Insert(root_1st_1, leaf_1st[i]);
		}
	}
	else {
		count = degree;
		for (int j = 0; j < num_2nd; j++) Insert(root_1st_1, keys_2nd[j]);
		for (int j = 0; j < degree; j++) Insert(root_1st_1, func[j]);
		for (int j = 0; j < num_2nd; j++) {
			node_1st = Search(root_1st_1, keys_2nd[j]); // Find the node in the 1st BST with a 2ND key value.
			node_2nd = Search(root_2nd_1, keys_2nd[j]); // Find the node in the 2nd BST with a 2ND key value.

			if (!node_1st->left_child && !node_2nd->left_child) ; // When the LEFT child of the merged BST's node and the 2nd BST's node is NULL, it is VALID.
			else if (!node_1st->left_child && node_2nd->left_child) { if(Search(root_2nd_1, node_2nd->left_child->key)) count++; }// Either one is NULL and the other is not, it is INVALID.
			else if (node_1st->left_child && !node_2nd->left_child) { if(Search(root_2nd_1, node_1st->left_child->key)) count++; }// Either one is NULL and the other is not, it is INVALID.
			else if (Search(root_2nd_1, node_1st->left_child->key) && Search(root_2nd_1, node_2nd->left_child->key) && node_1st->left_child->key != node_2nd->left_child->key) count++; // Both are not null and the keys of each nodes are not same, it is INVALID.

			if (!node_1st->right_child && !node_2nd->right_child) ; // When the RIGHT child of the merged BST's node and the 2nd BST's node is NULL, it is VALID.
			else if (!node_1st->right_child && node_2nd->right_child) { if(Search(root_2nd_1, node_2nd->right_child->key)) count++;} // Either one is NULL and the other is not, it is INVALID.
			else if (node_1st->right_child && !node_2nd->right_child) { if(Search(root_2nd_1, node_1st->right_child->key)) count++;} // Either one is NULL and the other is not, it is INVALID.
			else if (Search(root_2nd_1, node_1st->right_child->key) && Search(root_2nd_1, node_2nd->right_child->key) && node_1st->right_child->key != node_2nd->right_child->key) count++; // Both are not null and the keys of each nodes are not same, it is INVALID.
		}
		if (count < invalid) invalid = count;
		for (int j = 0; j < degree; j++) Remove(root_1st_1, func[j]);
		for (int j = num_2nd - 1; j >= 0; j--) Remove(root_1st_1, keys_2nd[j]);
		// printf("invalid : %d, count : %d\n", invalid, count);
	}
}

void function2 (int degree, int cur, int start){
	// printf("f2 degree : %d cur : %d\n", degree, cur);
	if (cur <= degree) {
		for (int i = start; leaf_len_2 >= degree && i < leaf_len_2 - (degree - cur); i++) {
			Remove(root_2nd_1, leaf_2nd[i]);
			func[cur - 1] = leaf_2nd[i];
			function2(degree, cur + 1, i + 1);
			Insert(root_2nd_1, leaf_2nd[i]);
		}
	}

	else {
		count = degree;
		for (int j = 0; j < num_1st; j++) Insert(root_2nd_1, keys_1st[j]);
		for (int j = 0; j < degree; j++) Insert(root_2nd_1, func[j]);
		for (int j = 0; j < num_1st; j++) {
			node_1st = Search(root_1st_1, keys_1st[j]); // Find the node in the 1st BST with a 2ND key value.
			node_2nd = Search(root_2nd_1, keys_1st[j]); // Find the node in the 2nd BST with a 2ND key value.

			if (!node_1st->left_child && !node_2nd->left_child) ; // When the LEFT child of the merged BST's node and the 2nd BST's node is NULL, it is VALID.
			else if (!node_1st->left_child && node_2nd->left_child) { if(Search(root_1st_1, node_2nd->left_child->key)) count++;} // Either one is NULL and the other is not, it is INVALID.
			else if (node_1st->left_child && !node_2nd->left_child) { if(Search(root_1st_1, node_1st->left_child->key)) count++;} // Either one is NULL and the other is not, it is INVALID.
			else if (Search(root_1st_1, node_1st->left_child->key) && Search(root_1st_1, node_2nd->left_child->key) && node_1st->left_child->key != node_2nd->left_child->key) count++; // Both are not null and the keys of each nodes are not same, it is INVALID.

			if (!node_1st->right_child && !node_2nd->right_child) ; // When the RIGHT child of the merged BST's node and the 2nd BST's node is NULL, it is VALID.
			else if (!node_1st->right_child && node_2nd->right_child) { if(Search(root_1st_1, node_2nd->right_child->key)) count++;} // Either one is NULL and the other is not, it is INVALID.
			else if (node_1st->right_child && !node_2nd->right_child) { if(Search(root_1st_1, node_1st->right_child->key)) count++;} // Either one is NULL and the other is not, it is INVALID.
			else if (Search(root_1st_1, node_1st->right_child->key) && Search(root_1st_1, node_2nd->right_child->key) && node_1st->right_child->key != node_2nd->right_child->key) count++; // Both are not null and the keys of each nodes are not same, it is INVALID.
		}
		if (count < invalid) invalid = count;
		for (int j = 0; j < degree; j++) Remove(root_2nd_1, func[j]);
		for (int j = num_1st - 1; j >= 0; j--) Remove(root_2nd_1, keys_1st[j]);
		// printf("invalid : %d, count : %d\n", invalid, count);
	}
}

int main()
{
	/* write your own code here */
	scanf("%d %d", &num_1st, &num_2nd);

	for (int i = 0; i < num_1st; i++) {
		scanf("%d", &keys_1st[i]);
		if (i == 0) {
			root_1st_1 = CreateNode(keys_1st[i]);
			root_1st_2 = CreateNode(keys_1st[i]);
		}
		else {
			Insert(root_1st_1, keys_1st[i]);
			Insert(root_1st_2, keys_1st[i]);
		}
	}
	for (int i = 0; i < num_2nd; i++) {
		scanf("%d", &keys_2nd[i]);
		if (i == 0) {
			root_2nd_1 = CreateNode(keys_2nd[i]);
			root_2nd_2 = CreateNode(keys_2nd[i]);
		}
		else {
			Insert(root_2nd_1, keys_2nd[i]);
			Insert(root_2nd_2, keys_2nd[i]);
		}
	}

	BSTNode *tmpnode;
	for (int i = 0; i < num_1st; i++) {
		tmpnode = Search(root_1st_1, keys_1st[i]);
		if (!(tmpnode->left_child) && !(tmpnode->right_child)) leaf_1st[leaf_len_1++] = keys_1st[i];
	}
	for (int i = 0; i < num_2nd; i++) {
		tmpnode = Search(root_2nd_1, keys_2nd[i]);
		if (!(tmpnode->left_child) && !(tmpnode->right_child)) leaf_2nd[leaf_len_2++] = keys_2nd[i];
	}
	// printf("len1: %d len2 : %d\n", leaf_len_1, leaf_len_2);

	for (int i = 0; i < num_2nd; i++) Insert(root_1st_1, keys_2nd[i]); // Merge the 2ND BST into the 1ST BST.
	for (int i = 0; i < num_2nd; i++) {
		node_1st = Search(root_1st_1, keys_2nd[i]); // Find the node in the 1st BST with a 2ND key value.
		node_2nd = Search(root_2nd_1, keys_2nd[i]); // Find the node in the 2nd BST with a 2ND key value.

		if (!node_1st->left_child && !node_2nd->left_child) ; // When the LEFT child of the merged BST's node and the 2nd BST's node is NULL, it is VALID.
		else if ((!node_1st->left_child && node_2nd->left_child) || (node_1st->left_child && !node_2nd->left_child)) invalid_edge_1++; // Either one is NULL and the other is not, it is INVALID.
		else if (node_1st->left_child->key != node_2nd->left_child->key) invalid_edge_1++; // Both are not null and the keys of each nodes are not same, it is INVALID.

		if (!node_1st->right_child && !node_2nd->right_child) ; // When the RIGHT child of the merged BST's node and the 2nd BST's node is NULL, it is VALID.
		else if ((!node_1st->right_child && node_2nd->right_child) || (node_1st->right_child && !node_2nd->right_child)) invalid_edge_1++; // Either one is NULL and the other is not, it is INVALID.
		else if (node_1st->right_child->key != node_2nd->right_child->key) invalid_edge_1++; // Both are not null and the keys of each nodes are not same, it is INVALID.
	}
	for (int i = num_2nd - 1; i >= 0; i--) Remove(root_1st_1, keys_2nd[i]);

	for (int i = 0; i < num_1st; i++) Insert(root_2nd_2, keys_1st[i]); // Merge the 1ST BST into the 2ND BST.
	for (int i = 0; i < num_1st; i++) {
		node_1st = Search(root_1st_2, keys_1st[i]); // Find the node in the 1st BST with a 1ST key value.
		node_2nd = Search(root_2nd_2, keys_1st[i]); // Find the node in the 2nd BST with a 1ST key value.

		if (!node_1st->left_child && !node_2nd->left_child) ; // When the LEFT child of the merged BST's node and the 2nd BST's node is NULL, it is valid.
		else if ((!node_1st->left_child && node_2nd->left_child) || (node_1st->left_child && !node_2nd->left_child)) invalid_edge_2++; // Either one is NULL and the other is not, it is INVALID.
		else if (node_1st->left_child->key != node_2nd->left_child->key) invalid_edge_2++; // Both are not null and the keys of each nodes are not same, it is INVALID.

		if (!node_1st->right_child && !node_2nd->right_child) ; // When the RIGHT child of the merged BST's node and the 2nd BST's node is NULL, it is VALID.
		else if ((!node_1st->right_child && node_2nd->right_child) || (node_1st->right_child && !node_2nd->right_child)) invalid_edge_2++; // Either one is NULL and the other is not, it is INVALID.
		else if (node_1st->right_child->key != node_2nd->right_child->key) invalid_edge_2++; // Both are not null and the keys of each nodes are not same, it is INVALID.
	}
	for (int i = num_1st - 1; i >= 0; i--) Remove(root_2nd_2, keys_1st[i]); // Merge the 1ST BST into the 2ND BST.

	invalid = invalid_edge_1 < invalid_edge_2 ? invalid_edge_1 : invalid_edge_2;

	// function1(1, 1, 0);
	// function2(1, 1, 0);
	// function1(2, 1, 0);
	// function2(2, 1, 0);
	int max_count = 5;
	for (int i = 1; i <= (leaf_len_1 < max_count ? leaf_len_1 : max_count); i++) function1(i, 1, 0);
	for (int i = 1; i <= (leaf_len_2 < max_count ? leaf_len_2 : max_count); i++) function2(i, 1, 0);
	// for (int i = 0; i < leaf_len_1; i++) {
	// 	count = 1;
	// 	Remove(root_1st_1, leaf_1st[i]);
	// 	for (int j = 0; j < num_2nd; j++) Insert(root_1st_1, keys_2nd[j]);
	// 	Insert(root_1st_1, leaf_1st[i]);

	// 	for (int j = 0; j < num_2nd; j++) {
	// 		node_1st = Search(root_1st_1, keys_2nd[j]); // Find the node in the 1st BST with a 2ND key value.
	// 		node_2nd = Search(root_2nd_1, keys_2nd[j]); // Find the node in the 2nd BST with a 2ND key value.

	// 		if (!node_1st->left_child && !node_2nd->left_child) ; // When the LEFT child of the merged BST's node and the 2nd BST's node is NULL, it is VALID.
	// 		else if (!node_1st->left_child && node_2nd->left_child) { if(Search(root_2nd_1, node_2nd->left_child->key)) count++; }// Either one is NULL and the other is not, it is INVALID.
	// 		else if (node_1st->left_child && !node_2nd->left_child) { if(Search(root_2nd_1, node_1st->left_child->key)) count++; }// Either one is NULL and the other is not, it is INVALID.
	// 		else if (Search(root_2nd_1, node_1st->left_child->key) && Search(root_2nd_1, node_2nd->left_child->key) && node_1st->left_child->key != node_2nd->left_child->key) count++; // Both are not null and the keys of each nodes are not same, it is INVALID.

	// 		if (!node_1st->right_child && !node_2nd->right_child) ; // When the RIGHT child of the merged BST's node and the 2nd BST's node is NULL, it is VALID.
	// 		else if (!node_1st->right_child && node_2nd->right_child) { if(Search(root_2nd_1, node_2nd->right_child->key)) count++;} // Either one is NULL and the other is not, it is INVALID.
	// 		else if (node_1st->right_child && !node_2nd->right_child) { if(Search(root_2nd_1, node_1st->right_child->key)) count++;} // Either one is NULL and the other is not, it is INVALID.
	// 		else if (Search(root_2nd_1, node_1st->right_child->key) && Search(root_2nd_1, node_2nd->right_child->key) && node_1st->right_child->key != node_2nd->right_child->key) count++; // Both are not null and the keys of each nodes are not same, it is INVALID.
	// 	}
	// 	if (count < invalid) invalid = count;
	// 	Remove(root_1st_1, leaf_1st[i]);
	// 	for (int j = num_2nd - 1; j >= 0; j--) Remove(root_1st_1, keys_2nd[j]);
	// 	Insert(root_1st_1, leaf_1st[i]);
	// 	// printf("count : %d\n", count);
	// }

	// for (int i = 0; i < leaf_len_2; i++) {
	// 	count = 1;
	// 	Remove(root_2nd_1, leaf_2nd[i]);
	// 	for (int j = 0; j < num_1st; j++) Insert(root_2nd_1, keys_1st[j]);
	// 	Insert(root_2nd_1, leaf_2nd[i]);

	// 	for (int j = 0; j < num_1st; j++) {
	// 		node_1st = Search(root_1st_1, keys_1st[j]); // Find the node in the 1st BST with a 2ND key value.
	// 		node_2nd = Search(root_2nd_1, keys_1st[j]); // Find the node in the 2nd BST with a 2ND key value.

	// 		if (!node_1st->left_child && !node_2nd->left_child) ; // When the LEFT child of the merged BST's node and the 2nd BST's node is NULL, it is VALID.
	// 		else if (!node_1st->left_child && node_2nd->left_child) { if(Search(root_1st_1, node_2nd->left_child->key)) count++;} // Either one is NULL and the other is not, it is INVALID.
	// 		else if (node_1st->left_child && !node_2nd->left_child) { if(Search(root_1st_1, node_1st->left_child->key)) count++;} // Either one is NULL and the other is not, it is INVALID.
	// 		else if (Search(root_1st_1, node_1st->left_child->key) && Search(root_1st_1, node_2nd->left_child->key) && node_1st->left_child->key != node_2nd->left_child->key) count++; // Both are not null and the keys of each nodes are not same, it is INVALID.

	// 		if (!node_1st->right_child && !node_2nd->right_child) ; // When the RIGHT child of the merged BST's node and the 2nd BST's node is NULL, it is VALID.
	// 		else if (!node_1st->right_child && node_2nd->right_child) { if(Search(root_1st_1, node_2nd->right_child->key)) count++;} // Either one is NULL and the other is not, it is INVALID.
	// 		else if (node_1st->right_child && !node_2nd->right_child) { if(Search(root_1st_1, node_1st->right_child->key)) count++;} // Either one is NULL and the other is not, it is INVALID.
	// 		else if (Search(root_1st_1, node_1st->right_child->key) && Search(root_1st_1, node_2nd->right_child->key) && node_1st->right_child->key != node_2nd->right_child->key) count++; // Both are not null and the keys of each nodes are not same, it is INVALID.
	// 	}
	// 	if (count < invalid) invalid = count;
	// 	Remove(root_2nd_1, leaf_2nd[i]);
	// 	for (int j = num_1st - 1; j >= 0; j--) Remove(root_2nd_1, keys_1st[j]);
	// 	Insert(root_2nd_1, leaf_2nd[i]);
	// 	// printf("count : %d\n", count);
	// }

	// for (int k = 0; leaf_len_1 >= 2 && k < leaf_len_1 - 1; k++) {
	// 	for (int i = 0; i < leaf_len_1; i++) {
	// 		count = 2;
	// 		Remove(root_2nd_1, leaf_2nd[k]);
	// 		Remove(root_2nd_1, leaf_2nd[i]);
	// 		for (int j = 0; j < num_2nd; j++) Insert(root_1st_1, keys_2nd[j]);
	// 		Insert(root_2nd_1, leaf_2nd[i]);
	// 		Insert(root_2nd_1, leaf_2nd[k]);

	// 		for (int j = 0; j < num_2nd; j++) {
	// 			node_1st = Search(root_1st_1, keys_2nd[j]); // Find the node in the 1st BST with a 2ND key value.
	// 			node_2nd = Search(root_2nd_1, keys_2nd[j]); // Find the node in the 2nd BST with a 2ND key value.

	// 			if (!node_1st->left_child && !node_2nd->left_child) ; // When the LEFT child of the merged BST's node and the 2nd BST's node is NULL, it is VALID.
	// 			else if (!node_1st->left_child && node_2nd->left_child) { if(Search(root_2nd_1, node_2nd->left_child->key)) count++; }// Either one is NULL and the other is not, it is INVALID.
	// 			else if (node_1st->left_child && !node_2nd->left_child) { if(Search(root_2nd_1, node_1st->left_child->key)) count++; }// Either one is NULL and the other is not, it is INVALID.
	// 			else if (Search(root_2nd_1, node_1st->left_child->key) && Search(root_2nd_1, node_2nd->left_child->key) && node_1st->left_child->key != node_2nd->left_child->key) count++; // Both are not null and the keys of each nodes are not same, it is INVALID.

	// 			if (!node_1st->right_child && !node_2nd->right_child) ; // When the RIGHT child of the merged BST's node and the 2nd BST's node is NULL, it is VALID.
	// 			else if (!node_1st->right_child && node_2nd->right_child) { if(Search(root_2nd_1, node_2nd->right_child->key)) count++;} // Either one is NULL and the other is not, it is INVALID.
	// 			else if (node_1st->right_child && !node_2nd->right_child) { if(Search(root_2nd_1, node_1st->right_child->key)) count++;} // Either one is NULL and the other is not, it is INVALID.
	// 			else if (Search(root_2nd_1, node_1st->right_child->key) && Search(root_2nd_1, node_2nd->right_child->key) && node_1st->right_child->key != node_2nd->right_child->key) count++; // Both are not null and the keys of each nodes are not same, it is INVALID.
	// 		}
	// 		if (count < invalid) invalid = count;
	// 		Remove(root_1st_1, leaf_1st[i]);
	// 		for (int j = num_2nd - 1; j >= 0; j--) Remove(root_1st_1, keys_2nd[j]);
	// 		Insert(root_1st_1, leaf_1st[i]);
	// 		// printf("count : %d\n", count);
	// 	}
	// }

	// for (int k = 0; leaf_len_2 >= 2 && k < leaf_len_2 - 1; k++) {
	// 	for (int i = k + 1; i < leaf_len_2; i++) {
	// 		count = 2;
	// 		Remove(root_2nd_1, leaf_2nd[k]);
	// 		Remove(root_2nd_1, leaf_2nd[i]);
	// 		for (int j = 0; j < num_1st; j++) Insert(root_2nd_1, keys_1st[j]);
	// 		Insert(root_2nd_1, leaf_2nd[i]);
	// 		Insert(root_2nd_1, leaf_2nd[k]);

	// 		for (int j = 0; j < num_1st; j++) {
	// 			node_1st = Search(root_1st_1, keys_1st[j]); // Find the node in the 1st BST with a 2ND key value.
	// 			node_2nd = Search(root_2nd_1, keys_1st[j]); // Find the node in the 2nd BST with a 2ND key value.

	// 			if (!node_1st->left_child && !node_2nd->left_child) ; // When the LEFT child of the merged BST's node and the 2nd BST's node is NULL, it is VALID.
	// 			else if (!node_1st->left_child && node_2nd->left_child) { if(Search(root_1st_1, node_2nd->left_child->key)) count++;} // Either one is NULL and the other is not, it is INVALID.
	// 			else if (node_1st->left_child && !node_2nd->left_child) { if(Search(root_1st_1, node_1st->left_child->key)) count++;} // Either one is NULL and the other is not, it is INVALID.
	// 			else if (Search(root_1st_1, node_1st->left_child->key) && Search(root_1st_1, node_2nd->left_child->key) && node_1st->left_child->key != node_2nd->left_child->key) count++; // Both are not null and the keys of each nodes are not same, it is INVALID.

	// 			if (!node_1st->right_child && !node_2nd->right_child) ; // When the RIGHT child of the merged BST's node and the 2nd BST's node is NULL, it is VALID.
	// 			else if (!node_1st->right_child && node_2nd->right_child) { if(Search(root_1st_1, node_2nd->right_child->key)) count++;} // Either one is NULL and the other is not, it is INVALID.
	// 			else if (node_1st->right_child && !node_2nd->right_child) { if(Search(root_1st_1, node_1st->right_child->key)) count++;} // Either one is NULL and the other is not, it is INVALID.
	// 			else if (Search(root_1st_1, node_1st->right_child->key) && Search(root_1st_1, node_2nd->right_child->key) && node_1st->right_child->key != node_2nd->right_child->key) count++; // Both are not null and the keys of each nodes are not same, it is INVALID.
	// 		}
	// 		if (count < invalid) invalid = count;
	// 		Remove(root_2nd_1, leaf_2nd[k]);
	// 		Remove(root_2nd_1, leaf_2nd[i]);
	// 		for (int j = num_1st - 1; j >= 0; j--) Remove(root_2nd_1, keys_1st[j]);
	// 		Insert(root_2nd_1, leaf_2nd[i]);
	// 		Insert(root_2nd_1, leaf_2nd[k]);
	// 		// printf("count : %d\n", count);
	// 	}
	// }

	printf("%d", invalid);
	for (int i = num_1st; i >= 0; i--) {
		Remove(root_1st_1, keys_1st[i]);
		Remove(root_1st_2, keys_1st[i]);
	}
	for (int i = num_2nd; i >= 0; i--) {
		Remove(root_2nd_1, keys_2nd[i]);
		Remove(root_2nd_2, keys_2nd[i]);
	}
	return 0;
}

BSTNode * CreateNode(Key key)
{
	BSTNode * node = (BSTNode*)malloc(sizeof(BSTNode));
	node->key = key;
	node->left_child = NULL;
	node->right_child = NULL;
	return node;
}

void DestroyNode(BSTNode * node)
{
	free(node);
}

bool Verify(BSTNode* root, int min, int max)
{
	if (root != NULL)
	{
		if (root->key < min || root->key > max)
			return false;
		else
			return Verify(root->left_child, min, root->key) && Verify(root->right_child, root->key, max);
	}
	else
	return true;
}

// Iterative version
BSTNode* Search(BSTNode* root, Key key)
{
	BSTNode* cur = root;
	while (cur != NULL) {
		if (cur->key == key) break;
		else if (cur->key > key)
			cur = cur->left_child;
		else
			cur = cur->right_child;
	}
	return cur;
}

// Iterative version
void Insert(BSTNode* root, Key key)
{
	BSTNode* cur = root;
	while (cur != NULL) {
		if (cur->key == key) exit(1);
		else if (cur->key > key) {
			if (cur->left_child == NULL) {
				BSTNode* left = CreateNode(key);
				cur->left_child = left;
				break;
			} else
				cur = cur->left_child;
		}
		else {
			if (cur->right_child == NULL) {
				BSTNode* right = CreateNode(key);
				cur->right_child = right;
				break;
			} else
				cur = cur->right_child;
		}
	}
}

void Remove(BSTNode* root, Key key)
{
	BSTNode* cur = root, * parent = NULL;
	while (cur != NULL && cur->key != key) {
		parent = cur;
		if (cur->key > key)
			cur = cur->left_child;
		else
			cur = cur->right_child;
	}
	if (cur == NULL) exit(1);
	if (cur->left_child == NULL && cur->right_child == NULL) {
		if (parent != NULL) {
			if (parent->left_child == cur)
				parent->left_child = NULL;
			else
				parent->right_child = NULL;
		}
		else
			cur = NULL;
	}
	else if (cur->left_child == NULL || cur->right_child == NULL) {
		BSTNode* child;
		if (cur->left_child != NULL)
			child = cur->left_child;
		else
			child = cur->right_child;
		if (parent != NULL) {
			if (parent->left_child == cur)
				parent->left_child = child;
			else
				parent->right_child = child;
		}
	}
	else {
		BSTNode* succ_parent = cur, *succ = cur->right_child;
		while (succ->left_child != NULL) {
			succ_parent = succ;
			succ = succ->left_child;
		}
		if (succ_parent->right_child == succ)
			succ_parent->right_child = succ->right_child;
		else
			succ_parent->left_child = succ->right_child;
		cur->key = succ->key;
		cur = succ;
	}
	DestroyNode(cur);
}
