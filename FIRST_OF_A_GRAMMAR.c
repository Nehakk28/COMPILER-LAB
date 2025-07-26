#include<stdio.h> 
#include<ctype.h>
void FIRST(char[],char);
void addtoresultset(char[],char); 
int np;
char productionset[10][10];
int main()
{
int i;
char c,choice,result[20];
printf("Enter the number of productions:"); 
scanf("%d",&np);
for(i=0;i<np;i++)
{
printf("Enter the production number[%d]:",i+1); 
scanf(" %s",productionset[i]);
}
do
{
printf("Find the FIRST of: "); 
scanf(" %c",&c); 
FIRST(result,c);
printf("\n FIRST of (%c)={",c);
for(i=0;result[i]!='\0';i++)
printf("%c",result[i]);
printf("} \n");
printf("Press y to continue:"); 
scanf("%s",&choice);
}while(choice=='y' || choice=='Y'); 
return 0;
}
void FIRST(char* result,char c)
{
int
i,j,k,foundepsilon; 
char subresult[20]; 
subresult[0]='\0'; 
result[0]='\0';
if(!(isupper(c)))
{
addtoresultset(result,c); 
return;
}
 for(i=0;i<np;i++)
 {
if(productionset[i][0]==c)
{
if(productionset[i][2]=='$') 
addtoresultset(result,'$');
else
{
j=2;
while(productionset[i][j]!='\0')
{
foundepsilon=0; 
FIRST(subresult,productionset[i][j]); 
for(k=0;subresult[k]!='\0';k++)
addtoresultset(result,subresult[k]); 
for(k=0;subresult[k]!='\0';k++)
if(subresult[k]=='$')
{
foundepsilon=1; 
break;
}
if(!foundepsilon)
break;
j++;
}
}
}
}
return;
}
void addtoresultset(char result[],char val)
{
int k; 
for(k=0;result[k]!='\0';k++)
if(result[k]==val)
return; 
result[k]=val; 
result[k+1]='\0';
}
