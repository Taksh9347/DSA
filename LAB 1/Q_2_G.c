#include<stdio.h>
#include<stdlib.h>

int abs_diff(int a,int b);
void unique_elements(int arr[],int n,int unique_arr[]);
void Asc_sort(int n,int arr[]);

int main()
{
	int arr1[5]={4,6,7,14,15};
	int arr2[5]={2,7,8,11,18};
	int sum[5*5];
	int indx=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			sum[indx++]=arr1[i]+arr2[j];
		}
	}
	
	Asc_sort(25,sum);
	printf("Possible sums of elements of given arrays\n");
	for(int i=0;i<25;i++)
	{
		printf("%d ",sum[i]);
	}
	int unique_sum[25];
	unique_elements(sum,25,unique_sum);
//	printf("\n\nunique sums\n");
//	for(int i=0;i<25;i++)
//	{
//		printf("%d ",unique_sum[i]);
//	}

	int x;
	printf("\n\nEnter a number x\n");
	scanf("%d",&x);

	int diff_arr[25];
	for(int i=0;i<25;i++)
	{
		diff_arr[i]=abs(sum[i]-x);
	}
	Asc_sort(25,diff_arr);

	int max_sum = arr1[5-1]+arr2[5-1];
	printf("\nPairs whose sum is closest to %d is/are ",x);
	if(x >= max_sum)
	{
		printf("(%d,%d) ",arr1[5-1],arr2[5-1]);
	}
	else if(x < max_sum)
	{
		int y=0;
		while(unique_sum[y]!=0)
		{
		
			if(abs(unique_sum[y]-x)==0)
			{
				for(int j=0;j<5;j++)
				{
					for(int k=0;k<5;k++)
					{
						if(unique_sum[y]==arr1[j]+arr2[k])
						{
							printf("(%d,%d) ",arr1[j],arr2[k]);
						}
					}
				}
				
			}
			else 
			{
				{
					if(abs(unique_sum[y]-x)==diff_arr[0])
					{
						for(int j=0;j<5;j++)
						{
							for(int k=0;k<5;k++)
							{
								if(unique_sum[y]==arr1[j]+arr2[k])
								{
									printf("(%d,%d) ",arr1[j],arr2[k]);
								}
							}
						}
					}
				}
			}
			y++;
		}
	}
	else if(x<0)
	{
		printf("\nInvalid number!");
	}
	return 0;
}
int abs_diff(int a,int b)
{
	return abs(a-b);
}
void unique_elements(int arr[], int n, int unique_arr[]) 
{
    int unique_count = 0;
    for (int i = 0; i < n; i++) 
	{
        int is_unique = 1;
        for (int j = 0; j < unique_count; j++) 
		{
            if (arr[i] == unique_arr[j]) 
			{
                is_unique = 0;
                break;
            }
        }
        if (is_unique) 
		{
            unique_arr[unique_count] = arr[i];
            unique_count++;
        }
    }
}
void Asc_sort(int n,int arr[])
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