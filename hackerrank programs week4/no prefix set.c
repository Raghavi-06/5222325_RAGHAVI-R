#include <stdio.h>
#include <string.h>

#define MAX_EDGES (6000000+5)
#define MAX_NODES (MAX_EDGES+5)
#define ALPHABET 10
typedef struct
 {
    int to;
    int next;
    unsigned char ch;
} Edge;
typedef struct 
{
    int first;
    unsigned char end;
} Node;
static Edge edges[MAX_EDGES];
static Node nodes[MAX_NODES];
static int edgeCnt = 0, nodeCnt = 1;
static inline void init_node(int idx) 
{
    nodes[idx].first = -1;
    nodes[idx].end = 0;
}
static inline int find_child(int u, unsigned char ch) 
{
    for (int e = nodes[u].first; e != -1; e = edges[e].next)
    if (edges[e].ch == ch) return edges[e].to;
     return -1;
}
static inline int add_child(int u, unsigned char ch)
 {
    int v = nodeCnt++;
    init_node(v);
    edges[edgeCnt].to=v;
    edges[edgeCnt].ch=ch;
    edges[edgeCnt].next = nodes[u].first;
    nodes[u].first = edgeCnt++;
    return v;
}
int main(void) 
{
    init_node(0);
    int n;
    if (scanf("%d", &n) != 1)
     return 0;
    char s[70];
    for(int i = 0; i < n; ++i)
     {
    if(scanf("%s", s) != 1) 
    return 0;
    int u = 0;
    int bad = 0;
    for(int j=0;s[j];++j)
     {
    if(nodes[u].end) 
{ 
  bad=1;
   break;
}
unsigned char c =(unsigned char)(s[j] - 'a');
int v=find_child(u, c);
if (v==-1) v=add_child(u,c);
 u=v;
 }
 if(!bad)
{
 if(nodes[u].end)bad =1; 
 else if(nodes[u].first !=-1) bad=1; 
  }
   if(bad)
{
 printf("BAD SET\n%s\n",s);
     return 0;
  }
 nodes[u].end = 1; 
  }
   printf("GOOD SET\n");
    return 0;
}