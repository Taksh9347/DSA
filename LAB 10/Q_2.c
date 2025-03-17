#include<stdio.h>
void Selection_Sort(int *arr,int n)
{
    int temp;
    int max_indx;
    for(int i=0;i<n-1;i++)
    {
        max_indx = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>arr[max_indx])
                max_indx = j;
        }
        temp = arr[i];
        arr[i] = arr[max_indx];
        arr[max_indx]=temp;
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
    Selection_Sort(arr,n);
    printf("Array after sorting : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}