#include <stdio.h>
#include "linkedlist.h"

int main(void) {
	linkedlist_t list;
	init_list(&list);
	printf("%s\n", (is_empty(&list) ? "True" : "False"));
	insert_first(&list, 'a');
	insert_first(&list, 'b');
	insert_first(&list, 'c');
	insert_first(&list, 'd');
	print(&list);

	return 0;
}