%{
 #include<stdio.h>
 #include<stdlib.h>
%}
%token DIGIT ALPHA
%%
var: ALPHA
|var ALPHA
|var DIGIT;
%%
int main(int argc,char *argv[])
{
printf("Enter a variable name : ");
yyparse();
printf("Valid variable!!\n");
return 0;
}
int yyerror()
{
printf("Invalid Variable!\n");
exit(1);
}


/* output
Enter a variable name: Hello!12
Invalid Variable!
student@holy-ThinkCentre-M72e:~/neha$./a.out
Enter a variable name: Hello12
Valid variable!! */
