#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int Item;
typedef struct queue_type *Queue;

Queue queue_create(void);   /* initializes a queue and returns a pointer to it */
void queue_destroy(Queue q); /* frees the queue from memory */
bool is_empty(Queue q);     /* checks if the queue is empty */
bool is_full(Queue q);      /* checks if the queue is full */
void enqueue(Queue q, Item value); /* adds an element onto the queue */ 
Item dequeue(Queue q);      /* removes and returns an element from the front of the queue */
Item rear(Queue q);         /* returns the element at the end of the queue */
Item front(Queue q);        /* returns the element at the front of the queue */ 

#endif
