#include<stdio.h>
#include<string.h>

char bitmask[30],bit[12]={0};
void convert(char h[12]);
void main()
{
    int load,add,len,address,tlen,addr,i,actual_address,length,opcode;
    char input[30],pn[20],relocbit;
    FILE *f1,*f2;
    printf("\nEnter the program load address: ");
    scanf("%x",&load);
    f1=fopen("relinput.txt","r");
    f2=fopen("reloutput.txt","w");
    fscanf(f1,"%s",input);
    while(strcmp(input,"E")!=0)
    {
        if(strcmp(input,"H")==0)
        {
            fscanf(f1,"%s",pn);
            fscanf(f1,"%x",&add);
            fscanf(f1,"%x",&len);
            fscanf(f1,"%s",input);
        }
        if(strcmp(input,"T")==0)
        {
            fscanf(f1,"%x",&address);
            address+=load;
            fscanf(f1,"%x",&tlen);
            fscanf(f1,"%s",bitmask);
            convert(bitmask);
            length=strlen(bit);
            if(length>=11)
                length=10;
            for(i=0;i<length;i++)
            {
                fscanf(f1,"%x",&opcode);
                fscanf(f1,"%x",&addr);
                relocbit=bit[i];
                if(relocbit=='0')
                    actual_address=addr;
                else
                    actual_address=addr+load;
                fprintf(f2,"\n%x\t%x%x",address, opcode,actual_address);
                address+=3;
            }
            fscanf(f1,"%s",input);
        }
    }
    printf("\nContents of output file: \n ");
    fclose(f2);
    f2=fopen("RLOUT.txt","r");
    char c;
    c=fgetc(f2);
    while(c!=EOF)
    {
        printf("%c",c);
        c=fgetc(f2);
    }
    fclose(f1);
    fclose(f2);
}
void convert(char h[])
{   strcpy(bit,"");
    for(int i=0;i<strlen(h);i++)
    {
        switch(h[i])
        {
            case '0':   strcat(bit,"0");
                        break; 
            case '1':   strcat(bit,"1");
                        break; 
            case '2':   strcat(bit,"10");
                        break; 
            case '3':   strcat(bit,"11");
                        break; 
            case '4':   strcat(bit,"100");
                        break; 
            case '5':   strcat(bit,"101");
                        break; 
            case '6':   strcat(bit,"110");
                        break; 
            case '7':   strcat(bit,"111");
                        break; 
            case '8':   strcat(bit,"1000");
                        break; 
            case '9':   strcat(bit,"1001");
                        break; 
            case 'A':   strcat(bit,"1010");
                        break; 
            case 'B':   strcat(bit,"1011");
                        break; 
            case 'C':   strcat(bit,"1100");
                        break; 
            case 'D':   strcat(bit,"1101");
                        break; 
            case 'E':   strcat(bit,"1110");
                        break; 
            case 'F':   strcat(bit,"1111");
                        break;  
        }
    }
}


/*
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char bit[30];
char bitmask[20];

void bitmask_convert(char mask[])
{
	int len;
	len=strlen(mask);
	strcpy(bit,"");

	int i;

	for(i=0;i<len;++i)
	{
		switch(mask[i])
		{
		
			case '0': strcat(bit,"0000");
				  break;
			case '1': strcat(bit,"0001");
				  break;
			case '2': strcat(bit,"0010");
                                  break;
			case '3': strcat(bit,"0011");
                                  break;
			case '4': strcat(bit,"0100");
                                  break;
			case '5': strcat(bit,"0101");
                                  break;
			case '6': strcat(bit,"0110");
                                  break;
			case '7': strcat(bit,"0111");
                                  break;
			case '8': strcat(bit,"1000");
                                  break;
			case '9': strcat(bit,"1001");
                                  break;
			case 'A': strcat(bit,"1010");
                                  break;
			case 'B': strcat(bit,"1011");
                                  break;
			case 'C': strcat(bit,"1100");
                                  break;
	
			case 'D': strcat(bit,"1101");
                                  break;
			case 'E': strcat(bit,"1110");
                                  break;

			case 'F': strcat(bit,"1111");
                                  break;

			default : break;
		}

	}
	
}





void main()
{

	FILE *objptr;
	int start,addr;
	char rec[20];
	char name[20];
	int modif_obj_code;

	char first[3];
	char second[5];
	
	int bitmask_index=0;

	int i;
	////char bitmask[20];
	//char bit[20];

	int  add,len;

	printf("ENTER THE STARTING ADDRESS OF THE PROGRAM\n");
	scanf("%X",&start);
	addr=start;
	
	objptr=fopen("relinput.txt","r");

       fscanf(objptr,"%s",rec);

       if(strcmp(rec,"H")==0)
       {
	      // printf("HEADER RECORD");
	       fscanf(objptr,"%s",name);
	       fscanf(objptr,"%X",&add);
	       fscanf(objptr,"%X",&len);
	      printf("\nPROGRAM NAME=%s\n\n",name);

	      printf(" ADDRESS   OBJECT CODE \n");
	      printf("____________________________\n");
       }
       else
	{
		printf("INAVLID OBJECT CODE FORMAT\n");
		fclose(objptr);
		exit(1);
	}
      
       strcpy(rec,"");
       
	
       fscanf(objptr,"%s",rec);

       while(strcmp(rec,"E")!=0)
       {
	       //fscanf(objptr,"%s",rec);
	       if(strcmp(rec,"T")==0)
	       {
		       fscanf(objptr,"%X",&add);
		       fscanf(objptr,"%X",&len);
		       fscanf(objptr,"%s",bitmask);
		       add+=start;
		       bitmask_index=0;
		       bitmask_convert(bitmask);
		       fscanf(objptr,"%s",rec);
	       }

		if(bit[bitmask_index]=='1')
	 	{
			//printf("NEED RELOCATION\n");
			
		//	modif_obj_code=atoi(rec);
		//	modif_obj_code+=start;
		//	printf("%X\t%X\n",add,modif_obj_code);
		//	strcpy(first,"");
		//	strcpy(second,"");
			for(i=0;i<6;++i)
			{
				if(i<2)
				{
					
					first[i]=rec[i];
					
				}
				else
				{
					second[i-2]=rec[i];

				}
			}
			first[2]='\0';
			second[4]='\0';
			modif_obj_code=strtol(second,NULL,16);
			modif_obj_code+=start;

			printf("%X\t%s%X\n",add,first,modif_obj_code);
				
		}
		else
		{
			printf("%X\t%s\n",add,rec);

		}		
	       //printf("%s\n",rec);
		add+=3;
		bitmask_index++;
		
	       fscanf(objptr,"%s",rec);
       }
       

       fclose(objptr);
}


*/

