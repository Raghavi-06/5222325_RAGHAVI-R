#include <stdio.h>
#include <stdlib.h>

//simple helper function to find the minimum of two integers.
int min(int a, int b) 
{
    if (a < b)
 {
        return a;
    }
    return b;
}

//function to calculate the minimum number of page turns.
int pageCount(int n, int p)
 {
    //calculate turns from the front of the book.
    int turns_from_front = p / 2;
    
    //calculate turns from the back of the book.
    //the total number of sheets in the book is n / 2.
    //number of sheets to turn from the back is (n / 2) - (p / 2).
    //this formula is robust for both even and odd n.
    int turns_from_back = (n / 2) - (p / 2);
    
    //return the minimum of the two possible turn counts.
    return min(turns_from_front, turns_from_back);
}

int main() 
{
    int n, p;
    
    //read n and p from standard input.
    if (scanf("%d", &n) != 1 || scanf("%d", &p) != 1) {
        //handle input reading error if necessary.
        return 1;
    }
    
    //call the pageCount function with the input values.
    int result = pageCount(n, p);
    
    // Print the result to standard output.
    printf("%d\n", result);
    
    return 0;
}
