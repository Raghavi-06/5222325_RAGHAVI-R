#include <stdio.h>
#include <stdlib.h>

int getPlayerRank(int score, int* distinct_scores, int distinct_count) 
{
    int left = 0;
    int right = distinct_count - 1;
    int rank = distinct_count + 1; 
    
    while (left <= right)
     {
        int mid = left + (right - left) / 2;
        if (score >= distinct_scores[mid]) 
        {
            rank = mid + 1;
            right = mid - 1;
        }
         else
          {
            left = mid + 1;
        }
    }
    return rank;
}
int main()
 {
    int n, m;
    scanf("%d", &n);
    int* ranked_scores = (int*)malloc(n * sizeof(int));
    if (ranked_scores == NULL) 
    {
        return 1; 
    }
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &ranked_scores[i]);
    }
    scanf("%d", &m);
    int* player_scores = (int*)malloc(m * sizeof(int));
    if (player_scores == NULL) 
    {
        free(ranked_scores);
        return 1; 
    }
    for (int i = 0; i < m; i++) 
    {
        scanf("%d", &player_scores[i]);
    }
    int* distinct_scores = (int*)malloc(n * sizeof(int));
    if (distinct_scores == NULL) {
        free(ranked_scores);
        free(player_scores);
        return 1; 
    }
    int distinct_count = 0;
    if (n > 0)
     {
    distinct_scores[distinct_count++] = ranked_scores[0];
    for (int i = 1; i < n; i++) 
    {
     if (ranked_scores[i] != ranked_scores[i - 1])
     {
      distinct_scores[distinct_count++] = ranked_scores[i];
            }
        }
    }
    for (int i = 0; i < m; i++) 
    {
     int player_score = player_scores[i];
    int rank = getPlayerRank(player_score, distinct_scores, distinct_count);
    printf("%d\n", rank);
    }
    free(ranked_scores);
    free(player_scores);
    free(distinct_scores);

    return 0;
}
