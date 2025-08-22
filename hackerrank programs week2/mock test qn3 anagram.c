#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
 int q;
 scanf("%d",&q); 
 //read the number of test cases
 while(q--) 
 {
 char s[10001]; 
 //string to hold the input
 scanf("%s",s);
 int len=strlen(s);
 //if the length is odd,it's impossible to split.
 if(len % 2 !=0) {
 printf("-1\n");
 continue;
 }
 int n=len /2; 
 //length of each half
 int count1[26] = {0}; //frrequency array for the first half
 int count2[26] = {0}; 
 //frequency array for the second half
 int changes=0;
//populate frequency arrays for each half
 for(int i=0;i<n;i++) {
 count1[s[i]-'a']++;
 count2[s[i+n]-'a']++;
 }
 //compare frequencies to find the number of changes
 for(int i=0;i<26;i++) 
 {
 if (count1[i]>count2[i])
 {
 changes +=count1[i] - count2[i];
 }
 }
 printf("%d\n",changes);
 }
 return 0;
}