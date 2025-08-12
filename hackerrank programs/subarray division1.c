#include <stdio.h>

int main()
 {
    int n; //the number of squares on the chocolate bar
    scanf("%d", &n);

    int s[n]; //an array to store the numbers on each square

    
    //read the numbers on each square
    for (int i = 0; i < n; i++)
     {
        scanf("%d", &s[i]);
    }
    
    int d; //Ron's birth day (the target sum)
    int m; //Ron's birth month (the target length)

    //read the birth day and birth month
    scanf("%d %d", &d, &m);

    int count = 0;
    
    // Loop through the chocolate bar to find all possible starting positions for a segment of length 'm'
    // The loop runs from i = 0 to n-m, because a segment of length 'm'
    //cannot start after index (n-m-1) without going off the end of the bar.
    for (int i = 0; i <= n - m; i++) 
    {
        int current_sum = 0; 
        
    //inner loop to calculate the sum of the segment of length 'm'
   //starting at index 'i'.
        for (int j = 0; j < m; j++) {
            current_sum += s[i + j];
        }
        
     //check if the sum of the current segment equals the target day 'd'
        if (current_sum == d)
         {
            count++;
         }
    }
    
    //print the final count of valid segments
    printf("%d\n", count);
    
    return 0;
}