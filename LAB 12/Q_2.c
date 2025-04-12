#include<stdio.h>
int getmax(int *arr, int n) 
{
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}
void Count_sort(int *arr, int n, int exp) {
    int res[n];
    int count_arr[10] ={0};
    for(int i = 0; i < n; i++) {
        count_arr[(arr[i]/exp)%10]++;
    }
    for(int i = 1; i < 10; i++) {
        count_arr[i] += count_arr[i - 1];
    }
    for(int i = n - 1; i >= 0; i--) 
    {  
        int digit = (arr[i] / exp) % 10;
        res[--count_arr[digit]] = arr[i];
    }
    for(int i = 0; i < n; i++) 
    {
        arr[i] = res[i];
    }
}
void Radix_sort(int *arr,int n)
{
    int m = getmax(arr,n);
    for(int exp=1;m/exp>0;exp*=10)
    {
        Count_sort(arr,n,exp);
    }       
}
int main() {
    int n;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before sorting : ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    Radix_sort(arr, n);

    printf("After Radix sort : ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
