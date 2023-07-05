#include <stdio.h>
#include <conio.h>
int linear_search(int arr[], int size, int target_element)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if(arr[i] == target_element)
            return i;
    }
        return -1;

}
int main()
{

    int target_element;
    char decision;
    int arr[] = {5, 3, 2, 7, 8, 1, 23, 66, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    do{
    printf("\nEnter the element to be search : ");
    scanf("%d",&target_element);
    int a = linear_search(arr, size, target_element);

    if (a != -1)
        printf("\nThe element %d is found at %d position", target_element, a + 1);
    else
        printf("\nNo element found :");

    printf("\nDo you want to search another element (y/n) : ");
    scanf(" %c",&decision);

    }while(decision != 'n');

    getch();
    return 0;
}