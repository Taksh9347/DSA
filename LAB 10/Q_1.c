#include<stdio.h>
void Bubble_sort(int *arr,int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        int swapped=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1]) // 3 4 1 2 8 9
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=1;
            }
        }
        if(!swapped)
            break;
    }
}
int main()
{
    int n;
    printf("Enter length of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements of the array\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    Bubble_sort(arr,n);
    printf("Array after sorting : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}