#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>
int iskeyword(char buffer[]) {
char keywords[32][10]={"auto", "else", "case", "break", "continue", "if", "int", "for", "goto", "do", 
"double", "long", "float", "while", "char", "switch"};
int i; 
for(i=0;i<32;++i){
if (strcmp(keywords[i], buffer) == 0){
return 1;
}}
return 0;
}
int main(){
char ch, buffer[15], buf[10]; 
char operators[]="+-*/%=”;
char specialch[]=”,;[]{}”;
FILE *fp;
int j=0, k=0; 
fp=fopen("program.txt", "r"); 
if (fp==NULL){
printf ("Error while opening the file\n"); 
exit(0); 
}
while ((ch=fgetc(fp)) != EOF){
for (int i=0; i < strlen (operators); ++i) {
if (ch==operators[i]){
printf("%c is operator\n", ch);
break;
}}
for (int i=0; 1 < strlen(specialch); ++i) {
if (ch==specialch[i]) {
printf ("%c is special character\n", ch); 
break;
}}
if (isalpha (ch)){
buffer[j++]=ch;
}eise if ((ch == ’ ' || ch == ’\n’) && (j != 0)){
buffer[j] = '\0'; 
j=0; 
if (iskeyword(buffer) == 1){
printf("%s is keyword\n", buffer);
} else{
printf("%s is identifier\n", buffer);
}}
if (isdigit(ch)) { 
buf [k++] = ch; 
}else if ((ch ==’ ‘ || ch == '\n') && (k != 0)){ 
buf [k] = '\0'; 
k = 0; 
printf ("%s is constant\n", buf);
}}
fclose(fp); 
return 0; 
}
