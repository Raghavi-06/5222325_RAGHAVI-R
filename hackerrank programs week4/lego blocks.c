#include <stdio.h>
#include <string.h>

#define MOD 1000000007
long long ways_to_build[1001];
long long total_ways[1001];
long long solid_ways[1001];
long long power(long long base, long long exp) 
{
    long long res=1;
    base %=MOD;
    while(exp > 0)
     {
        if(exp % 2 == 1)res =(res*base)%MOD;
        base=(base*base) % MOD;
        exp /= 2;
    }
  return res;
}
void precompute_ways() 
{
    ways_to_build[0] = 1; 
    ways_to_build[1] = 1;
    ways_to_build[2] = 2;
    ways_to_build[3] = 4; 
    for (int i=4; i<=1000; i++)
 {
  ways_to_build[i] = (ways_to_build[i-1]+ways_to_build[i-2] + ways_to_build[i-3] + ways_to_build[i-4]) % MOD;
  }
}
void solve()
 {
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1; i<=m; i++) 
    {
    total_ways[i] = power(ways_to_build[i],n);
    }
    solid_ways[1] = 1;
    for (int i=2; i<=m; i++) 
    {
    long long invalid_ways = 0;
    for (int j=1; j<i; j++) 
    {
    long long temp = (solid_ways[j] * total_ways[i - j]) % MOD;
     invalid_ways = (invalid_ways + temp) % MOD;
 }
 solid_ways[i] = (total_ways[i] - invalid_ways + MOD) % MOD;
}
  printf("%lld\n", solid_ways[m]);
}
int main() 
{
    precompute_ways();
    int t;
    scanf("%d", &t);
    while (t--)
 {
    solve();
    }
  return 0;
}
