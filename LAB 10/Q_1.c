#include<stdio.h>
void Bubble_sort(int *arr,int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
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