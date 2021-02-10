#include <stdio.h>
#include "queue.h"

int main(void)
{
    Queue queue = queue_create();

    printf("%d\n", is_empty(queue));
    printf("%d\n", is_full(queue));

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printf("Front: %d\n", front(queue));
    printf("Rear: %d\n", rear(queue));

    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    
    queue_destroy(queue);
    return 0;
}
