#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef int Item;
typedef struct stack_type *Stack;

Stack stack_create(void);   /* initializes a stack and returns a pointer to it */
void stack_destroy(Stack s); /* frees the stack from memory */
bool is_empty(Stack s);     /* checks if the stack is empty */
bool is_full(Stack s);      /* checks if the stack is full */
void push(Stack s, Item value); /* adds an element onto the stack */
Item pop(Stack s);          /* removes and returns an element from the top of the stack */
Item top(Stack s);          /* returns an element from the top of the stack */

#endif
