#include<stdio.h>
#include<stdlib.h>
struct Array
{
	int a1[6];
	int a2[6];
};
int main()
{
	struct Array *A=malloc(sizeof(struct Array));
	printf("Enter 6 elements of array\n");
	for(int i=1;i<=6;i++)
	{
		scanf("%d",&A->a1[i]);
	}
	int *ptr1,*ptr2;
	ptr1 = A->a1;
	ptr2 = A->a2;
	
	for(int i=1;i<=6;i++)
	{
		if( i%2!=0 || i==1 || i==6 )
		{
			*(ptr2+i) = *(ptr1+i);
		}
		else
		{
			*(ptr2+i) = *(ptr1+i-1) * *(ptr1+i+1);
		}
	}
	
	printf("Input Array\n");
	for(int i=1;i<=6;i++)
	{
		printf("%d ",*(ptr1+i));
	}
	
	printf("\nResultant Array\n");
	for(int i=1;i<=6;i++)
	{
		printf("%d ",*(ptr2+i));
	}
	
	free(A);
	return 0;
}