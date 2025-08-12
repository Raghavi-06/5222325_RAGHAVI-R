#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n); // Read the size of the array
    int arr[n];
    
    // Initialize counters for positive, negative, and zero numbers
    int positive_count = 0;
    int negative_count = 0;
    int zero_count = 0;
    
    // Read the array elements and count positive, negative, and zero numbers
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > 0) {
            positive_count++;
        } else if (arr[i] < 0) {
            negative_count++;
        } else {
            zero_count++;
        }
    }
    
    // Calculate and print the ratios with 6 decimal places
    printf("%.6f\n", (double)positive_count / n);
    printf("%.6f\n", (double)negative_count / n);
    printf("%.6f\n", (double)zero_count / n);
    
    return 0;
}



