#include<stdio.h>
int Partition(int *arr,int start, int end)
{
    int pivot = arr[start];
    int i=start;
    int j=end;
    int temp;
    while(i<j)  // 4 6 7 5 1 2 3
    {
        while(pivot >= arr[i] && i <= end-1) // find indx of first greatest element from left
        {
            i++;
        }
        while(pivot < arr[j] && j > start) // find indx of first smaller element from right
        {
            j--;
        } 
        if(i<j) // swap elements of above indices to put smaller on left side and larger element on right side
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[j];
    arr[j] = arr[start];
    arr[start] = temp;
    return j;
}
void Quick_sort(int *arr,int start,int end)
{
    if(start<end)
    {
        int pI = Partition(arr,start,end);
        Quick_sort(arr,start,pI-1);
        Quick_sort(arr,pI+1,end);
    }
}
int main()
{
    int n;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    Quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}