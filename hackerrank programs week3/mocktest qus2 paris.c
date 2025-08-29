#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) 
{
return (*(int *)a - *(int *)b);
}
int pairs(int k, int arr_count, int* arr) 
{
qsort(arr, arr_count, sizeof(int), compare);
int count = 0;
int left = 0;
int right = 0;
while(right < arr_count)
{
 if(arr[right] - arr[left] == k)
{
count++;
left++;
right++;
} 
else if (arr[right] - arr[left] < k) 
{
right++;
} 
else
{
left++;
 }
}
 return count;
}
int main()
{
 int n, k;
 scanf("%d %d", &n, &k);
 int arr[n];
 for(int i = 0; i < n; i++)
{
 scanf("%d", &arr[i]);
 }
 int result = pairs(k, n, arr);
 printf("%d\n", result);
 return 0;
}