#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int * array,int size)
{
    for(int i = 0;i<size-1;i++)
    {
        for(int j = 0;j<size-i-1;j++)
        {
            if(array[j] > array[j+1])
            {
                int t = array[j];
                array[j] = array[j+1];
                array[j+1] = t;
            }
        }
    }
}

int main()
{
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("After sorting\n");
    bubble_sort(arr,size);
    for(int i =0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;


}

