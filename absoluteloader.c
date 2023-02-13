#include<stdio.h>
#include<stdlib.h>
int main()
{
        FILE *f1;
        char name[50];
        char line[50],address[50];
        int start;
        f1=fopen("absinput.txt","r");
        fscanf(f1,"%s",line);
        int j=0;
        for(int i=2;line[i]!='^';i++)
        {
                name[j++]=line[i];
        }
        printf("Name of the prgm is %s\n",name);
        fscanf(f1,"%s",line);
        while(line[0]!='E')
        {
               if(line[0]='T')
               {
                         int k=0;
                         for(int i=2;line[i]!='^';i++)
                         {
                               address[k++]=line[i];
                         }
                         start=atoi(address);
                         int m=12;
                         while(line[m]!='$')
                         {
                                if(line[m]!='^')
                                {
                                      printf("00%d\t %c%c\n",start,line[m],line[m+1]);
                                      start++;
                                      m=m+2;
                                }
                                else
                                {
                                     m=m+1;
                                }
                         }
                         fscanf(f1,"%s",line);
               }
        }
        
}






























/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
  FILE *fp;
  int i,addr1,l,j,staddr1;
  char name[10],line[50],name1[10],addr[10],rec[10],ch,staddr[10];
  
  fp=fopen("absinput.txt","r");
  fscanf(fp,"%s",line);
  for(i=2,j=0;i<8,j<6;i++,j++)
    name1[j]=line[i];
    name1[j]='\0';
  printf("name from obj. %s\n",name1);
  
    do
    {
    fscanf(fp,"%s",line);
    if(line[0]=='T')
    {
    for(i=2,j=0;i<8,j<6;i++,j++)
    staddr[j]=line[i];
    staddr[j]='\0';
    staddr1=atoi(staddr);
    i=12;
    while(line[i]!='$')
    {
      if(line[i]!='^')
      {
        printf("00%d \t %c%c\n", staddr1,line[i],line[i+1]);
        staddr1++;
        i=i+2;
      }
      else i++;
    }
    }
    else if(line[0]='E')
    fclose(fp);
    }while(!feof(fp));
    
    
*/
















/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *fp, *fp1;
    fp = fopen("absinput.txt", "r");
    fp1 = fopen("absoutput.txt", "w");
    char name[20], line[30];
    fscanf(fp, "%s", line);
    int k = 0;
    if (line[0] == 'H')
    {
        for (int i = 2; line[i] != '^'; i++)
        {
            name[k++] = line[i];
        }
    }
    char startaddr[20];
    int sta;
    int i, j;
    printf("The name of the program is %s", name);
    fscanf(fp, "%s", line);
    while (!feof(fp))
    {
        while (line[0] == 'T')
        {
            for (i = 2, j = 0; line[i] != '^'; i++, j++)
            {
                startaddr[j] = line[i];
            }
            sta = atoi(startaddr);
            i = 12;
            while (line[i] != '$')
            {
                if (line[i] != '^')
                {
                    fprintf(fp1, "%d\t%c\t%c\n", sta, line[i], line[i + 1]);
                    i = i + 2;
                    sta++;
                }
                else
                {
                    i++;
                }
            }
            fscanf(fp, "%s", line);
        }
    }
}

*/
