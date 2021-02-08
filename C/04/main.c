#include <stdio.h>
#include "bank_queue.h"

int main(void)
{
    Queue queue = queue_create();

    printf("%d\n", queue_is_empty(queue));
    printf("%d\n", queue_is_full(queue));

    get_token(queue);
    get_token(queue);
    get_token(queue);

    printf("Customer at the front of the line: %d\n", customer_at_the_front_of_queue(queue));
    printf("Customer at the end of the line: %d\n", customer_at_the_end_of_queue(queue));

    printf("Turn: %d\n", customer_to_serve(queue));
    printf("Turn: %d\n", customer_to_serve(queue));
    printf("Turn: %d\n", customer_to_serve(queue));
    printf("Turn: %d\n", customer_to_serve(queue));

    queue_destroy(queue);
    return 0;
}
