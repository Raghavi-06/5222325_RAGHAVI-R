#include <stdio.h>

void sort_ascending(int arr[], int n) 
{
    int i, j, temp;
   //outer loop for passes
    for (i = 0; i < n - 1; i++) {
     //inner loop for comparisons in each pass
        for (j = 0; j < n - i - 1; j++) {
        //if the current element is greater than the next, swap them
            if (arr[j] > arr[j + 1]) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sort_descending(int arr[], int n) {
    int i, j, temp;
    //outer loop for passes
    for (i = 0; i < n - 1; i++) {
     //inner loop for comparisons in each pass
        for (j = 0; j < n - i - 1; j++) {
    //if the current element is less than the next, swap them
            if (arr[j] < arr[j + 1])
             {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void solve_query(int n, int k) 
{
    int a[n], b[n]; //declare arrays to store the input values

 //read the elements for array 'a'
    for (int i = 0; i < n; i++)
     {
        scanf("%d", &a[i]);
        
    }

 //read the elements for array 'b'
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &b[i]);
    }

    //sort array 'a' in ascending order using our simple function
    sort_ascending(a, n);

    //sort array 'b' in descending order using our simple function
    sort_descending(b, n);

    //now, we check the condition for all pairs
    int possible = 1; //assume it's possible at the start (1 = true, 0 = false)
    for (int i = 0; i < n; i++) 
    {
//the core check: if the sum of elements at any position is less than k
        if (a[i] + b[i] < k) 
        {
            possible = 0; //the condition is not met, so it's impossible
            break;      //we can stop checking and exit the loop
        }
    }

    //print the final result based on our 'possible' flag
    if (possible)
     {
        printf("YES\n");
    } 
    else 
    {
        printf("NO\n");
    }
}

int main() {
    int q; //the number of queries
    scanf("%d", &q);

    //a loop that runs for each query
    while (q--) {
        int n, k; //'n' is the size of the arrays, 'k' is the target sum
        scanf("%d %d", &n, &k);

        //call the function to solve the current query
        solve_query(n, k);
    }

    return 0; 
}