/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void convert(char h[12]);
char bitmask[12];
char bit[12]={0};
void main()
{char add[6],length[10],input[10],binary[12],relocbit,ch,pn[5];
int start,inp,len,i,address,opcode,addr,actualadd,tlen;
FILE *fp1,*fp2;

printf("\n\n Enter the actual starting address : ");
scanf("%x",&start);
fp1=fopen("relinput.txt","r");
fp2=fopen("reloutput.txt","w");
fscanf(fp1,"%s",input);
fprintf(fp2," ----------------------------\n");
fprintf(fp2," ADDRESS\tCONTENT\n");
fprintf(fp2," ----------------------------\n");
while(strcmp(input,"E")!=0)
{
if(strcmp(input,"H")==0)
{
fscanf(fp1,"%s",pn);
fscanf(fp1,"%x",add);
fscanf(fp1,"%x",length);
fscanf(fp1,"%s",input);
}
if(strcmp(input,"T")==0)
{
fscanf(fp1,"%x",&address);
fscanf(fp1,"%x",&tlen);
fscanf(fp1,"%s",bitmask);
address+=start;
convert(bitmask);
len=strlen(bit);
if(len>=11)
len=10;
for(i=0;i<len;i++)
{
fscanf(fp1,"%x",&opcode);
fscanf(fp1,"%x",&addr);
relocbit=bit[i];
if(relocbit=='0')
actualadd=addr;
else
actualadd=addr+start;
fprintf(fp2,"\n  %x\t\t%x%x\n",address,opcode,actualadd);
address+=3;
}
fscanf(fp1,"%s",input);
}
}
fprintf(fp2," ----------------------------\n");
fclose(fp1);
fclose(fp2);
printf("\n\n The contents of output file(RLOUT.TXT n\n");
fp2=fopen("RLOUT.txt","r");
ch=fgetc(fp2);
while(ch!=EOF)
{
printf("%c",ch);
ch=fgetc(fp2);
}
fclose(fp2);

}
void convert(char h[12])
{
int i,l;
strcpy(bit,"");
l=strlen(h);
for(i=0;i<l;i++)
{
switch(h[i])
{
case '0':
    strcat(bit,"0");
break;
case '1':
    strcat(bit,"1");
break;
case '2':
    strcat(bit,"10");
break;
case '3':
    strcat(bit,"11");
break;
case '4':
    strcat(bit,"100");
break;
case '5':
  strcat(bit,"101");
break;
case '6':
   strcat(bit,"110");
break;
case '7':
    strcat(bit,"111");
break;
case '8':
    strcat(bit,"1000");
break;
case '9':
    strcat(bit,"1001");
break;
case 'A':
    strcat(bit,"1010");
break;
case 'B':
   strcat(bit,"1011");
break;
case 'C':
  strcat(bit,"1100");
break;
case 'D':
    strcat(bit,"1101");
break;
case 'E':
   strcat(bit,"1110");
break;
case 'F':
    strcat(bit,"1111");
break;
}
}

}
*/
