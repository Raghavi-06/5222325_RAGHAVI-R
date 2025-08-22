#include <stdio.h>

int main() 
{
    int n, pairs = 0;
    scanf("%d", &n);
    int ar[101] = {0}; //assuming sock colors are between 1 and 100

    for (int i = 0; i < n; i++)
 {
        int color;
        scanf("%d", &color);
        ar[color]++;
    }

    for (int i = 0; i < 101; i++)
 {
        pairs += ar[i] / 2;
    }

    printf("%d\n", pairs);

    return 0;
}
