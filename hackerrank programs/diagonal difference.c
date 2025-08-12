#include <stdio.h>
#include <stdlib.h>  // for the abs() function

int main() {
    int n,i;
      int primary_diagonal_sum = 0;
      int secondary_diagonal_sum = 0;
   
   //read the size of the square matrix 
   scanf("%d", &n);
   
   // iterate through the rows of the matrix
   for(i = 0; i<n; i++) {
        int j;
   // iterate trough the columns of the matrix
      for (j=0; j<n; j++) {
            int element;
            scanf("%d", &element);
            
    // if the element is on the primary diagonal
            if (i == j) {
                primary_diagonal_sum += element;
            }
            
    // if the element is on the secondary diagonal
       if (i+j == n-1) {
        secondary_diagonal_sum += element;
       }
      }
   }
       
      // calculate and print the absolute difference 
      printf("%d\n", abs(primary_diagonal_sum - secondary_diagonal_sum));
    
    return 0;
}
