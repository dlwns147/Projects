#if defined(_MSC_VER)
   #define _CRT_SECURE_NO_WARININGS
#endif

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int DATA;

typedef struct _Node
{
	int coef;
	int exp;
	struct _Node* next;
} Node;

typedef struct 
{
	Node* tail;
	int len;
} Polynomial;

Polynomial* create_polynomial();
Node* create_or_insert_node(Polynomial* plist, int coef, int exp);
void insert_first(Polynomial* plist, int coef, int exp);
void insert_last(Polynomial* plist, int coef, int exp);
bool is_empty(Polynomial* plist);
void remove_init(Polynomial* plist);
void print(Polynomial* plist);

// Each polynomial represented by a linked list, and each node is defined as a coef(coefficient), exp(exponential), and *next structure.
// ex) 7x - 2 ( []: node, ->: link )
// [7x]->[-2]
void add_polynomials(Polynomial* poly_a, Polynomial* poly_b, Polynomial* result)
{
	// Implement your answer here
	int cmp = 0;
		Node *a = poly_a->tail->next;
		Node *b = poly_b->tail->next;
	while (a != poly_a->tail || b != poly_b->tail) {
		if (a->exp > b->exp) {
			insert_first(result, a->coef, a->exp);
			a = a->next;
		}
		else if (a->exp < b->exp) {
			insert_first(result, b->coef, b->exp);
			b = b->next;
		}
		else {
			insert_first(result, a->coef + b->coef, a->exp);
			a = a->next;
			b = b->next;
		}
		cmp++;
	}
}

int main()
{
	/* DO NOT modify main function*/
	Polynomial* a = create_polynomial();
	insert_last(a, 3, 14);
	insert_last(a, 2, 7);
	insert_last(a, 2, 0);

	Polynomial* b = create_polynomial();
	insert_last(b, 5, 14);
	insert_last(b, -3, 8);
	insert_last(b, 7, 6);

	Polynomial* result = create_polynomial();
	add_polynomials(a, b, result);

	print(result);

	free(a);
	free(b);
	free(result);

	return 0;
	/* DO NOT modify main function*/
}

Polynomial* create_polynomial()
{
	Polynomial* p = (Polynomial*)malloc(sizeof(Polynomial));
	p->len = 0;
	p->tail = NULL;

	return p;
}

Node* create_or_insert_node(Polynomial* plist, int coef, int exp)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->coef = coef;
	newNode->exp = exp;

	if (plist->len == 0) {
		newNode->next = newNode;
		plist->tail = newNode;
	}
	else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}

	plist->len++;
	return newNode;
}

void insert_first(Polynomial* plist, int coef, int exp)
{
	create_or_insert_node(plist, coef, exp);
}

void insert_last(Polynomial* plist, int coef, int exp)
{
	plist->tail = create_or_insert_node(plist, coef, exp);
}

bool is_empty(Polynomial* plist)
{
	return plist->len == 0;
}

void remove_init(Polynomial* plist)
{
	if (is_empty(plist)) exit(1);

	if (plist->len == 1) {
		free(plist->tail);
		plist->len--;
		plist->tail = NULL;
	}
}

void remove_first(Polynomial* plist)
{
	if (plist->len == 1)
		remove_init(plist);
	else {
		Node* temp = plist->tail->next;
		plist->tail->next = temp->next;

		free(temp);
		plist->len--;
	}
}

void remove_last(Polynomial* plist)
{
	if (plist->len == 1)
		remove_init(plist);
	else {
		Node* cur, * temp;
		cur = plist->tail;
		for (int i = 0; i < plist->len - 1; i++)
			cur = cur->next;
		temp = cur->next;
		cur->next = temp->next;

		free(temp);
		plist->tail = cur;
		plist->len--;

	}
}

char swap(char a, char b)
{
	char tmp = a;
	a = b;
	b = tmp;
}

void reverse(char str[], int len)
{
	int start = 0;
	int end = len - 1;
	while(start < end)
	{
		swap(*(str+start), *(str+end));
		start++;
		end--;
	}
}

char* int_to_string(int num, char* str)
{
	int i = 0;
	if(num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}

	bool is_negative = num < 0;
	if(is_negative)	num = -num;

	while(num != 0)
	{
		int rem = num % 10;
		str[i++] = rem + '0';
		num = num / 10;
	}

	if(is_negative) str[i++] = '-';
	str[i] = '\0';

	reverse(str, i);
	return str;
}

void print(Polynomial* plist)
{
	char str_poly[1024] = "";
	char var[8] = "";
	Node* cur = plist->tail;

	for (int i = 0; i < plist->len; i++)
	{
		cur = cur->next;
		if (cur->coef > 0 && i > 0) strcat(str_poly, "+");
		strcat(str_poly, int_to_string(cur->coef, var));
		if (cur->exp != 0) {
			strcat(str_poly, "x");
			strcat(str_poly, "^");
			strcat(str_poly, int_to_string(cur->exp, var));
		}
	}

	printf("%s", str_poly);
}

