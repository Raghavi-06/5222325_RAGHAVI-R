#include <stdio.h>

int main() {
    int n, i;

//the problem states the input values are less than 100, so we need a frequency array of size 100.
    //initialize all elements to 0.
    int frequency_array[100] = {0};

    //read the number of items in the input array
    scanf("%d", &n);

    //loop to read each element of the input array
    for (i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);
        
    //increment the count for the current element in the frequency array.
     //the value of the element (e.g., 63) is used as the index.
        frequency_array[element]++;
    }

    //print the final frequency array
    for (i = 0; i < 100; i++) {
        printf("%d ", frequency_array[i]);
    }
    printf("\n");

    return 0;
}