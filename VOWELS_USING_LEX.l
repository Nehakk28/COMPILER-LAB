%{
int v=0;
int c=0;
%}
%%
[aeiouAEIOU] {v++;}
[a-zA-Z] {c++;}
%%
void main()
{
printf("Enter the String :\n");
yylex();
printf("Number of vowels =%d\n",v);
printf("Number of consonants 
=%d\n",c);
}
int yywrap(){
return 1;
}

/* output
Enter the String:
Hello WORLD
Number of vowels =3
Number of consonants =7
*/
