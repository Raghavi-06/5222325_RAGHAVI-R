#include <stdio.h>
// This function calculates the maximum possible sum of the upper-left
quadrant
// of a 2n x 2n matrix.
long flippingMatrix(int n, int matrix[2 * n][2 * n]) {
 long maxSum = 0;
 int i, j;
 // Iterate through the top-left n x n quadrant of the matrix.
 for (i = 0; i < n; i++) {
 for (j = 0; j < n; j++) {
 // Find the maximum value among the four symmetrical positions.
 int maxVal = matrix[i][j];
 
 // Check the element flipped horizontally.
 if (matrix[i][2 * n - 1 - j] > maxVal) {
 maxVal = matrix[i][2 * n - 1 - j];
 }
 
 // Check the element flipped vertically.
 if (matrix[2 * n - 1 - i][j] > maxVal) {
 maxVal = matrix[2 * n - 1 - i][j];
 }
 
 // Check the element flipped both horizontally and vertically.
 if (matrix[2 * n - 1 - i][2 * n - 1 - j] > maxVal) {
 maxVal = matrix[2 * n - 1 - i][2 * n - 1 - j];
 }
 // Add the maximum value to the total sum.
 maxSum += maxVal;
 }
 }
 return maxSum;
}
int main() {
 int q, n, i, j;
 
 // Read the number of queries.
 scanf("%d", &q);
 // Loop through each query.
while (q--) {
 // Read the dimension n for the 2n x 2n matrix.
 scanf("%d", &n);
 
 // Declare a 2n x 2n matrix using a VLA.
 int matrix[2 * n][2 * n];
 
 // Read the elements of the 2n x 2n matrix.
 for (i = 0; i < 2 * n; i++) {
 for (j = 0; j < 2 * n; j++) {
 scanf("%d", &matrix[i][j]);
 }
 }
 
 // Call the function to get the maximal sum and print the result.
 long result = flippingMatrix(n, matrix);
 printf("%ld\n", result);
 }
 
 return 0;
}