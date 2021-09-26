#include "queue.h"

/* FYI, predefined macro and data types are as below.  */
/*
#define MAX_QUEUE	100

typedef int DATA_TYPE

typedef struct queue_t{
	int front, rear;
	DATA_TYPE items[MAX_QUEUE];
}queue_t;
*/

void init_queue(queue_t* queue){

	/* write your own code here. */
	queue->front = 0;
	queue->rear = 0;
}

bool is_full(queue_t* queue){
	bool res;
	
	/* write your own code here. */
	if (queue->front == ((queue->rear + 1) % MAX_QUEUE)) res = true;
	else res = false;

	return res;
}

bool is_empty(queue_t* queue){
	bool res;
	
	/* write your own code here. */
	if (queue->front == queue->rear) res = true;
	else res = false;

	return res;
}

DATA_TYPE peek(queue_t* queue){
	DATA_TYPE res;

	/* write your own code here. */
	if (is_empty(queue)) {
		printf("Queue is empty.\n");
		return -1;
	}
	else res = queue->items[queue->front];

	return res;
}
void enqueue(queue_t* queue, DATA_TYPE item){

	/* write your own code here. */
	if (is_full(queue)) printf("Queue if full.\n");
	else {
		queue->items[queue->rear] = item;
		queue->rear = (queue->rear + 1) % MAX_QUEUE;
	}
}

void dequeue(queue_t* queue){

	/* write your own code here. */
	if (is_empty(queue)) printf("Queue is empty.\n");
	else queue->front = (queue->front + 1)  % MAX_QUEUE;
}


//DO NOT define main function 
