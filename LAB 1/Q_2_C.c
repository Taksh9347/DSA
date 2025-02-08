#include<stdio.h>
int main()
{
	int arr[10]={2,34,67,198,23,6,83,891,627,8923};
	int even[10]={0},odd[10]={0};
	int j=0,k=0;
	for(int i=0;i<10;i++)
	{
		if(arr[i]%2==0)
		{
			even[j++]=arr[i];
		}
		else
		{
			odd[k++]=arr[i];
		}
	}
	printf("\nEven array is ");
	for(int i=0;i<10;i++)
	{
		if(even[i]!=0)
		{
			printf("%d ",even[i]);
		}
	}
	printf("\n");
	printf("\nOdd array is ");
	for(int i=0;i<10;i++)
	{
		if(odd[i]!=0)
		{
			printf("%d ",odd[i]);
		}
	}
	
	return 0;
}