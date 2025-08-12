#include <stdio.h>

int lonelyinteger(int n, int a[]) {
    int result=0;
    for (int i = 0; i<n; i++) {
        result = result ^a[i];
    }   
    return result; 
}

 int main(){
     int n;
     scanf("%d", &n); // read the number of elements
     
     int a[n];
     for (int i=0; i<n; i++) {
        scanf("%d", &a[i]); //read the array elements
     }
        
     int lonely = lonelyinteger(n,a);
     printf("%d\n",lonely); //print the unique element
     
     return 0;
 }
