#ifndef BANK_QUEUE_H
#define BANK_QUEUE_H

#include <stdbool.h>

typedef int Token;
typedef struct queue_type *Queue;

Queue queue_create(void);
void queue_destroy(Queue q);
bool queue_is_empty(Queue q);
bool queue_is_full(Queue q);
Token get_token(Queue q);           /* enqueue */
Token customer_to_serve(Queue q);   /* dequeue */
Token customer_at_the_front_of_queue(Queue q);  /* peak front */
Token customer_at_the_end_of_queue(Queue q);    /* peak rear */

#endif
