#if defined(_MSC_VER)
   #define _CRT_SECURE_NO_WARININGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE 100
#define N 5

typedef struct { int front, rear; int items[MAX_QUEUE];} Queue;

void InitQueue(Queue *pqueue);
bool IsFull(Queue *pqueue);
bool IsEmpty(Queue *pqueue);
int Peek(Queue *pqueue);
void EnQueue(Queue *pqueue, int item);
void DeQueue(Queue *pqueue);

typedef struct _GNode { int id; struct _GNode* next;} GNode;
typedef struct { int num; GNode** heads;} Graph;

void CreateGraph(Graph* pgraph, int num);
void DestroyGraph(Graph* pgraph);
void AddEdge(Graph* pgraph, int src, int dest);

// HavePath returns true if at least one path exists between src and dest, and returns false if not.
bool HavePath(Graph* pgraph, int src, int dest)
{
	if (src == dest) return true;
	
	bool visited[N];
	for (int i = 0; i < N; i++)
		visited[i] = false;
	
	Queue queue;
	InitQueue(&queue);
	EnQueue(&queue, src);
	
	visited[src] = true;
	while (!IsEmpty(&queue)) {
		/* implement your answer here. Do not change anywhere else. */
		int temp = Peek(&queue);
		DeQueue(&queue);
		GNode *cur = pgraph->heads[temp]->next;
		while (cur != NULL) {
			if (cur->id == dest) return true;
			if (!visited[cur->id]) {
				EnQueue(&queue, cur->id);
				visited[cur->id] = true;
			}
			cur = cur->next;
		}
	}
	return false;
}

int main()
{
	Graph g;
	CreateGraph(&g, N);
	
	AddEdge(&g, 1, 0);
	AddEdge(&g, 1, 2);
	AddEdge(&g, 1, 3);
	AddEdge(&g, 2, 3);
	AddEdge(&g, 2, 4);
	AddEdge(&g, 3, 4);
	AddEdge(&g, 4, 1);
	AddEdge(&g, 4, 3);
	
	int score = 0;
	
	if (HavePath(&g, 0, 1) == false) score++;
	if (HavePath(&g, 0, 2) == false) score++;
	if (HavePath(&g, 0, 3) == false) score++;
	if (HavePath(&g, 0, 4) == false) score++;
	if (HavePath(&g, 1, 0) == true) score++;
	if (HavePath(&g, 1, 2) == true) score++;
	if (HavePath(&g, 1, 3) == true) score++;
	if (HavePath(&g, 1, 4) == true) score++;
	if (HavePath(&g, 2, 0) == true) score++;
	if (HavePath(&g, 2, 1) == true) score++;
	if (HavePath(&g, 2, 3) == true) score++;
	if (HavePath(&g, 2, 4) == true) score++;
	if (HavePath(&g, 3, 0) == true) score++;
	if (HavePath(&g, 3, 1) == true) score++;
	if (HavePath(&g, 3, 2) == true) score++;
	if (HavePath(&g, 3, 4) == true) score++;
	if (HavePath(&g, 4, 0) == true) score++;
	if (HavePath(&g, 4, 1) == true) score++;
	if (HavePath(&g, 4, 2) == true) score++;
	if (HavePath(&g, 4, 3) == true) score++;
	
	if (score == 20) printf("RIGHT!");
	else printf("WRONG!");
}

void InitQueue(Queue *pqueue)
{
	pqueue->front = pqueue->rear = 0;
}

bool IsFull(Queue *pqueue)
{
	return pqueue->front == (pqueue->rear + 1) % MAX_QUEUE;
}

bool IsEmpty(Queue *pqueue)
{
	return pqueue->front == pqueue->rear;
}

int Peek(Queue *pqueue)
{
	if (IsEmpty(pqueue))
		exit(1);
	return pqueue->items[pqueue->front];
}

void EnQueue(Queue *pqueue, int item)
{
	if (IsFull(pqueue))
		exit(1);
	pqueue->items[pqueue->rear] = item;
	pqueue->rear = (pqueue->rear + 1) % MAX_QUEUE;
}

void DeQueue(Queue *pqueue)
{
	if (IsEmpty(pqueue))
		exit(1);
	pqueue->front = (pqueue->front + 1) % MAX_QUEUE;
}


void CreateGraph(Graph* pgraph, int num)
{
	pgraph->num = num;
	pgraph->heads = (GNode **)malloc(sizeof(GNode*)* num);
	for (int i = 0; i < num; i++) {
		pgraph->heads[i] = (GNode *)malloc(sizeof(GNode));
		pgraph->heads[i]->next = NULL;
	}
}

void DestroyGraph(Graph* pgraph)
{
	for (int i = 0; i < pgraph->num; i++) {
		GNode* cur = pgraph->heads[i];
		while (cur != NULL) {
			GNode* temp = cur;
			cur = cur->next;
			free(temp);
		}
	}
	free(pgraph->heads);
}

void AddEdge(Graph* pgraph, int src, int dest)
{
	GNode* newNode, *cur;
	
	newNode = (GNode *)malloc(sizeof(GNode));
	newNode->id = dest;
	newNode->next = NULL;
	
	cur = pgraph->heads[src];
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = newNode;
}
