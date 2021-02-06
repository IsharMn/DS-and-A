#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "string_stack.h"

bool is_operator(char c);
int read_line(char str[], int n); /* reads a line and stores it in str; returns the length of the string */ 

int main(void)
{
    Stack stack = stack_create();   /* stack initialization */
    char prefix_expression[STRING_SIZE + 1] = "\0";

    /* reading prefix expression into prefix_expression */
    printf("Enter prefix expression: ");
    int expression_length = read_line(prefix_expression, STRING_SIZE);

    char temp[2] = "\0";    /* temporarily storing char as string */
    for (int i = expression_length - 1; i >= 0; i--) {
        temp[0] = prefix_expression[i];

        if (is_operator(temp[0])) {
            char intermediate_expression[expression_length+1];

            char *pop1 = stack_pop(stack);
            strcpy(intermediate_expression, pop1);
            char *pop2 = stack_pop(stack);
            strcat(strcat(intermediate_expression, pop2), temp);
            stack_push(stack, intermediate_expression);
        }
        else {
            stack_push(stack, temp);
        }
    }

    printf("Equivalent postfix expression: %s\n", stack_pop(stack));
    return 0;
} /* end function main */

bool is_operator(char c)
{
    return (!isalpha(c) && !isdigit(c));
} /* end function is_operator */

int read_line(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < n) {
            if (isspace(ch))
                continue;
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
} /* end function read_line */

