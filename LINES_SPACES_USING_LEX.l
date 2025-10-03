%{ 
#include<stdio.h> 
#include<string.h> 
int wc=0,lc=0,ch=0,sc=0,oc=0; 
%} 
%% 
\n lc++; 
" " sc++; 
[^\t\n] ch++; 
%% 
void main() 
{ 
printf("Enter the input:\n"); 
yylex(); 
printf("\nNumber of lines=%d",lc); 
printf("\nNumber of spaces=%d",sc); 
printf("\nNumber of characters=%d",ch);
printf("\nNumber of words=%d\n",lc+sc);
} 
int yywrap() 
{ 
return 1; 
}

/* output
Enter the input: 
Hello world 
Number of lines=1 
Number of spaces=1 
Number of characters=12
Number of words=2
*/
