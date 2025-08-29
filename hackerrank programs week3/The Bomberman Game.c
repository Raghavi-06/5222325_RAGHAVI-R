#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to print the grid
void print_grid(int r, int c, char grid[r][c])
 {
    for (int i = 0; i < r; i++) 
    {
        for (int j = 0; j < c; j++) 
        {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}
//function to perform one detonation cycle and return the new grid
void detonate_and_return_new_grid(int r, int c, char initial_grid[r][c], char result_grid[r][c]) 
{
//fill the result grid with 'O' initially
    for(int i = 0; i < r; i++)
     {
        for(int j = 0; j < c; j++) 
        {
         result_grid[i][j] = 'O';
        }
    }

    int dx[] = {0, 0, 1, -1, 0};
    int dy[] = {0, 1, 0, 0, -1};
    //detonate bombs from the initial grid
    for (int i = 0; i < r; i++) 
    {
        for (int j = 0; j < c; j++)
         {
            if (initial_grid[i][j] == 'O') 
            {
                for (int k = 0; k < 5; k++) 
                {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
//corrected boundary check: ensure ni and nj are within bounds
    if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
         result_grid[ni][nj] = '.';
                    }
                }
            }
        }
    }
}
int main() {
    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);
 //read the initial grid state
    char initial_grid[r][c];
    for(int i = 0; i < r; i++) {
    scanf("%s", initial_grid[i]);
    }
    //case 1: n is 0 or 1.
    if(n <= 1)
     {
        print_grid(r, c, initial_grid);
        return 0;
    }
//case 2: n is even. The grid is completely full of bombs.
    if (n % 2 == 0)
     {
        for (int i = 0; i < r; i++) 
        {
            for (int j = 0; j < c; j++)
             {
                printf("O");
            }
            printf("\n");
        }
        return 0;
    }
 //case 3 & 4: n is odd. The state depends on modulo 4.
    char final_grid[r][c];
    if (n % 4 == 3) {
detonate_and_return_new_grid(r, c, initial_grid, final_grid);
    } 
    else 
    { 
    //n % 4 == 1
    //first detonation on the initial grid
        char temp_grid[r][c];
detonate_and_return_new_grid(r, c, initial_grid, temp_grid);
//second detonation on the result of the first
 detonate_and_return_new_grid(r, c, temp_grid, final_grid);
    }
    print_grid(r, c, final_grid);
    return 0;
}
