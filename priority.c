#include<stdio.h>
#include<stdlib.h>
int n,prio[50],tat[50],bt[50],prio[50],pid[50],temp,totwtime=0,tottime=0,wt[50];
int main()
{
    printf("Enter the no of processes\n");
    scanf("%d",&n);
    printf("Enter the priority and bursttime of each process\n");
    for(int i=0;i<n;i++)
    {
        printf("p[%d]",i+1);
        scanf("%d%d",&prio[i],&bt[i]);
        pid[i]=i+1;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(prio[j]>prio[j+1])
            {
                temp=prio[j];
                prio[j]=prio[j+1];
                prio[j+1]=temp;
                
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
                
                temp=pid[j];
                pid[j]=pid[j+1];
                pid[j+1]=temp;
            }
        }
    }
    wt[0]=0;
    tat[0]=bt[0]+wt[0];
    for(int i=i;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=bt[i]+wt[i];
        
        
    }
    for(int i=0;i<n;i++)
    {
        totwtime+=wt[i];
        tottime+=tat[i];
    }
    printf("process\tpriority\tBursttime\twaiting\tturnaroun\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n",pid[i],prio[i],bt[i],wt[i],tat[i]);
    }
    
}
