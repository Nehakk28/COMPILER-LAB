%{ 
#include<stdio.h> 
int i; 
%} 
%% 
[a-zA-Z]* { 
for(i=0;i<yyleng;i++) 
{ 
if((yytext[i]=='a') && (yytext[i+1]=='b') 
&& (yytext[i+2]=='c'))
{ 
yytext[i]='A'; 
yytext[i+1]='B'; 
yytext[i+2]='C'; 
} 
} 
printf("%s",yytext); 
} 
[\t]* return 1; 
.* {ECHO;} 
\n {printf("%s",yytext);} 
%% 
int main() 
{ 
printf("Enter an input:"); 
yylex();
return 0;} 
int yywrap() 
{ 
return 1; 
}

/* output 
Enter an input:
nehaabcc 
nehaABCc
*/
