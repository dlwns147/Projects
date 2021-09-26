#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/* predefined data types are as below.  */

typedef struct GNode{int id; struct GNode* next;} GNode;
typedef struct{int num; GNode** heads;} Graph;

void CreateGraph(Graph* pgraph, int num);		// Create a graph
void DestroyGraph(Graph* pgraph);				// Destroy a graph
void AddEdge(Graph* pgraph, int src, int dest);	// Add an undirected edge from src to dest

/* you can define any variables or functions you need */

typedef struct Cycle{ char len;	short sum; } cycle;
int CYCLES_LEN = 0;
char *VISITED;
cycle *CYCLES;
Graph graph;

void DFS(int vtx, int start, int degree, int sum) {

	// printf("vtx: %d start: %d deg: %d sum: %d\n", vtx, start, degree, sum);
	VISITED[vtx] = 1;
	GNode *ptr = graph.heads[vtx]->next;
	while (degree > 2 && ptr != NULL) {
		// printf("while, id : %d, start : %d\n", ptr->id, start);
		if (ptr->id == start) {
			// printf("HERE\n");
			// Compare with already existing cycles.
			if (CYCLES_LEN == 0) {
				CYCLES[CYCLES_LEN].len = degree;
				CYCLES[CYCLES_LEN].sum = sum;
				CYCLES_LEN++;
			}
			else {
				for (int i = 0; i < CYCLES_LEN; i++) {
					// printf("for\n");
					if (CYCLES[i].len == degree && CYCLES[i].sum == sum)
						break;

					if (i == CYCLES_LEN - 1) {
						CYCLES[CYCLES_LEN].len = degree;
						CYCLES[CYCLES_LEN].sum = sum;
						CYCLES_LEN++;
					}
				}
			}
			break;
		}
		ptr = ptr->next;
	}
	ptr = graph.heads[vtx]->next;
	while (ptr != NULL) {
		if (VISITED[ptr->id] == 0) DFS(ptr->id, start, degree + 1, sum + (1 << ptr->id));
		ptr = ptr->next;
	}
	VISITED[vtx] = 0;
}

int main()
{
	/* write your own code here */
	int vertex;
	int edge;
	int start_vertex;
	int end_vertex;
	
	// vertex = 10;
	// edge = 45;

	scanf("%d %d", &vertex, &edge);
	CreateGraph(&graph, vertex);
	for (int i = 0; i < edge; i++) {
		scanf("%d %d", &start_vertex, &end_vertex);
		AddEdge(&graph, start_vertex, end_vertex);
	}

	// AddEdge(&graph, 0, 1); AddEdge(&graph, 1, 3); AddEdge(&graph, 2, 3); AddEdge(&graph, 0, 2);

	// AddEdge(&graph, 0, 1); AddEdge(&graph, 1, 2); AddEdge(&graph, 1, 3); AddEdge(&graph, 1, 4);
	// AddEdge(&graph, 2, 3); AddEdge(&graph, 2, 4); AddEdge(&graph, 3, 4);

	// for (int i = 0; i < vertex; i++) 
	// 	for (int j = i + 1; j < vertex; j++)
	// 		AddEdge(&graph, i, j);
	
	VISITED = (char *)calloc(sizeof(char), vertex);
	CYCLES = (cycle *)calloc(sizeof(cycle), 1000); // Max number of cycles = 1000
	for (int i = 0; i < vertex; i++) {
		DFS(i, i, 1, (1 << i));
		// printf("\n");
		// memset(VISITED, 0, sizeof(char) * vertex);
	}
	printf("%d", CYCLES_LEN);
	DestroyGraph(&graph);
	free(VISITED);
	free(CYCLES);
	
	return 0;
}

void CreateGraph(Graph* pgraph, int num){
	pgraph->num = num;
	pgraph->heads = (GNode **)malloc(sizeof(GNode*)* num);
	int i;
	for (i = 0; i < num; i++){
		pgraph->heads[i] = (GNode *)malloc(sizeof(GNode));
		pgraph->heads[i]->next = NULL;
	}
}

void DestroyGraph(Graph* pgraph){
	int i;
	for (i = 0; i < pgraph->num; i++){
		GNode* cur = pgraph->heads[i];
		while (cur != NULL){
			GNode* temp = cur;
			cur = cur->next;
			free(temp);
		}
	}
	free(pgraph->heads);
}

void AddEdge(Graph* pgraph, int src, int dest){
	GNode* newNode1, *newNode2, *cur;
	
	newNode1 = (GNode *)malloc(sizeof(GNode));
	newNode1->id = dest;
	newNode1->next = NULL;
	
	cur = pgraph->heads[src];
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = newNode1;
	
	newNode2 = (GNode *)malloc(sizeof(GNode));
	newNode2->id = src;
	newNode2->next = NULL;
	
	cur = pgraph->heads[dest];
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = newNode2;
}
