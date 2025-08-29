#include <stdio.h>
#include <stdlib.h>
#define EDGE_WEIGHT 6
typedef struct
{
 int *nbr;
 int cnt;
 int cap;
} 
Vec;
void add_edge(Vec*adj,int u,int v)
 {
 if (adj[u].cap==0) 
 {
 adj[u].cap=4;
 adj[u].nbr=(int*)malloc(adj[u].cap*sizeof(int));
 } 
 else if(adj[u].cnt==adj[u].cap) 
 {
 adj[u].cap*=2;
 adj[u].nbr =(int*)realloc(adj[u].nbr,adj[u].cap*sizeof(int));
 }
 adj[u].nbr[adj[u].cnt++]=v;
 }
 int main(void) 
 {
 int q;
 if (scanf("%d",&q)!=1)
return 0;
while(q--) 
 {
 int n,m;
 scanf("%d %d",&n,&m);
 Vec*adj=(Vec*)malloc((n+1)*sizeof(Vec));
 for(int i=1; i<=n;++i)
 { 
 adj[i].nbr=NULL; adj[i].cnt=0; adj[i].cap=0;
 }
 for (int i=0; i<m;++i) 
 {
 int u,v;
 scanf("%d %d",&u,&v);
 add_edge(adj,u,v);
 add_edge(adj,v,u);
 }
 int s; 
 scanf("%d",&s);
int*dist = (int*)malloc((n+1)*sizeof(int));
for(int i=1; i<=n;++i) dist[i]=-1;
 int*queue=(int*)malloc((n+5)*sizeof(int));
 int head=0, tail=0;
 dist[s]=0;
 queue[tail++]=s;
 while (head < tail)
 {
 int u=queue[head++];
 for (int j=0; j<adj[u].cnt;++j)
 {
 int v=adj[u].nbr[j];
 if (dist[v] == -1) 
 {
 dist[v] = dist[u] + EDGE_WEIGHT;
 queue[tail++] = v;
 }
 }
 }
 int first = 1;
 for (int i = 1; i <= n; ++i)
{
 if (i == s) continue;
 if (!first) printf(" ");
 printf("%d", dist[i]);
 first = 0;
}
 printf("\n");
 for (int i=1; i<=n; ++i) free(adj[i].nbr);
 free(adj);
 free(dist);
 free(queue);
 }
 return 0;
}