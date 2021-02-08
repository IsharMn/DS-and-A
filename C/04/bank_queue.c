#include <stdio.h>
#include <stdlib.h>
#include "bank_queue.h"

#define QUEUE_SIZE 10

struct queue_type {
    Token contents[QUEUE_SIZE];
    int front;
    int rear;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
} /* end function terminate */

Queue queue_create(void)
{
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error: Could not create queue!");
    q->front = -1;
    q->rear = -1;
    return q;
} /* end function queue_create */

void queue_destroy(Queue q)
{
    free(q);
} /* end function queue_destroy */

bool queue_is_empty(Queue q)
{
    return q->front == -1;
} /* end function queue_is_empty */

bool queue_is_full(Queue q)
{
    return q->rear == QUEUE_SIZE - 1;
} /* end function queue_is_full */

Token get_token(Queue q)
{
    if (queue_is_full(q))
        terminate("Error in enqueue: Queue is full!");
    q->rear++;
    q->contents[q->rear] = q->rear + 100;
    if (queue_is_empty(q))
        q->front++;
    printf("Customer added to queue. Token: %d\n", q->contents[q->rear]);
    return q->contents[q->rear];
} /* end function get_token */

Token customer_to_serve(Queue q) 
{
    if (queue_is_empty(q))
        terminate("Error in dequeue: Queue is empty");
    Token value_to_return = q->contents[q->front++];
    if (q->front > q->rear)
        q->front = q->rear = -1;
    return value_to_return;
} /* end function customer_to_serve */

Token customer_at_the_front_of_queue(Queue q)
{
    if (queue_is_empty(q))
        terminate("Error in peek: Queue is empty!");
    return q->contents[q->front];
} /* end function customer_at_the_front_of_queue */

Token customer_at_the_end_of_queue(Queue q)
{
    if (queue_is_empty(q))
        terminate("Error in peek: Queue is empty!");
    return q->contents[q->rear];
} /* end function customer_at_the_end_of_queue */
