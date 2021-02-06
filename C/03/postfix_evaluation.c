#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "int_stack.h"

int main(void)
{
    Stack stack = stack_create();   /* initialize a stack */
    char ch[2] = "\0";

    printf("Enter postfix expression: ");
    while ((ch[0] = getchar()) != '\n') {
        if (isdigit(ch[0])) {
            stack_push(stack, atoi(ch));
        }
        else {
            Item p1 = stack_pop(stack);
            Item p2 = stack_pop(stack);
            Item result;
            switch (ch[0]) {
                case '+':
                    result = p2 + p1;
                    break;
                case '-':
                    result = p2 - p1;
                    break;
                case '*':
                    result = p2 * p1;
                    break;
                case '/':
                    result = p2 / p1;
                    break;
                case '^':
                    result = (int) pow(p2, p1);
            }
            stack_push(stack, result);
        }
    }
    printf("Result: %d\n", stack_pop(stack));
    stack_destroy(stack);
    return 0;
}
