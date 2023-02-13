#include<stdio.h>
#include<stdlib.h>
int n,at[10],wt[10],tat[10],bt[10],ct[50];
int main()
{
int totwtime=0,totime=0;
         printf("Enter the no of processes\n");
         scanf("%d",&n);
         printf("Enter the arrivaltime and bursttime of each process\n");
         for(int i=0;i<n;i++)
         {
              printf("p[%d]",i+1);
              scanf("%d\t%d",&at[i],&bt[i]);
         }
         ct[0]=at[0]+bt[0];
         tat[0]=ct[0]-at[0];
         wt[0]=tat[0]-bt[0];
         for(int i=1;i<n;i++)
         {
               ct[i]=ct[i-1]+bt[i];
               tat[i]=ct[i]-at[i];
               wt[i]=tat[i]-bt[i];
         }
         printf("process atime btime tattime waittime\n");
         for(int i=0;i<n;i++)
         
         {    totwtime+=wt[i];
              totime+=tat[i];
              printf("%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],tat[i],wt[i]);
         }
         float avgwtime=totwtime/n;
         float avgttime=totime/n;
         printf("Avg ttime and wtime are %f and %f\n",avgttime,avgwtime);
         
}
