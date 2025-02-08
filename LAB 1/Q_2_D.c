#include<stdio.h>
int main()
{
	int a[3][3],b[3][3];
	printf("Enter elements for A(3*3)\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter elements for B(3*3)\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	int x=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i][j]==b[i][j])
			{
				x++;
			}
		}
	}
	if(x==9)
	{
		printf("Matrix A and B are equal");
	}
	else
	{
		printf("Not");
	}
	return 0;
}