#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "B+TREE.h"

int main(void) {
	BPLUSTreeInit(3); // Max degree 3
	insertElement(1); insertElement(3); insertElement(7); insertElement(10); insertElement(11); insertElement(13);	insertElement(14);
	insertElement(15); insertElement(18); insertElement(16); insertElement(19); insertElement(24); insertElement(25); insertElement(26);
	printTree();
	printf("\n");

	removeElement(13);
	printTree();
	printf("\n");

	BPLUSTreeInit(4); // Max degree 4
	insertElement(1); insertElement(3); insertElement(7); insertElement(10); insertElement(11); insertElement(13);	insertElement(14);
	insertElement(15); insertElement(18); insertElement(16); insertElement(19); insertElement(24); insertElement(25); insertElement(26);
	printTree();
	printf("\n");

	removeElement(13);
	printTree();
	printf("\n");
	
	return 0;
}
