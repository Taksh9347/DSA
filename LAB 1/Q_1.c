#include<stdio.h>
#include<stdlib.h>
int main()
{
    long double c1[365],c2[365],c3[365],c4[365],c5[365];
    for(int i=0;i<365;i++)
    {
        c1[i] = rand()%(40-20+1) + 20;
        c2[i] = rand()%(40-20+1) + 20;
        c3[i] = rand()%(40-20+1) + 20;
        c4[i] = rand()%(40-20+1) + 20;
        c5[i] = rand()%(40-20+1) + 20;
    }
    long double sum[5]={0};
    for(int i=0;i<365;i++)
    {
        sum[0] += c1[i];
        sum[1] += c2[i];
        sum[2] += c3[i];
        sum[3] += c4[i];
        sum[4] += c5[i];
    }
    float avg[5],x;
    for(int i=0;i<5;i++)
    {
        avg[i]=sum[i]/365;
        x+=avg[i];
        printf("Average Temprature of city %d = %f\n",i+1,avg[i]);
    }
    printf("Overall average temperature of all cities = %f",x/5);
    return 0;
}