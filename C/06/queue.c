#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

typedef struct node {
    int data;
    struct node *next;
} *Node;

struct queue_type {
    Node rear;       /* pointer to the tail of the linked list */
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
} /* end function terminate */

Queue queue_create(void)
{
    Queue q = malloc(sizeof(struct queue_type));
    q->rear = NULL;
    return q;
} /* end function queue_create */

void queue_destroy(Queue q)
{
    if (q->rear == NULL) {
         free(q);
         return;
    }
    Node temp = q->rear->next;
    while (temp->next != temp) {
        q->rear->next = temp->next;
        free(temp);
        temp = q->rear->next;
    }
    free(temp);
    free(q);
} /* end function queue_destroy */

bool is_empty(Queue q)
{
    return q->rear == NULL;
} /* end function is_empty */

bool is_full(Queue q)
{
    return false;
} /* end function is_full */

void enqueue(Queue q, Item value)
{
    if (is_full(q))
        terminate("Error in push: Queue is full!");

    Node new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push: Cannot create node!");
    new_node->data = value;
    
    if (is_empty(q)) {
        new_node->next = new_node;
        q->rear = new_node;
        return;
    }
    new_node->next = q->rear->next;
    q->rear->next = new_node;
    q->rear = new_node;
    
} /* end function enqueue */

Item dequeue(Queue q)
{
    if (is_empty(q))
        terminate("Error in pop: queue is empty!");

    Item value_to_return;
    /* if only one node is present */
    if (q->rear == q->rear->next) {
        value_to_return = q->rear->data;
        free(q->rear);
        q->rear = NULL;
    }
    else {
        Node to_delete = q->rear->next;
        value_to_return = to_delete->data;
        q->rear->next = to_delete->next;
        free(to_delete);
    }
    return value_to_return;
} /* end function dequeue */

Item rear(Queue q)
{
    if (is_empty(q))
        terminate("Error in peek: Queue is empty!");
    return q->rear->data;
} /* end function rear */

Item front(Queue q)
{
    if (is_empty(q))
        terminate("Error in peek: Queue is empty!");
    return q->rear->next->data;
} /* end function front */

