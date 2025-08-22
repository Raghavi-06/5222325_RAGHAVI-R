#include <stdio.h>
#include <string.h>

long long superDigit(long long n) 
{
    if (n < 10)
     {
        return n;
    }
    long long sum = 0;
    while (n > 0)
     {
        sum += n % 10;
        n /= 10;
    }
    return superDigit(sum);
}

int main() 
{
    char n_str[100001];
    long long k;
    scanf("%s %lld", n_str, &k);

    long long sum = 0;
    for (int i = 0; i < strlen(n_str); i++) 
    {
        sum += n_str[i] - '0';
    }

    long long initialSuperDigit = superDigit(sum);
    long long result = superDigit(initialSuperDigit * k);

    printf("%lld\n", result);

    return 0;
}
