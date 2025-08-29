#include <stdio.h>
#include <stdlib.h>

int compare(const void*a,const void*b) 
{
  return (*(int*)a-*(int*)b);
}
int main()
 {
    int n,k;
    scanf("%d %d",&n,&k);
    int houses[n];
    for(int i=0; i<n;i++) 
    {
     scanf("%d",&houses[i]);
    }
    qsort(houses, n, sizeof(int), compare);
    int transmitters = 0;
    int i = 0;
    while (i < n) 
    {
     transmitters++;
    int loc = houses[i];
    int j=i+1;
    while (j<n && houses[j]<=loc+k) 
  {
   j++;
 }
    loc = houses[j-1];
    i = j;
    while (i<n && houses[i] <= loc+k) 
    {
    i++;
  }
}
    printf("%d\n",transmitters);
    return 0;
}
