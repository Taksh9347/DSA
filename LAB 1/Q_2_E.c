#include<stdio.h>
int Asc_sort(int n,int arr[n])
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
	int arr[10]={1,3,-7,-22,8,0,0,2,-4,-5};
	Asc_sort(10,arr);
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}