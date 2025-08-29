#include <stdio.h>
#include <stdlib.h>

int get_sum(int arr[], int size) 
{
    int sum = 0;
    for (int i = 0; i < size; i++)
     {
     sum += arr[i];
    }
    return sum;
}
int main()
 {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);
    int* h1 = (int*)malloc(n1 * sizeof(int));
    int* h2 = (int*)malloc(n2 * sizeof(int));
    int* h3 = (int*)malloc(n3 * sizeof(int));
    if (h1 == NULL || h2 == NULL || h3 == NULL) 
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < n1; i++) 
    {
        scanf("%d", &h1[i]);
    }
    for (int i = 0; i < n2; i++)
     {
        scanf("%d", &h2[i]);
    }
    for (int i = 0; i < n3; i++) 
    {
        scanf("%d", &h3[i]);
    }
    int sum1 = get_sum(h1, n1);
    int sum2 = get_sum(h2, n2);
    int sum3 = get_sum(h3, n3);
    int i = 0, j = 0, k = 0;
    while (sum1 != sum2 || sum2 != sum3) 
    {
        if (i >= n1 || j >= n2 || k >= n3) 
        {
            printf("0\n");
            free(h1);
            free(h2);
            free(h3);
            return 0;
        }
        if (sum1 >= sum2 && sum1 >= sum3) 
        {
            sum1 -= h1[i++];
        } else if (sum2 >= sum1 && sum2 >= sum3) 
        {
            sum2 -= h2[j++];
        } else if (sum3 >= sum1 && sum3 >= sum2) 
        {
            sum3 -= h3[k++];
        }
    }
    printf("%d\n", sum1);
    free(h1);
    free(h2);
    free(h3);
    return 0;
}
