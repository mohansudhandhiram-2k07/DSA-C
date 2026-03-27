#include<stdio.h>
#include<stdlib.h>


void insertion_sort(int *arr,int size)
{
    for(int i = 1; i < size;i++)
    {
        int temp = arr[i],j;
        for( j = i-1; arr[j] > temp && j>-1; j-- )
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
}


int main()
{
    int arr[] = {9,8,7,6,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,size);
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}