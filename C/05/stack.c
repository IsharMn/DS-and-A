#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

typedef struct node {
    int data;
    struct node *next;
} *Node;

struct stack_type {
    Node top;       /* pointer to the tail of the linked list */
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
} /* end function terminate */

static Node get_previous_node(Node target_node, Node start) 
{
    Node temp = start;
    while (!(temp->next == target_node)) {
        temp = temp->next;
    }
    return temp;
} /* end function get_previous_node */

Stack stack_create(void)
{
    Stack s = malloc(sizeof(struct stack_type));
    s->top = NULL;
    return s;
} /* end function stack_create */

void stack_destroy(Stack s)
{
    if (s->top == NULL) {
         free(s);
         return;
    }
    Node temp = s->top->next;
    while (temp->next != temp) {
        s->top->next = temp->next;
        free(temp);
        temp = s->top->next;
    }
    free(temp);
    free(s);
} /* end function stack_destroy */

bool is_empty(Stack s)
{
    return s->top == NULL;
} /* end function is_empty */

bool is_full(Stack s)
{
    return false;
} /* end function is_full */

void push(Stack s, Item value)
{
    if (is_full(s))
        terminate("Error in push: Stack is full!");

    Node new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push: Cannot create node!");
    new_node->data = value;
    
    if (is_empty(s)) {
        new_node->next = new_node;
        s->top = new_node;
        return;
    }
    new_node->next = s->top->next;
    s->top->next = new_node;
    s->top = new_node;
    
} /* end function push */

Item pop(Stack s)
{
    if (is_empty(s))
        terminate("Error in pop: stack is empty!");

    Item value_to_return;
    /* if only one node is present */
    if (s->top == s->top->next) {
        value_to_return = s->top->data;
        free(s->top);
        s->top = NULL;
    }
    else {
        Node prev = get_previous_node(s->top, s->top->next);
        prev->next = s->top->next;
        value_to_return = s->top->data;
        free(s->top);
        s->top = prev;
    }
    return value_to_return;
} /* end function pop */

Item top(Stack s)
{
    if (is_empty(s))
        terminate("Error in top: Stack is empty!");
    return s->top->data;
} /* end function top */

