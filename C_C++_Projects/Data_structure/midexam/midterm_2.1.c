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

// 오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화 
void init_deque(DequeType *q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(DequeType *q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(DequeType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
void deque_print(DequeType *q)
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
void add_rear(DequeType *q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element delete_front(DequeType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 삭제 함수
element get_front(DequeType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType *q, char c)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	element val;
	val.aminoL = c;
	if (c =='A') {val.aminoR = 'T';}
	else if (c =='T') {val.aminoR = 'A';}
	else if (c =='G') {val.aminoR = 'C';}
	else if (c =='C') {val.aminoR = 'G';}
	else error("잘못된 입력입니다");


	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType *q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[q->rear];
}

int main(void)
{
	DequeType queue;

	init_deque(&queue);

	char dna[100]; 
	printf("Please input DNA sequence: ");
	gets(dna);
	int len = strlen(dna);

	for (int i = 0; i<len; i++){
		
		add_front(&queue, dna[i]);


	}
	
	deque_print(&queue);
	return 0;
}