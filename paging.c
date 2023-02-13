#include<stdio.h>
#include<stdlib.h>
int main()
{
       int ms,ps,n,rem,nop,s[50],offset,x,y,fno[50][50];
       int i,j;
       printf("Enter the memory size\n");
       scanf("%d",&ms);
       printf("Enter the page size\n");
       scanf("%d",&ps);
       nop=ms/ps;
       printf("The no of pages is %d\n",nop);
       printf("Enter the no of processes\n");
       scanf("%d",&n);
       rem=nop;
       for(int i=1;i<=n;i++)
       {
              printf("Enter the no of pages for p[%d]",i);
              scanf("%d",&s[i]);
              if(s[i]>rem)
              {
                    printf("Memory is full\n");
                    break;
              }
              else
              {
              rem-=s[i];
              printf("Enter the page table for p[%d]",i);
              for(int j=1;j<=s[i];j++)
              {
                     scanf("%d",&fno[i][j]);
              }
              }
       }
       printf("Enter the processno,pageno and offset to calculate physical address\n");
       scanf("%d%d%d",&x,&y,&offset);
       
       {
            int pa=fno[x][y]*ps+offset;
            printf("Physical address is %d\n",pa);
       }
}



/*  
#include<stdio.h>
void main()
{
int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
int s[10], fno[10][20];
printf("\nEnter the memory size -- ");
scanf("%d",&ms);
printf("\nEnter the page size -- ");
scanf("%d",&ps);
nop = ms/ps;
printf("\nThe no. of pages available in memory are -- %d ",nop);
printf("\nEnter number of processes -- ");
scanf("%d",&np);
rempages = nop;
for(i=1;i<=np;i++)
{
printf("\nEnter no. of pages required for p[%d]-- ",i);
scanf("%d",&s[i]);
if(s[i] >rempages)
{
printf("\nMemory is Full");
break;
}
rempages = rempages - s[i];
printf("\nEnter pagetable for p[%d] --- ",i);
for(j=0;j<s[i];j++)
scanf("%d",&fno[i][j]);
}
printf("\nEnter Logical Address to find Physical Address ");
printf("\nEnter process no. and pagenumber and offset -- ");
scanf("%d %d %d",&x,&y, &offset);
if(x>np || y>=s[i] || offset>=ps)
printf("\nInvalid Process or Page Number or offset");
else
{ pa=fno[x][y]*ps+offset;
printf("\nThe Physical Address is -- %d",pa);
}
}
*/
