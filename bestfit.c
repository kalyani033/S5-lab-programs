#include<stdio.h>
#include<stdlib.h>
int np,nb,alloc[50],p[50],b[50],j,i;
int main()
{
      printf("Enter the no of blocks\n");
      scanf("%d",&nb);
      printf("Enter the size of blocks\n");
      for(int i=1;i<=nb;i++)
      {
          printf("b[%d]:",i);
          scanf("%d",&b[i]);
          
          
          
      }
      printf("Enter the no of processes\n");
      scanf("%d",&np);
      printf("Enter the size of blocks\n");
      for(int i=1;i<=np;i++)
      {
          
          printf("p[%d]:",i);
          scanf("%d",&p[i]);
          alloc[i]=-1;
          
          
      }
      for(int i=1;i<=np;i++)
      {
               int index=-1;
               for(int j=1;j<=nb;j++)
               {
                    if(b[j]>=p[i])
                    {
                          if(index==-1)
                          {
                            index=j;
                          }
                          else if(b[index]>b[j])
                          {
                              index=j;
                          }
                    }
               }
               if(index!=-1)
               {
                    alloc[i]=index;
               }
      }
      printf("Process\tProcesssize\tBlockno\n");
      for(int i=1;i<=np;i++)
      {
             if(alloc[i]==-1)
             
             {
                     printf("%d\%d\tNotallocated\n",i,p[i]);
             }
             else
             {
                     printf("%d\t%d\t%d\n",i,p[i],alloc[i]);
             }
      }
}






/*
#include<stdio.h>
#include<stdlib.h>
int np,nb,alloc[50],p[50],b[50],lowest=9999,temp,barray[50],parray[50],j,i;
int main()
{
      printf("Enter the no of blocks\n");
      scanf("%d",&nb);
      printf("Enter the size of blocks\n");
      for(int i=1;i<=nb;i++)
      {
          printf("b[%d]:",i);
          scanf("%d",&b[i]);
          barray[i]=0;
          
          
      }
      printf("Enter the no of processes\n");
      scanf("%d",&np);
      printf("Enter the size of blocks\n");
      for(int i=1;i<=np;i++)
      {
          parray[i]=0;
          printf("p[%d]:",i);
          scanf("%d",&p[i]);
          
          
      }
      for(int i=1;i<=np;i++)
      {
            for(int j=1;j<=nb;j++)
            {
                   if(barray[j]!=1)
                   {
                         temp=b[j]-p[i];
                         if(temp>=0)
                         {
                         if(temp<lowest)
                         {
                               parray[i]=j;
                               lowest=temp;
                               
                         }
                         }
                   }
                   
            }
            
            barray[parray[i]]=1;
            lowest=1000;
      }
      printf("Processno\tProcesssize\tBlock allocated\n");
      for(int i=1;i<=np;i++)
      {
            if(parray[i]!=0)
            {
                 printf("%d\t%d\t%d\n",i,p[i],parray[i]);
            }
            else
            {
                  printf("%d\t%d\tNot alocated\n",i,p[i]);
            }
      }
}
*/

/*
#include<stdio.h>
 
void main()
{
int fragment[20],b[20],p[20],i,j,nb,np,temp,lowest=9999;
static int barray[20],parray[20];
printf("\n\t\t\tMemory Management Scheme - Best Fit");
printf("\nEnter the number of blocks:");
scanf("%d",&nb);
printf("Enter the number of processes:");
scanf("%d",&np);
printf("\nEnter the size of the blocks:-\n");
for(i=1;i<=nb;i++)
    {
printf("Block no.%d:",i);
        scanf("%d",&b[i]);
    }
printf("\nEnter the size of the processes :-\n");
for(i=1;i<=np;i++)
    {
        printf("Process no.%d:",i);
        scanf("%d",&p[i]);
    }
for(i=1;i<=np;i++)
{
for(j=1;j<=nb;j++)
{
if(barray[j]!=1)
{
temp=b[j]-p[i];
if(temp>=0)
if(lowest>temp)
{
parray[i]=j;
lowest=temp;
}
}
}
fragment[i]=lowest;
barray[parray[i]]=1;
lowest=10000;
}
printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
for(i=1;i<=np && parray[i]!=0;i++)
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,p[i],parray[i],b[parray[i]],fragment[i]);
}
*/
