#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "char_stack.h"

#define EXPRESSION_LENGTH 50

int priority(char c);
bool is_operator(char c);

int main(void)
{
    Stack stack = stack_create();   /* initialize a stack */

    char postfix_expression[EXPRESSION_LENGTH + 1] = "\0";
    char ch[2] = "\0";      /* storing characters as string */
    char temp[2] = "\0";

    printf("Enter infix expression: ");

    while ((ch[0] = getchar()) != '\n') {
        if (isspace(ch[0]))     /* skipping spaces present in the equation */
            continue;

        if (ch[0] == ')') {
            while (stack_top(stack) != '(') {
                temp[0] = stack_pop(stack);
                strncat(postfix_expression, temp, 1);
            }
            stack_pop(stack);
        }
        else if (is_operator(ch[0])) {
            if (stack_is_empty(stack)) {
                stack_push(stack, ch[0]);
            }
            else if (ch[0] == '(')
                stack_push(stack, ch[0]);
            else {
                while (priority(ch[0]) <= priority(stack_top(stack))) {
                    temp[0] = stack_pop(stack);
                    strncat(postfix_expression, temp, 1);
                }
                stack_push(stack, ch[0]);
            }
        }
        else {
            strncat(postfix_expression, ch, 1); /* adding the operand to the postfix expression */
        }
    }
    /* poping off the remaining operators from the stack */
    while (!stack_is_empty(stack)) {
        temp[0] = stack_pop(stack);
        strncat(postfix_expression, temp, 1);
    }

    stack_destroy(stack);
    printf("Equivalent postfix expression: %s\n", postfix_expression);
} /* end function main */

int priority(char c)
{
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
} /* end function priority */

bool is_operator(char c)
{
    return (!isalpha(c) && !isdigit(c));
} /* end function is_operator */

