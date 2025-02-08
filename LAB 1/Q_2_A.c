#include<stdio.h>
int Desc_sort(int n,int arr[n])
{
	int temp;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]<arr[j])
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
    int arr1[5]={3,2,4,1,8};
    int arr2[5]={3,5,2,10,9};
    int arr3[10],indx=0;
    
    for(int i=0;i<5;i++)
    {
        arr3[indx]=arr1[i];
        arr3[indx+5]=arr2[i];
        indx++;
    }
    Desc_sort(10,arr3);
    for(int j=0;j<10;j++)
    {
    	printf("%d ",arr3[j]);
	}
    return 0;
}