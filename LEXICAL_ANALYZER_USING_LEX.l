%{
#include<stdio.h>
%}
keyword int|void|while|do|for
iden [a-zA-Z][a-zA-Z0-9]*
ropr <|<=|>|>=|==
pun [;,{}()]
con [0-9]
aopr [+\-*/]
ass =
%%
{keyword} {printf("%s is a keyword\n",yytext);}
{iden} {printf("%s is an identifier\n",yytext);}
{ropr} {printf("%s is a relational operator\n",yytext);}
{pun} {printf("%s is a punctuation\n",yytext);}
{con} {printf("%s is a constant\n",yytext);}
{aopr} {printf("%s is a arithmetic operator\n",yytext);}
{ass} {printf("%s is a assignment operator\n",yytext);}
%%
void main(){
printf("Enter a String :\n");
yylex();
}
int yywrap(){
return 1;
}

/* output
Enter a String :
for(i=0;i<n;i++)
for is a keyword
( is a punctuation
i is an identifier
= is an assignment operator
0 is a constant
; is a punctuation
i is an identifier
< is a relational operator
n is an identifier
; is a punctuation
i is an identifier
+ is an arithmetic operator
+ is an arithmetic operator
) is a punctuation
*/
