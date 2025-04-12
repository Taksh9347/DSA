#include<stdio.h>
void Insertion_sort(int *arr,int n)
{
    for(int i=1;i<n;i++) // 3 11 2 9 5 6 
    {
        int curr = arr[i];
        int j=i-1;
        while(arr[j] >= curr && j>=0) // if arr[j] is >= to current element then it will be shifted 1 position forward
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr; // after end of while loop put curr at its correct position
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
    printf("Before sorting : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    Insertion_sort(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}