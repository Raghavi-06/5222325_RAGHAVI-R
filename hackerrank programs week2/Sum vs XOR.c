#include <stdio.h>
 
//function to find the number of valid x values
long long sumXor(long long n) 
{
    if(n==0) 
    {
        return 1;
    }

    long long count_zeros=0;
    long long temp=n;

//count the number of zero bits in the binary representation of n
    while(temp>0)
     {
        if ((temp&1)==0) 
        {
            count_zeros++;
        }
        temp>>=1;
    }
//the number of solutions is 2 raised to the power of the count of zero bits
    return 1LL<<count_zeros;
}

int main() 
{
    long long n;
    scanf("%lld", &n);
    printf("%lld\n",sumXor(n));
    return 0;
}
