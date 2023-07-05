#include<stdio.h>
#include<conio.h>

                        // Bubble sorting 
void bubble_sort( int s[] , int n){
    int i , j;
    for ( i = 0; i < n; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            if(s[i] > s[j]){
                int temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
        
    }
    
}

                    // Selection sort
void selection_sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        int min_value = arr[i];
        int min_index = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_value = arr[j];
                min_index = j;
            }
        }
        if (min_index != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}
                // Insertion sort
void insertion_sort(int arr[] , int n){
    int i , j , key;
    for ( i = 1; i < n; i++)
    {
        key = arr[i];
        int j = i-1;
    

    while (j>=0 && key < arr[j]){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
    }
}


int main(){
     int n , i;
    printf("Enter of the number of array : ");
    scanf("%d" ,&n);
    printf("\nEnter the array : \n");
    int arr[n];
    for ( i = 0; i < n; i++){
        scanf("%d" , &arr[i]);
    }

    bubble_sort(arr,n);
    // selection_sort(arr,n);
    // insertion_sort(arr,n);

    for ( i = 0; i < n; i++){
        printf("%d " , arr[i]);
    }
    getch();
    return 0;
    

}

// 47 46 70 53 13 42 91 3 92 20 76 28 96 64 52 4 58 29 65 2 (20 data)
