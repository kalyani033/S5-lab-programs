#include<stdio.h>
#include<stdlib.h>
int i,j,np,nb,p[50],b[50],alloc[50];
int main()
{
        printf("Enter the no of blocks\n");
        scanf("%d",&nb);
        printf("Enter the size of blocks\n");
        for(int i=0;i<nb;i++)
        {    
                printf("b[%d]:",i+1); 
                scanf("%d",&b[i]);
        }
        for(int i=0;i<nb;i++)
        {
                alloc[i]=-1;
                
        }
        printf("Enter the no processes\n");
        scanf("%d",&np);
        printf("Enter the size of processes\n");
        for(int i=0;i<np;i++)
        {     
                printf("p[%d]:",i+1);
            
                scanf("%d",&p[i]);
        }
        for(int i=0;i<np;i++)
        {
              for(int j=0;j<nb;j++)
              {
                      if(p[i]<=b[j])
                      {
                           b[j]-=p[i];
                           alloc[i]=j;
                           break;
                      }
              }
        }
        printf("Processno\tProcesssize\tBlockno\n");
        for(int i=0;i<np;i++)
        {
             if(alloc[i]==-1)
             {
                    printf("%d\t%d\t---\tNot allocated\n",i+1,p[i]);
             }
             else
             {
                     printf("%d\t%d\t%d\tallocated\n",i+1,p[i],alloc[i]+1);
             }
        }
        
}
