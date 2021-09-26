#include "linkedlist.h"

/* FYI, predefined macro and data types are as below.  */
/*
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
*/

void init_list(linkedlist_t* plist)
{
	/* write your own code here. */
	plist->head = 0;
	plist->len = 0;
}

bool is_empty(linkedlist_t* plist)
{
	bool ret;

	/* write your own code here. */
	if (plist->len == 0) ret = true;
	else ret = false;

	return ret;
}

void insert_first(linkedlist_t* plist, DATA_TYPE item)
{
	/* write your own code here. */
	node *new = (node *)malloc(sizeof(node));
	new->item = item;
	new->next = plist->head;
	plist->head = new;
	plist->len++;
}

void insert_middle(linkedlist_t* plist, int pos, DATA_TYPE item)
{
	/* write your own code here. */
	if (pos > plist->len || pos < 0) printf("input value is invalid.\n");
	else {
		node *temp = plist->head;
		for (int i = 0; i < pos - 1; i++) temp = temp->next;
		
		node *new = (node *)malloc(sizeof(node));
		new->item = item;
		new->next = temp->next;
		temp->next = new;
		plist->len++;
	}
}

void insert_last(linkedlist_t* plist, DATA_TYPE item)
{
	/* write your own code here. */
	node *temp = plist->head;
	for (int i = 0; i < plist->len; i++) temp = temp->next;
	
	node *new = (node *)malloc(sizeof(node));
	new->item = item;
	new->next = temp->next;
	temp->next = new;
	plist->len++;
}

void remove_first(linkedlist_t* plist)
{
	/* write your own code here. */
	node *temp = plist->head;
	plist->head = plist->head->next;
	free(temp);
}

void remove_middle(linkedlist_t* plist, int pos)
{
	/* write your own code here. */
	node *cur = plist->head;
	for (int i = 0; i < pos - 1;i++) cur = cur->next;
	node *temp = cur->next;
	cur->next = cur->next->next;
	free(temp);
}

DATA_TYPE read_item(linkedlist_t* plist, int pos)
{
	DATA_TYPE ret;

	/* write your own code here. */
	node *cur = plist->head;
	for (int i = 0; i < pos;i++) cur = cur->next;
	ret = cur->item;

	return ret;
}

void replace_item(linkedlist_t* plist, int pos, DATA_TYPE orig, DATA_TYPE rep)
{
	/* write your own code here. */
	if (pos < 0 || pos > plist->len) printf("input value is invalid.\n");
	node *cur = plist->head;
	for (int i = 0; i < pos - 1; i++) {
		if (cur->item == orig) {
			node *new = (node *)malloc(sizeof(node));
			new->item = rep;

		}
		cur = cur->next;
	}
}

void print(linkedlist_t* plist)
{
	/* write your own code here. */
	for(node *cur = plist->head; cur != 0; cur = cur->next)
		printf("%c", cur->item);

}

void clear(linkedlist_t* plist)
{
	/* write your own code here. */
	if (is_empty(plist)) printf("linked list is empty.\n");
	else {
		if (plist->len == 1) free(plist->head);
		else {
			node *cur = plist->head;
			node *temp;
			for (int i = 0; i < plist->len; i++) {
				temp = cur;
				cur = cur->next;
				free(temp);
			}
		}
	}


}

//NOTE: DO NOT define main function 