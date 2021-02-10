#include <stdio.h>
#include "stack.h"

int main(void)
{
    Stack stack = stack_create();
    printf("%d\n", is_empty(stack));
    printf("%d\n", is_full(stack));

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    printf("Top: %d\n", top(stack));

    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));

    stack_destroy(stack);
    return 0;
}
