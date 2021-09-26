#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 200
typedef struct {
	char aminoL;
	char aminoR;
} element;
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} DequeType;
typedef struct ListNode { 	// 노드 타입
	char data;
	struct ListNode* link;
} ListNode;


// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화 
void init_deque(DequeType* q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(DequeType* q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(DequeType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
void deque_print(DequeType* q)
{
	printf("DEQUE(front=%d rear=%d) :\n ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%c-%c \n ", q->data[i].aminoL, q->data[i].aminoR);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// 삽입 함수
void add_rear(DequeType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element delete_front(DequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 삭제 함수
element get_front(DequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType* q, char c)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	element val;
	val.aminoL = c;
	if (c == 'A') { val.aminoR = 'T'; }
	else if (c == 'T') { val.aminoR = 'A'; }
	else if (c == 'G') { val.aminoR = 'C'; }
	else if (c == 'C') { val.aminoR = 'G'; }
	else error("잘못된 입력입니다");


	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType* q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[q->rear];
}

ListNode* insert_first(ListNode* head, char value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// 헤드 포인터의 값을 복사	//(3)
	head = p;	// 헤드 포인터 변경		//(4)
	return head;	// 변경된 헤드 포인터 반환
}

// 노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, char value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = pre->link;	//(3)	
	pre->link = p;		//(4)	
	return head;		//(5)	
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;	// (1)
	head = removed->link;	// (2)
	free(removed);		// (3)
	return head;		// (4)
}

ListNode* delete_list(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;		// (2)
	free(removed);			// (3)
	return head;			// (4)
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%c->", p->data);
	printf("NULL \n");
}

ListNode* transcribe(DequeType* q, char side)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");	// determine vacancy of queue.

	ListNode* r = NULL;

	if (side == 'L')	// create list of RNA of left amino acid.
	{
		while (!is_empty(q))
		{
			char dna_p = delete_front(q).aminoL;
			char rna_p;
			if (dna_p == 'T')
				rna_p = 'U';
			else
				rna_p = dna_p;
			r = insert_first(r, rna_p);
		}
	}

	if (side == 'R')	// create list of RNA of right amino acid.
	{
		while (!is_empty(q))
		{
			char dna_p = delete_front(q).aminoR;
			char rna_p;
			if (dna_p == 'T')
				rna_p = 'U';
			else
				rna_p = dna_p;
			r = insert_first(r, rna_p);
		}
	}

	return r;
}

void translate(ListNode* head)
{
	if (head == NULL)
		error("3>!");

	while (head != NULL)
	{
		char rna3[4] = { NULL, };
		char* protein = (char*)malloc(sizeof(char) * 5);
		memset(protein, NULL, sizeof(char) * 5);

		for (int i = 0; i < 3; i++)	// create rna's 3-amino-acid string.  
		{
			if (head == NULL)	// verify wheter the number of remaining amino acid is less than 3
				error("3>!");	// by determining head is NULL
			else
				rna3[i] = head->data;
			head = delete_first(head);
		}

		if (!strcmp(rna3, "UAA") || !strcmp(rna3, "UAG") || !strcmp(rna3, "UGA"))	// create translated protein string
		{
			free(protein);
			error("stop!");
		}
		else if (!strncmp(rna3, "GU", 2))
			strcpy(protein, "Val");
		else if (!strncmp(rna3, "GC", 2))
			strcpy(protein, "Ala");
		else if (!strcmp(rna3, "GAU") || !strcmp(rna3, "GAC"))
			strcpy(protein, "Asp");
		else if (!strcmp(rna3, "GAA") || !strcmp(rna3, "GAG"))
			strcpy(protein, "Glu");
		else if (!strncmp(rna3, "GG", 2))
			strcpy(protein, "Gly");
		else if (!strcmp(rna3, "UUU") || !strcmp(rna3, "UUC"))
			strcpy(protein, "Phe");
		else if (!strcmp(rna3, "UUA") || !strcmp(rna3, "UUG"))
			strcpy(protein, "Leu");
		else if (!strncmp(rna3, "UC", 2))
			strcpy(protein, "Ser");
		else if (!strcmp(rna3, "UAU") || !strcmp(rna3, "UAC"))
			strcpy(protein, "Tyr");
		else if (!strcmp(rna3, "UGU") || !strcmp(rna3, "UGC"))
			strcpy(protein, "Cys");
		else if (!strcmp(rna3, "UGG"))
			strcpy(protein, "Trp");
		else if (!strncmp(rna3, "CU", 2))
			strcpy(protein, "Leu");
		else if (!strncmp(rna3, "CC", 2))
			strcpy(protein, "Pro");
		else if (!strcmp(rna3, "CAC") || !strcmp(rna3, "CAU"))
			strcpy(protein, "His");
		else if (!strcmp(rna3, "CAA") || !strcmp(rna3, "CAG"))
			strcpy(protein, "Gin");
		else if (!strncmp(rna3, "CG", 2))
			strcpy(protein, "Arg");
		else if (!strcmp(rna3, "AUG"))
			strcpy(protein, "Met");
		else if (!strncmp(rna3, "AU", 2))
			strcpy(protein, "Ile");
		else if (!strncmp(rna3, "AC", 2))
			strcpy(protein, "Thr");
		else if (!strcmp(rna3, "AAC") || !strcmp(rna3, "AAU"))
			strcpy(protein, "Asna");
		else if (!strcmp(rna3, "AAA") || !strcmp(rna3, "AAG"))
			strcpy(protein, "Lys");
		else if (!strcmp(rna3, "AGU") || !strcmp(rna3, "AGC"))
			strcpy(protein, "Ser");
		else if (!strcmp(rna3, "AGA") || !strcmp(rna3, "AGG"))
			strcpy(protein, "Arg");

		if (head == NULL)
			printf("%s", protein);	// print last element of traslated protein.
		else
			printf("%s-", protein);	// print elements of tralslated protein.

		free(protein);
	}
}

int main(void)
{
	DequeType queue;

	init_deque(&queue);

	char dna[100];
	printf("Please input DNA sequence: ");
	gets(dna);
	int len = strlen(dna);

	for (int i = 0; i < len; i++) {

		add_front(&queue, dna[i]);

	}

	deque_print(&queue);

	//RNA Transcribe start


	ListNode* rna = NULL;

	rna = transcribe(&queue, 'L');

	print_list(rna);

	//RNA Translate start

	translate(rna);

	return 0;
}