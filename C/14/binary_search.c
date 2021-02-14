#include <stdio.h>

int binary_search(const int arr[], int arr_length, int target_key);

int main(void)
{
    int numbers[] = {2, 13, 55, 73, 1, 97};
    int target = 59;
    int index = binary_search(numbers, 6, target);
    
    if (index == -1) 
        puts("Not found!");
    else 
        printf("Found at index %d.\n", index);
} /* end function main */

int binary_search(const int arr[], int arr_length, int target_key)
/* returns the index if found, -1 otherwise */
{
    int low = 0;
    int high = arr_length - 1;

    int mid;
    while (low <= high) {
       mid = (high + low) / 2; 

       if (arr[mid] == target_key)
           return mid;
       else if (arr[mid] > target_key)
           high = mid - 1;
       else
           low = mid + 1;
    }
    return -1;
} /* end function binary_search */

