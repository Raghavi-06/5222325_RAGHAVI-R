#include <stdio.h>
#include <stdlib.h>
// Comparison function for qsort
int compare(const void *a, const void *b) 
{
 return (*(int *)a - *(int *)b);
}
// Function to find the median of an array
int findMedian(int arr[], int n)
{
 // Sort the array
 qsort(arr, n, sizeof(int), compare);
// The median is the middle element of the sorted array
 // Since n is guaranteed to be odd, there is only one middle element
 return arr[n / 2];
}
int main()
{
 int n, i;
 // Read the size of the array
 scanf("%d", &n);
 int arr[n];
 // Read the array elements
 for (i = 0; i < n; i++) 
 {
 scanf("%d", &arr[i]);
 }
 // Find and print the median
 int median = findMedian(arr, n);
 printf("%d\n", median);
 return 0;
}