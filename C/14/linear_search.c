#include <stdio.h>

int linear_search(const int arr[], int arr_length, int target_key);

int main(void)
{
    int numbers[] = {2, 13, 55, 73, 1, 97};
    int target = 59;
    int index = linear_search(numbers, 6, target);
    
    if (index == -1) 
        puts("Not found!");
    else 
        printf("Found at index %d.\n", index);
} /* end function main */

int linear_search(const int arr[], int arr_length, int target_key)
/* returns the index if found, -1 otherwise */
{
    for (int i = 0; i < arr_length; i++) 
    {
        if (arr[i] == target_key)
            return i;
    }
    return -1;
} /* end function linear_search */

