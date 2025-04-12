#include<stdio.h>
void merge1(int *arr, int s,int mid,int e)
{
    int temp[e-s+1];
    int indx = 0;
    int i=s,j=mid+1;
    while(i <= mid && j <= e) // itereate over sub sorted arr using i and j ,,insert the smaller element and incrament
    {
        if(arr[i]<=arr[j])
        {
            temp[indx++] = arr[i++];
        }
        else
        {
            temp[indx++] = arr[j++];
        }
    }
    while(i<=mid) // if left sub sorted arr is non empty
    {
        temp[indx++] = arr[i++];
    }
    while(j<=e) //if right sub sorted arr is non empty
    {
        temp[indx++] = arr[j++];
    }
    for(int x=0;x<e-s+1;x++) // copy back final sorted arr to main arr
    {
        arr[s+x] = temp[x];
    }
}
void ms_recursive(int *arr,int s,int e)
{
    if(s<e)
    {
        int mid = s + (e-s)/2;
        ms_recursive(arr,s,mid);
        ms_recursive(arr,mid+1,e);
        merge1(arr,s,mid,e);
    }
}
void merge2(int *arr, int n, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int arr1[n1], arr2[n2];

    for (int i = 0; i < n1; i++)
        arr1[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        arr2[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }
    while (i < n1)
        arr[k++] = arr1[i++];
    while (j < n2)
        arr[k++] = arr2[j++];
}
void ms_iterative(int *arr, int n)
{
    for (int size = 1; size < n; size *= 2)
    {
        for (int l = 0; l < n - 1; l += 2 * size)
        {
            int mid = (l + size - 1 < n - 1) ? l + size - 1 : n - 1;
            int r = (l + 2 * size - 1 < n - 1) ? l + 2 * size - 1 : n - 1;
            merge2(arr, n, l, mid, r);
        }
    }
}
int main()
{
    int n;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    printf("Enter elements of array \n");
    int arr[n],copy_arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        copy_arr[i]=arr[i];
    }
    ms_recursive(arr,0,n-1);
    printf("Recursive Merge sort-> ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nIterative Megre sort-> ");
    ms_iterative(copy_arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",copy_arr[i]);
    }
    return 0;
}