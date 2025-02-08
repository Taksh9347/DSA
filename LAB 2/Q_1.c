#include<stdio.h>
#include<stdlib.h>
void Read_Mat(int** M,int row,int col);
void Mult_Mat(int** M1,int row1,int col1,int** M2,int row2,int col2,int** M3);
void Print_Mat(int** M,int row,int col);
void Free_Mat(int** M,int row,int col);
int main()
{
	int r1,c1,r2,c2;
	printf("Enter number of rows for first Matrix\n");
	scanf("%d",&r1);
	printf("Enter number of columns for first Matrix\n");
	scanf("%d",&c1);
	printf("Enter number of rows for second Matrix\n");
	scanf("%d",&r2);
	printf("Enter number of columns for second Matrix\n");
	scanf("%d",&c2);
	if(c1!=r2)
	{
		printf("Matrix Multiplication is not possible\n");
		return 1;
	}
	int** Mat1;
	Mat1 = (int**)malloc(r1*sizeof(int *));
	for(int i=0;i<r1;i++)
	{
		*(Mat1+i) = (int *)malloc(c1*sizeof(int));
	}
	printf("Matrix 1.\n");
	Read_Mat(Mat1,r1,c1);
	Print_Mat(Mat1,r1,c1);
	printf("\n");
	
	int** Mat2;
	
	Mat2 = (int**)malloc(r2*sizeof(int *));
	for(int i=0;i<r2;i++)
	{
		*(Mat2+i) = (int *)malloc(c2*sizeof(int));
	}
	printf("Matrix 2.\n");
	Read_Mat(Mat2,r2,c2);
	Print_Mat(Mat2,r2,c2);
	printf("\n");

	int** result;
	result = (int**)malloc(r1*sizeof(int*));
	for(int i=0;i<r1;i++)
	{
		*(result+i) = (int*)malloc(c2*sizeof(int));
	}
	
	Mult_Mat(Mat1,r1,c1,Mat2,r2,c2,result);
	
	printf("Product Matrix\n");
	Print_Mat(result,r1,c2);
	
	Free_Mat(Mat1,r1,c1);
	Free_Mat(Mat2,r2,c2);
	Free_Mat(result,r1,c2);
}
void Free_Mat(int** M,int row,int col)
{
	for(int i=0;i<row;i++)
	{
		free(*(M+i));
	}
	free(M);
}
void Read_Mat(int** M,int row,int col)
{
	printf("Enter %d Elements\n",row*col);
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			scanf("%d",&*(*(M+i)+j));
		}
	}
}
void Print_Mat(int** M,int row,int col)
{
	printf("\n");
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			printf("%d ",*(*(M+i)+j));
		}
		printf("\n");
	}
}
void Mult_Mat(int** M1,int row1,int col1,int** M2,int row2,int col2,int** M3)
{
	for(int i=0;i<row1;i++)
	{
		for(int j=0;j<col2;j++)
		{
			*(*(M3+i)+j)=0;
			for(int k=0;k<col1;k++)
			{
				*(*(M3+i)+j) += *(*(M1+i)+k) * *(*(M2+k)+j);
			}
		}
	}
}