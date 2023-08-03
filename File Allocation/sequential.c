#include<stdio.h>
#include<stdlib.h>
int start[100],allocate[50],length[50],file[50],count,n;
void alloc(int m)
{
      for(int i=0;i<m;i++)
      {
              printf("Start\tLength\tStatus\n");
              if(allocate[i]==1)
              {
                    printf("%d\t%d\tAllocated\n",start[i],length[i]);
              }
              else
              {
                    printf("%d\t%d\tNot Allocated\n",start[i],length[i]);
              }
      }
}
int main()
{
     
      for(int i=0;i<100;i++)
      {
      
            file[i]=0;
      }
      printf("Enter the no of files to be allocated\n");
      scanf("%d",&n);
      for(int i=0;i<n;i++)
      {
           count=0;
           printf("Enter the starting block and length\n");
           scanf("%d%d",&start[i],&length[i]);
           for(int j=start[i];j<(start[i]+length[i]);j++)
           {
                if(file[j]==0)
                {
                     count++;
                }
           }
           if(count==length[i])
           {
                 for(int j=start[i];j<(start[i]+length[i]);j++)
                 {
                         file[j]=1;
                 }
                 allocate[i]=1;
           }
           else
           {
                allocate[i]=0;
           }
      }
      alloc(n);
}








/*
#include<stdio.h>
#include<stdlib.h>
int alloc[100];
int start[100];int len[100];
int file[100];
void display(int m)
{
      for(int i=0;i<m;i++)
      {
           if(alloc[i]==1)
           {
           printf("%d\t%d\t%d\tAllocated\n",i,start[i],len[i]);
           }
           else
           
           {
           printf("%d\t-\t-\tNot allocated\n",i);
           }
      }
}
void allocate(int m)
{
int count=0;
      for(int i=start[m];i<(start[m]+len[m]);i++)
      {
            if(file[i]==0)
            {
               count++;
            }
      }
      if(count==len[m])
      {
            for(int i=start[m];i<(start[m]+len[m]);i++)
            {
                 file[i]=1;
                 
            }
            alloc[m]=1;
      }
      else
      {
      alloc[m]=0;
      }
}

int main()
{

int n;

    for(int i=0;i<100;i++)
    {
         file[i]=0;
    }
    printf("Enter the no of files\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {  
          printf("Enter the starting block\n");
          scanf("%d",&start[i]);
          printf("Enter the length of file\n");
          scanf("%d",&len[i]);
          allocate(i);
          if(alloc[i]==1)
          {
               printf("succesfully allocated file %d\n",i+1);
          }
          else
          {
              printf("Unable to allocate fie %d\n",i+1);
          }
    }
    display(n);
}


*/





