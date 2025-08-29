#include <stdio.h>
#include <stdlib.h>

int main() 
{
 int n,m;
 scanf("%d %d",&n,&m);
 long long *arr=(long long *)calloc(n+2,sizeof(long long));
 for (int i=0; i<m;i++)
 {
   int a,b;
   long long k;
   scanf("%d %d %lld",&a,&b,&k);
   arr[a] += k;
   if (b+1<=n) 
   {
    arr[b+1] -=k;
    }
 }
    long long current_sum=0;
    long long max_value=0;
    
    for (int i=1;i<=n;i++) 
    {
     current_sum +=arr[i];
     if (current_sum>max_value) 
     {
        max_value = current_sum;
     }
  }
    printf("%lld\n",max_value);

    free(arr);
    return 0;
}
