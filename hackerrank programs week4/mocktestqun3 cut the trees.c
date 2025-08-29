#include <stdio.h>
#include <stdlib.h>
#define MAXN 100005
int n;
int weight[MAXN];
long long totalSum;
long long subSum[MAXN];
int *adj[MAXN];
int adjSize[MAXN];
int visited[MAXN];
long long minDiff;
long long dfs(int u) 
{
 visited[u] = 1;
subSum[u] = weight[u];
 for (int i = 0; i < adjSize[u]; i++)
 {
 int v = adj[u][i];
 if (!visited[v])
 {
 subSum[u] += dfs(v);
 }
 }
 if (u != 1) 
{ 
long long diff = llabs(totalSum - 2*subSum[u]);
 if (diff < minDiff) minDiff = diff;
 }
 return subSum[u];
}
int main() 
{
 scanf("%d", &n);
 for (int i = 1; i <= n; i++)
 {
 scanf("%d", &weight[i]);
 totalSum += weight[i];
 adj[i] = NULL;
 adjSize[i] = 0;
 }
 for (int i = 0; i < n-1; i++) 
 {
 int u, v;
 scanf("%d %d", &u, &v);
 adjSize[u]++;
 adjSize[v]++;
 adj[u] = realloc(adj[u],adjSize[u]*sizeof(int));
 adj[v] = realloc(adj[v],adjSize[v]*sizeof(int));
 adj[u][adjSize[u]-1] = v;
 adj[v][adjSize[v]-1] = u;
 }
 minDiff = 1e18;
 dfs(1);
 printf("%lld\n", minDiff);
 for (int i = 1; i <= n; i++) free(adj[i]);
 return 0;
}
