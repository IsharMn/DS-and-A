#ifndef STRING_STACK_H
#define STRING_STACK_H

#include <stdbool.h>

#define STRING_SIZE 50

typedef struct stack_type *Stack; /* Stack is a pointer to an incomplete struct with tag stack_type */

Stack stack_create(void);               /* initializes a stack and returns a pointer to it */
void stack_destroy(Stack s);            /* frees the stack 's' from memory */
bool stack_is_empty(Stack s);           /* checks if the stack 's' is empty */
bool stack_is_full(Stack s);            /* checks if the stack 's' is full */
void stack_push(Stack s, char *string); /* adds a string onto the stack 's' */
char *stack_pop(Stack s);               /* removes and returns a string from the top of the stack 's' */ 
char *stack_top(Stack s);               /* returns a string from the top of the stack 's' */

#endif
