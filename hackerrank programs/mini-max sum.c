#include <stdio.h>

int main() {
    long long int arr[5];
    long long int sum = 0;
    
    // Read the 5 integers and calculate their total sum 
    for (int i = 0; i < 5; i++) {
        scanf("%lld", &arr[i]);
        sum += arr[i];
    }
    
    // Initialize min_sum and max_sum with the sum of the first four elements
    
    long long int min_sum = sum - arr[0];
    long long int max_sum = sum - arr[0];
    
    // Iterate through the array to find the minimum and maximum sums
    // by subtracting each element from the total sum
    for (int i = 0; i < 5; i++) {
        long long int current_sum = sum - arr[i];
        
        if (current_sum < min_sum) {
            min_sum = current_sum;
        }
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    
    // Print the minimum and maximum sums on a single line
    printf("%lld %lld\n", min_sum, max_sum);
    
    return 0 ;
    
}
