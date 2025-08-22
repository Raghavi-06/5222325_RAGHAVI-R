#include <stdio.h>
#include <stdlib.h>

int main()
 {
    int n, q;
    scanf("%d %d", &n, &q);

 //create a dynamic 2D array
    int **arr = (int **)malloc(n*sizeof(int *));
    for (int i = 0; i<n; i++) {
        arr[i] = (int*)malloc(0*sizeof(int));
    }

 //keep track of the size of each dynamic array
    int*sizes = (int*)calloc(n,sizeof(int));
    int lastAnswer = 0;

 //process all the queries
    for (int i=0; i<q; i++) {
        int queryType, x,y;
        scanf("%d %d %d",&queryType, &x, &y);
        
    //calculate the index of the dynamic array
        int idx = (x^lastAnswer) % n;

        if (queryType == 1) 
        {
 //reallocate memory for the dynamic array and append the new integer
            sizes[idx]++;
            arr[idx]=(int *)realloc(arr[idx], sizes[idx] * sizeof(int));
            arr[idx][sizes[idx]-1] = y;
        } 
        else if (queryType == 2) 
        {
    //find the integer at the specified index and update lastAnswer
    int element = arr[idx][y % sizes[idx]];
     lastAnswer = element;
     printf("%d\n", lastAnswer);
        }
    }

    //free the allocated memory
    for (int i = 0; i < n; i++) 
    {
        free(arr[i]);
    }
    free(arr);
    free(sizes);

    return 0;
}
