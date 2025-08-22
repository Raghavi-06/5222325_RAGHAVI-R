#include <stdio.h>
#include <string.h>
#include <math.h>

  char* counterGame(long long n) 
{
    if (n == 1) 
    {
        return "Richard";
    }

    int turns = 0;
    while (n > 1)
     {
        if ((n & (n - 1)) == 0) { //n is a power of 2
            int power = 0;
            long long temp = n;
            while (temp > 1)
             {
                temp >>= 1;
                power++;
            }
            turns += power;
            break;
        } else 
        { // n is not a power of 2
            long long nearestPowerOf2 = 1;
            while (nearestPowerOf2 < n)
             {
                nearestPowerOf2 <<= 1;
            }
            nearestPowerOf2 >>= 1;
            n -= nearestPowerOf2;
            turns++;
        }
    }

    if (turns % 2 == 0)
     {
        return "Richard";
    } else
     {
        return "Louise";
    }
}

int main() 
{
    int t;
    scanf("%d",&t);
    while (t--) 
    {
        long long n;
        scanf("%lld", &n);
        printf("%s\n", counterGame(n));
    }
    return 0;
}
