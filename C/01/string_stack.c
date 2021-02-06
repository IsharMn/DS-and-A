#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "string_stack.h"

#define STACK_SIZE 50

struct stack_type {
    char contents[STACK_SIZE][STRING_SIZE + 1];
    int top;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
} /* end function terminate */

Stack stack_create(void)
{
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
        terminate("Error: Could not create stack!");
    s->top = -1;
    return s;
} /* end function stack_create */

void stack_destroy(Stack s)
{
    free(s);
} /* end function stack_destroy */

bool stack_is_empty(Stack s)
{
    return s->top == -1;
} /* end function stack_is_empty */

bool stack_is_full(Stack s)
{
    return s->top == STACK_SIZE - 1;
} /* end function stack_is_full */

void stack_push(Stack s, char *string)
{
    if (stack_is_full(s))
        terminate("Error in push: Stack is full!");
    strcpy(s->contents[++s->top], string);
} /* end function stack_push */

char *stack_pop(Stack s)
{
    if (stack_is_empty(s))
        terminate("Error in pop: stack is empty!");
    return s->contents[s->top--];
} /* end function stack_top */

char *stack_top(Stack s)
{
    return s->contents[s->top];
} /* end function stack_top */

