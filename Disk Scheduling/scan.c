#include<stdio.h>
#include<stdlib.h>
int initial,index=-1,n,size,mov,n,req[50],temp,i,j,totmovt=0;
int main()
{
    printf("Enter the initiak head pos\n");
    scanf("%d",&initial);
    printf("Enter the size\n");
    scanf("%d",&size);
    printf("Enter right 1 and left 0\n");
    scanf("%d",&mov);
    printf("Enter the total no of request\n");
    scanf("%d",&n);
    printf("Enter the request\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(req[j]>req[j+1])
            {
                temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(req[i]>initial)
        {
            index=i;
            break;
        }
        
    }
    if(mov==1)
    {
        for(int i=index;i<n;i++)
        {
            totmovt+=abs(req[i]-initial);
            initial=req[i];
            
        }
        totmovt+=abs(req[i]-size-1);
        initial=size-1;
        for(int i=index-1;i>=0;i--)
        {
            totmovt+=abs(initial-req[i]);
            initial=req[i];
        }
    }
    printf("Total head movt is %d\n",totmovt);
    
}
