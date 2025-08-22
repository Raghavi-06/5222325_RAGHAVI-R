#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to sort a string alphabetically
void sort_string(char *str) 
{
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (str[i] > str[j]) 
            {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

//function to check if the grid can be sorted
char* gridChallenge(char **grid, int n)
 {
    // Sort each row alphabetically
    for (int i = 0; i < n; i++) 
    {
        sort_string(grid[i]);
    }

    //check if each column is sorted alphabetically
    for (int j = 0; j < n; j++) 
    {
        for (int i = 0; i < n - 1; i++)
         {
            if (grid[i][j] > grid[i+1][j]) 
            {
                return "NO";
            }
        }
    }

    return "YES";
}

int main() 
{
    int t;
    scanf("%d", &t);

    while (t--) 
    {
        int n;
        scanf("%d", &n);

    //dynamically allocate memory for the grid
        char **grid = (char **)malloc(n * sizeof(char *));
        for (int i = 0; i < n; i++) 
        {
            grid[i] = (char *)malloc((n + 1) * sizeof(char));
            scanf("%s", grid[i]);
        }

        //call the function and print the result
        char *result = gridChallenge(grid, n);
        printf("%s\n", result);

    //free the allocated memory
        for (int i = 0; i < n; i++) 
        {
            free(grid[i]);
        }
        free(grid);
    }

    return 0;
}
