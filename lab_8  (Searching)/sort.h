// #include<stdio.h>

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

void display( int arr[] , int n){
    int i;
        for ( i = 0; i < n; i++){
        printf("%d " , arr[i]);
    }
}
