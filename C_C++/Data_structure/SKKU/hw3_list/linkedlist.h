#pragma once

#include <stdbool.h>

typedef char DATA_TYPE;

typedef struct node_t
{
	DATA_TYPE item;
	struct node_t* next;
} node;

typedef struct
{
	node* head;
	int len;
} linkedlist_t;

void init_list(linkedlist_t* plist);										// initialize to a linked-list.
bool is_empty(linkedlist_t* plist);											// check wheter a linked-list is full
void insert_first(linkedlist_t* plist, DATA_TYPE item);						// insert an item to the first position
void insert_middle(linkedlist_t* plist, int pos, DATA_TYPE item);			// insert an item at the k-th position
void insert_last(linkedlist_t* plist, DATA_TYPE item);						// insert an item to the last position
void remove_first(linkedlist_t* plist);										// remove an item to the first position
void remove_middle(linkedlist_t* plist, int pos);							// remove an item at the k-th position
DATA_TYPE read_item(linkedlist_t* plist, int pos);							// read an item at the k-th position
void replace_item(linkedlist_t* plist, int pos, DATA_TYPE orig, DATA_TYPE rep);	// change an item at the k-th position(NOTE: implement using remove and insert function)
void print(linkedlist_t* plist);											// print each item in a linked-list in sequence
void clear(linkedlist_t* plist);											// remove all nodes in a linked-list in sequence