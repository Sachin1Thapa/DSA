#include <stdio.h>
#include "sort.h"

int binary_search(int arr[], int target_element, int size)
{
    int start = 0, end = size - 1;
    int mid = (start + end) / 2;
    while (start <= end)
    {
        if (arr[mid] == target_element)
            return mid + 1;

        if (target_element < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;

        mid = (start + end) / 2;
    }
    return -1;
}

int main()
{
    int arr[] = {3, 4, 1, 7, 6, 11, 66, 77};
    int n, ans;
    char decision;
    int size = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, size);
    display(arr, size);

    do
    {
        printf("\nenter the number to search : ");
        scanf("%d", &n);

        ans = binary_search(arr, n, size);
        if (ans != -1)
            printf("\nThe element %d is found in the position : %d ", n, ans);
        else
            printf("\nNo element found :");

        printf("\nDo you want to search another element (y/n) : ");
        scanf(" %c", &decision);

    } while (decision != 'n');

    return 0;
}
