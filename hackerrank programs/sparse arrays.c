#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char strings[n][21]; // assuming for maximum string length is 20
    for (int i=0; i<n; i++) {
        scanf("%s", strings[i]);
    }
    int q;
    scanf("%d", &q);
    char quries[q][21]; // assuming for maximum qurey string length is 20
    for (int i=0; i<q; i++) {
        scanf("%s", quries[i]);
    }
    
    for (int i=0; i<q; i++) {
        int count =0;
        for (int j=0; j<n; j++) {
        if (strcmp(quries[i], strings[j]) ==0) {
            count ++;
        }
      }
      printf("%d\n", count);
    }
     return 0;
}