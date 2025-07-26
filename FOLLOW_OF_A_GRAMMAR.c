#include <stdio.h> 
#include <ctype.h> 
#include <string.h>
int n, m = 0;
char a[10][10], f[10];
void follow(charc);
void first(char c);
int main()
{
int i, z; char c;
printf("Enter the number of productions: "); 
scanf("%d", &n);
printf("Enter the productions (epsilon=$):\n"); 
for (i = 0; i < n; i++) 
{
scanf("%s", a[i]);
}
 do
 {
m = 0;
printf("Enter the element whose FOLLOW is to be found: "); 
scanf(" %c", &c);
follow(c);
printf("FOLLOW(%c) = {",c); 
for (i = 0; i < m; i++)
{
printf("%c", f[i]);
if (i < m - 1) 
{
printf(", ");
}
}
printf("}\n");
printf("Do you want to continue (0/1)? "); 
scanf("%d", &z);
} while (z == 1);
 return 0;
}
void follow(char c) 
{
 int i, j;
 if (a[0][0] == c && m == 0)
 {
f[m++] = '$';
}
for (i = 0; i < n; i++)
{
for (j = 2; j < strlen(a[i]); j++)
{
if (a[i][j] == c)
{
if (a[i][j + 1] != '\0')
{ 
 first(a[i][j + 1]);
}
if (a[i][j + 1] == '\0' && c != a[i][0])
{
follow(a[i][0]);
}
}
}
}
 for (i = 0; i < m; i++) 
 {
 for (j = i + 1; j < m; j++)
 { 
 if (f[i] == f[j]) 
 {
 for (int k = j; k < m - 1; k++)
 {
 f[k] = f[k + 1];
 }
 m--;
 j--;
 }
 }
 }
 void first(char c)
{ 
int i;
if (!isupper(c))
{
f[m++] = c;
}
else
{
for (i = 0; i < n; i++
{
if (a[i][0] == c) 
 {
 if (a[i][2] == '$')
 {
follow(a[i][0]);
}
else if (islower(a[i][2]))
{
 f[m++] = a[i][2];
}
else
{
first(a[i][2]);
}
 }
}
}
 for (i = 0; i < m; i++)
 {
 for (int j = i + 1; j < m; j++)
 { 
 if (f[i] == f[j]) 
 {
for (int k = j; k < m - 1; k++)
{ 
 f[k] = f[k + 1];
}
m--;
j--;
}
}
}
}
if (!isupper(c))
{
 f[m++] = c;
}
else
{
for (i = 0; i < n; i++)
{
 if (a[i][0] == c) 
 {
if (a[i][2] == '$')
 {
follow(a[i][0]);
}
else if (islower(a[i][2]))
{
f[m++] = a[i][2];
}
else
{
first(a[i][2]);
}
}
}
}
 for (i = 0; i < m; i++) 
 {
for (int j = i + 1; j < m; j++)
{
 if (f[i] == f[j])
 {
for (int k = j; k < m - 1; k++)
{ 
 f[k] = f[k + 1];
}
m--;
j--;
}
}
}
}
