#include <stdio.h>
#include <stdlib.h>
int* icecreamParlor(int m, int cost_count, int* cost, int* result_count) 
{
    int i, diff;
    int* map = (int*)malloc(sizeof(int) * 10001);
    for (i = 0; i <= 10000; i++)
     {
    map[i] = 0;
    }
    *result_count = 2;
    int* result = (int*)malloc(sizeof(int) * (*result_count));
    for (i = 0; i < cost_count; i++) 
    {
        diff = m - cost[i];
        if (diff > 0 && map[diff] != 0)
         {
 if (map[diff] < (i + 1))
  {
 result[0] = map[diff];
  result[1] = i + 1;
     } 
     else
     {
         result[0] = i + 1;
        result[1] = map[diff];
     }
        free(map);
         return result;
        }
        map[cost[i]] = i + 1;
    }
    free(map);
    return result;
}
int main()
 {
    int t, m, n, i, result_count;
    scanf("%d", &t);
    while (t--)
     {
        scanf("%d", &m);
        scanf("%d", &n);
        int* cost = (int*)malloc(sizeof(int) * n);
        for (i = 0; i < n; i++)
         {
     scanf("%d", &cost[i]);
        }
int* result = icecreamParlor(m, n, cost, &result_count);
 printf("%d %d\n", result[0], result[1]);
free(cost);
 free(result);
    }
    return 0;
}

