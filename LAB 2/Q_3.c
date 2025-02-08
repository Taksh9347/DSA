#include<stdio.h>
#include<string.h>
struct BankMgmt
{
	int AccNumber;
	char CustmName[100];
	float AvlBalance;
	char AccType[10];
}Custm1;
int main()
{
	printf("Enter details\n\n");
	printf("Enter account number  ");
	scanf("%d",&Custm1.AccNumber);
	printf("Enter Name  ");
	scanf("%s",&Custm1.CustmName);
	printf("Enter AvlBalance  ");
	scanf("%f",&Custm1.AvlBalance);
	printf("Enter account type  ");
	scanf("%s",&Custm1.AccType);
	

	while(1)
	{
	printf("\nMenu options\n");
	printf("1.Withdraw\n");
	printf("2.Deposit\n");
	printf("3.Display Balance\n");
	printf("4.Exit\n");
	
	int a;
	printf("\nSelect Menu option\n");
	scanf("%d",&a);
	
	float witd_amt;
	float depo_amt;
		
	
	switch(a)
	{
		case 1:
			printf("\nEnter withdrawl amount\n");
			scanf("%f",&witd_amt);
			if(witd_amt>Custm1.AvlBalance)
			{
				printf("\nLimit Exceeded(Witdhrawl amount cannot exceed current balnce)");
			}
			else
			{
				Custm1.AvlBalance-=witd_amt;
				printf("Current Available Balance -> %f\n",Custm1.AvlBalance);
			}
			break;
			
		case 2:
			printf("Enter deposit amount\n");
			scanf("%f",&depo_amt);
			Custm1.AvlBalance+=depo_amt;
			printf("\nCurrent Available Balance -> %f\n",Custm1.AvlBalance);
			break;
						
		case 3:
			printf("\nAccount number -> %d\n",Custm1.AccNumber);
			printf("\nName of account holder -> %s\n",Custm1.CustmName);
			printf("\nCurrent Available Balance -> %f\n",Custm1.AvlBalance);
			break;
			
		case 4:
			printf("\nExited successfully\n");
			return 0;
			break;
	}
}
}