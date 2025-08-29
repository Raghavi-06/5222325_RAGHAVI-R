#include <stdio.h>
#include <stdlib.h>

int find_parent(int parent[], int i) 
{
    if (parent[i]==i) 
    {
        return i;
    }
    return parent[i] = find_parent(parent, parent[i]);
}
void union_sets(int parent[], int rank[], int x, int y)
 {
    int root_x = find_parent(parent, x);
    int root_y = find_parent(parent, y);
    if (root_x != root_y)
     {
        if (rank[root_x] < rank[root_y]) 
        {
            parent[root_x] = root_y;
        } else if (rank[root_x] > rank[root_y])
         {
            parent[root_y] = root_x;
        } 
        else 
        {
            parent[root_y] = root_x;
            rank[root_x]++;
        }
    }
}

int main() 
{
    int q; 
    scanf("%d", &q);

    while (q--)
 {
     int n, m;
     long long c_lib, c_road;
     scanf("%d %d %lld %lld", &n, &m, &c_lib, &c_road);
    
     if (c_lib <= c_road) 
     {
         long long total_cost = (long long)n * c_lib;
         for (int i = 0; i < m; i++)
          {
         int u, v;
          scanf("%d %d", &u, &v);
     }
         printf("%lld\n", total_cost);
         continue;
  }
    int parent[n + 1];
    int rank[n + 1];
    for (int i = 1; i <= n; i++) 
 {
     parent[i] = i;
     rank[i] = 0;
}
   int num_components = n;
   for (int i = 0; i < m; i++)
    {
      int u, v;
      scanf("%d %d", &u, &v);
      int root_u = find_parent(parent, u);
      int root_v = find_parent(parent, v);
   if (root_u != root_v) 
   {
    union_sets(parent, rank, u, v);
     num_components--;
   }
 }
   long long total_cost = (long long)num_components * c_lib + (long long)(n - num_components) * c_road;
     printf("%lld\n", total_cost);
 }
 return 0;
}
