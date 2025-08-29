#include <stdio.h>
#include <stdlib.h>

void minimumBribes(int arr_count, int* arr) 
{
int bribes = 0; 
 for (int i = arr_count - 1; i >= 0; i--) 
    {
        if (arr[i] != i + 1)
         {
if (i - 1 >= 0 && arr[i-1] == i + 1)
 {
     bribes++;
    int temp = arr[i-1];
    arr[i-1] = arr[i];
    arr[i] = temp;
         } 
    else if (i - 2 >= 0 && arr[i-2] == i + 1) 
    {
     bribes += 2;
        int temp = arr[i-2];
        arr[i-2] = arr[i-1];
        arr[i-1] = arr[i];
        arr[i] = temp;
            } 
    else
  {
     printf("Too chaotic\n");
         return;
            }
        }
    }
    printf("%d\n", bribes);
}

int main()
 {
    int t;
    scanf("%d", &t);
    
    while (t--)
     {
        int n;
        scanf("%d", &n);
        int *q = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
         {
            scanf("%d", &q[i]);
        }  
        minimumBribes(n, q); 
        free(q);
    }
    return 0;
}
