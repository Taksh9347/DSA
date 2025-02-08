#include<stdio.h>
int main()
{
	int arr[10];
	printf("Enter 10 elements of array (within the range 0 to 10)\n");
	for(int i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	int ocurrence[11]={0};
	for(int i=0;i<10;i++)
	{
		ocurrence[arr[i]]++;
	}
	int result[11];
	int j=1;
	if(ocurrence[0]!=0)
	{
		result[0]=1;
	}
	for(int i=1;i<11;i++)
	{
	
		if(ocurrence[i]!=0)
		{
			result[j++]=i;
		}
	}
	printf("Unique Elements \n");
	if(result[0]!=0)
	{
		printf("%d ",0);
	}
	for(int i=1;i<11;i++)
	{
		if(result[i]<=11 && result[i]>=1)
		{
			printf("%d ",result[i]);
		}
	}
	return 0;
}