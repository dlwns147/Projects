#include <stdbool.h>
#define MAX_QUEUE	100

typedef int DATA_TYPE;

typedef struct queue_t{
	int front, rear;
	DATA_TYPE items[MAX_QUEUE];
}queue_t;

void init_queue(queue_t*);	// Make a queue empty.
bool is_full(queue_t*);	// Check wheter a queue is full.
bool is_empty(queue_t*);	// Check wheter a queue is empty.

DATA_TYPE peek(queue_t*);	// Read the item at the front. This function will be called only if the queue is not empty.
void enqueue(queue_t*, DATA_TYPE);	// Insert an item at the rear.
void dequeue(queue_t*);		// Delete an item at the front
