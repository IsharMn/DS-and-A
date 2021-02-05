#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef char Item;                  /* change here for support for different type */
typedef struct stack_type *Stack;   /* Stack is a pointer to an incomplete struct with tag stack_type */

Stack stack_create(void);           /* initializes a stack and returns a pointer to it */
void stack_destroy(Stack s);        /* frees the stack 's' from memory */
bool stack_is_empty(Stack s);       /* checks if the stack 's' is empty */
bool stack_is_full(Stack s);        /* checks if the stack 's' is full */
void stack_push(Stack s, Item i);   /* adds an element of type Item onto the stack 's' */
Item stack_pop(Stack s);            /* removes and returns an element of type Item from the top of the stack 's' */ 
Item stack_top(Stack s);            /* returns an element of type Item from the top of the stack s */ 

#endif

