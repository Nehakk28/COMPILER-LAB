%{
 #include<stdio.h>
 int flag=0;
%}
%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%
ArithemeticExpression: E{
 printf("\nResult=%d\n",$$);
 return 0;
 };
E:E'+'E {$$=$1+$3;}
|E'-'E {$$=$1-$3;}
|E'*'E {$$=$1*$3;}
|E'/'E {$$=$1/$3;}
|E'%'E {$$=$1%$3;}
|'('E')' {$$=$2;}
| NUMBER {$$=$1;}
;
%%
void main()
{
 printf("\nEnter any arithmetic exp 
which can have operations 
addition,subtraction,multiplication,divis
ion,modulus and round brackets:\n");
 yyparse();
 if(flag==0)
 printf("\nEntered Arithmetic 
expression is valid\n\n");
}
void yyerror()
{
printf("\n Entered Arithmetic 
expression is invalid\n\n");
flag=1;
}
