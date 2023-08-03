#include<stdio.h>
#include<stdlib.h>
int n,bt[50],tat[50],wt[50],at[50],temp[50],quant,pid[50],count=0,sum=0,i,wtime=0,ttime=0;
float avg_wt,avg_tat;
int main()
{
    printf("Enter the no of processes\n");
    scanf("%d",&n);
    printf("Enter the arrivaltime and bursttimne of all processes\n");
    for(int i=0;i<n;i++)
    {
        printf("p[%d]:",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        pid[i]=i+1;
        temp[i]=bt[i];
    }
    int y=n;
    printf("Enter the time quantum \n");
    scanf("%d",&quant);
    printf("Processno \tBursttime\tWaiting\tTurnaround\n");
    for(i=0,sum=0;y!=0;)
    {
        if(temp[i]<=quant&&temp[i]>0)
        {
            sum+=temp[i];
            temp[i]=0;
            count=1;
        }
        else if(temp[i]>0)
        {
            sum+=quant;
            temp[i]-=quant;
            
        }
        if(temp[i]==0&&count==1)
        {  
            y--;
            
            printf("%d\t%d\t%d\t%d\n",pid[i],bt[i],sum-at[i]-bt[i],sum-at[i]);
            wtime+=sum-at[i]-bt[i];
            ttime+=sum-at[i];
            count=0;
        }
        if(i==n-1)
        {
            i=0;
        }
        else if(sum>=at[i+1])
        {
            i++;
        }
        else
        {
            i=0;
        }
    }
    avg_wt = wtime * 1.0/n;  
avg_tat = wtime * 1.0/n;  
printf("\n Average Turn Around Time: \t%f", avg_wt);  
printf("\n Average Waiting Time: \t%f", avg_tat);  
}
