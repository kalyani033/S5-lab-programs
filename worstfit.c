#include<stdio.h>
#include<stdlib.h>
int np,nb,b[50],p[50],i,j,alloc[50];
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
          alloc[i]=-1;
          printf("p[%d]:",i);
          scanf("%d",&p[i]);
          
          
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
                                else if(b[j]>b[index])
                                {
                                     index=j;
                                     
                                }     
           
                                     
                     }
             }
             if(index!=-1)
             {
                      alloc[i]=index;
                      b[index]-=p[i];
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
