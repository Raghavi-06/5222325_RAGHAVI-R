#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//function to check if a string is a palindome 
bool is_palindrome(char* s) 
{
 int len = strlen(s);
 for (int i=0; i<len/2; i++) 
 {
 if (s[i] != s[len-1-i]) {
 return false;
 } 
 }
 return true;
}
// function to find the palindrome index
int palindomeIndex(char* s)
{
 int len =strlen(s);
 for (int i=0; i<len/2; i++) {
 if (s[i] != s[len-1-i]){
 
 // case 1: remove character at index i
 char temp1[len];
 strcpy(temp1, s);
 memmove(&temp1[i], &temp1[i+1], len-i);
 if (is_palindrome(temp1)) { 
 return i;
 }
 
 //case 2:remove character at index len-1-i
 char temp2[len];
 strcpy(temp2, s);
 memmove(&temp2[len-1-i], &temp2[len-i],i+1);
 if (is_palindrome(temp2)) {
 return len -1-i;
 }
 //if neither removal works, no solution exists 
 return -1;
 }
 }
 //if the string is already a palindrome
 return -1;
}
int main(){
 int q;
 scanf("%d", &q);
 while (q--) {
 char s[100005];
 scanf("%s", s);
 printf("%d\n",palindomeIndex(s));
 }
 return 0;
}