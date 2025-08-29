#include <stdio.h>
#include <limits.h>

int max(int a, int b)
 {
    return (a > b) ? a : b;
}
void solve() 
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
     {
        scanf("%d", &arr[i]);
    }
    int max_so_far = INT_MIN;
    int current_max = 0;
    for (int i = 0; i < n; i++) 
    {
        current_max += arr[i];
        if (current_max > max_so_far)
         {
            max_so_far = current_max;
        }
        if (current_max < 0) 
        {
            current_max = 0;
        }
    }
    if (max_so_far == 0) 
    {
        int highest_negative = INT_MIN;
        for (int i = 0; i < n; i++) 
        {
            if (arr[i] > highest_negative)
             {
                highest_negative = arr[i];
            }
        }
        max_so_far = highest_negative;
    }
    int non_contiguous_sum = 0;
    int has_positive = 0;
    for (int i = 0; i < n; i++)
     {
        if (arr[i] > 0) {
            non_contiguous_sum += arr[i];
            has_positive = 1;
        }
    }
    if (!has_positive) 
    {
        int highest_negative = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (arr[i] > highest_negative)
             {
                highest_negative = arr[i];
            }
        }
        non_contiguous_sum = highest_negative;
    }
    printf("%d %d\n", max_so_far, non_contiguous_sum);
}
int main()
 {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
