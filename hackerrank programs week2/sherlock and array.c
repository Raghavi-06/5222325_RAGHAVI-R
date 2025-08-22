#include <stdio.h>
#include <string.h>

   //function to solve the balancedSums problem
char* balancedSums(int arr_count, int* arr)
 {
    long long totalSum = 0;
    for (int i = 0; i < arr_count; i++) 
    {
        totalSum += arr[i];
    }

    long long leftSum = 0;
    for (int i = 0; i < arr_count; i++)
     {
        long long rightSum = totalSum - leftSum - arr[i];
        if (leftSum == rightSum)
         {
            return "YES";
        }
        leftSum += arr[i];
    }
    return "NO";
}

int main()
 {
    int T; //number of test cases
    scanf("%d", &T);

    while (T--) 
    {
        int n; //number of elements in the array
        scanf("%d", &n);

        int arr[n];
        for (int i = 0; i < n; i++)
         {
            scanf("%d", &arr[i]);
        }

        printf("%s\n", balancedSums(n, arr));
    }

    return 0;
}
