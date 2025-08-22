#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//comparison function for qsort
int compare(const void* a, const void* b) 
{
    return (*(int*)a - *(int*)b);
}

int maxMin(int k, int arr_count, int* arr) 
{
    //sort the array in ascending order
    qsort(arr, arr_count, sizeof(int), compare);
    
    //initialize minimum unfairness to a very large value
    long long min_unfairness = LLONG_MAX;
    
    //iterate through all possible sub-arrays of size k
    //the loop runs from the first element up to the element
    //from which a sub-array of size k can be formed.
    for (int i = 0; i <= arr_count - k; i++) {
 //Calculate the unfairness for the current sub-array
    //the sub-array starts at index i and ends at i + k - 1
    long long current_unfairness = (long long)arr[i + k - 1] - arr[i];
        
    //update the minimum unfairness if the current one is smaller
        if (current_unfairness < min_unfairness)
         {
            min_unfairness = current_unfairness;
        }
    }
    
    //return the minimum unfairness
    return (int)min_unfairness;
}

int main() 
{
    int n, k;
    
    //read the number of elements
    scanf("%d", &n);
    
    //read the size of the sub-array
    scanf("%d", &k);
    
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) 
    {
        return 1; // Handle memory allocation error
    }
    
    //read the elements of the array
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    //call the maxMin function and print the result
    int result = maxMin(k, n, arr);
    printf("%d\n", result);
    
    //free the dynamically allocated memory
    free(arr);
    
    return 0;
}
