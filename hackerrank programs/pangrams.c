#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1000];
    // Read a full line of input
    scanf("%[^\n]", s);
    
      int alphabet[26]={0};
    int count=0;

    for (int i=0; s[i] !='\0'; i++) {
        char ch=s[i];
        if (isalpha(ch)) {
            ch=tolower(ch);
            int index=ch-'a';
            if (alphabet[index]==0) {
                alphabet[index] = 1;
                count++;
            }
        }
    }
     if (count==26) {
        printf("pangram\n");
    } else {
        printf("not pangram\n");
    }

    return 0;
}
