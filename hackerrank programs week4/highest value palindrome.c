#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* highestValuePalindrome(char*s,int n,int k) 
{
    char* result=strdup(s);
    int changes_made[n];
    for (int i=0;i<n;i++) 
    {
     changes_made[i]=0;
    }
    int left=0;
    int right=n-1;
    while (left<right)
     {
      if(result[left] !=result[right]) 
        {
         if(result[left]>result[right]) 
         {
          result[right]=result[left];
     } 
     else 
     {
       result[left]=result[right];
     }
      changes_made[left]=1;
        k--;
     }
    left++;
     right--;
   }

 if (k<0) 
 {
  return "-1";
    }
 left=0;
 right=n-1;
    while (left<=right)
 {
   if (k>0) 
 {
  if (left==right) 
  {
   if (k>0)
    {
     result[left]='9';
    }
 } 
 else 
 {
    if (result[left] !='9') 
    {
    if (changes_made[left]==1) 
    {
    result[left]='9';
    result[right]='9';
     k--;
     } 
     else if (k>=2) 
     {
     result[left]='9';
     result[right]='9';
     k -= 2;
             }
           }
      }
    }
      left++;
     right--;
 }
   return result;
}
int main()
 {
    int n,k;
    scanf("%d %d",&n,&k);

    char s[n+1];
    scanf("%s",s);

    char*result = highestValuePalindrome(s,n,k);
    printf("%s\n",result);
    
    if (strcmp(result,"-1")!= 0)
 {
   free(result);
 }
    return 0;
}
