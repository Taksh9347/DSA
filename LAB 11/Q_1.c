#include<stdio.h>
void Insertion_sort(int *arr,int n)
{
    for(int i=1;i<n;i++)
    {
        int curr = arr[i];
        int j=i-1;
        while(arr[j] >= curr && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
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
    Insertion_sort(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}