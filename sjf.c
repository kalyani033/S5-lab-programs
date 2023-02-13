#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int n,bt[50],tat[50],i,j,totwtime=0,tottime=0,pid[50],wt[50],temp,pos;
int main()
{
    printf("Enter the no fo processes\n");
    scanf("%d",&n);
    printf("Enter the bursttime of all processes\n");
    for(int i=0;i<n;i++)
    {
        printf("p[%d]:",i+1);
        scanf("%d",&bt[i]);
        pid[i]=i+1;
    }
   for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=pid[i];
        pid[i]=pid[pos];
        pid[pos]=temp;
    }
    wt[0]=0;
    tat[0]=wt[0]+bt[0];
    for(int i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=wt[i]+bt[i];
    }
    
    for(int i=0;i<n;i++)
    {
        totwtime+=wt[i];
        tottime+=tat[i];
    }
    printf("process\tBursttime\tWaiting\tTurnaround\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\n",pid[i],bt[i],wt[i],tat[i]);
    }
    printf("Total waiting time is %d\n",totwtime);
    printf("Total turnaround time is %d\n",tottime);
    
}
