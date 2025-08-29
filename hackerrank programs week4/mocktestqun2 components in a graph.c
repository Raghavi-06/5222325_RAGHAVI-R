#include <stdio.h>
#define MAX 200005
int parent[MAX], compSize[MAX];
int find(int x) 
{
 if (parent[x] != x)
 parent[x] = find(parent[x]);
 return parent[x];
}
void unite(int x, int y)
{
 int rx = find(x);
 int ry = find(y);
 if (rx != ry)
 {
 if (compSize[rx] < compSize[ry]) 
 {
 parent[rx] = ry;
 compSize[ry] += compSize[rx];
 } else {
 parent[ry] = rx;
 compSize[rx] += compSize[ry];
 }
 }
}
int main() 
{
 int n;
 scanf("%d", &n);
 for (int i = 1; i <= 2*n; i++) 
 {
 parent[i] = i;
 compSize[i] = 1;
 }
 for (int i = 0; i < n; i++) 
 {
 int u, v;
 scanf("%d %d", &u, &v);
 unite(u, v);
 }
 int minSize = MAX;
 int maxSize = 0;
 for (int i = 1; i <= 2*n; i++)
 {
 if (parent[i] == i && compSize[i] > 1) 
 { 
 if (compSize[i] < minSize) minSize = compSize[i];
 if (compSize[i] > maxSize) maxSize = compSize[i];
 }
 }
 printf("%d %d\n", minSize, maxSize);
 return 0;
}