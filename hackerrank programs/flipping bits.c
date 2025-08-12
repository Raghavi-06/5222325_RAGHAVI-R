#include <stdio.h>

int main() {
    int q;
    unsigned int n;
    
    // read the number of quries 
    scanf("%d", &q);
    
    //loop through each query 
    while (q--) {
        // read the 32-bit unsigned integer
        scanf("%u", &n);
        
        // use the bitwise NOT operator(~) to flip all 32 bits
        unsigned int result = ~n;
        
        //print the result as an unsigned integer
        printf("%u\n", result);
    }
    return 0;
    
}

