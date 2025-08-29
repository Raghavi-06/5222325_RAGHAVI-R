#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 26

char* isValid(char* s) {
    int freq[MAX] = {0};
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }
    int minFreq = 0, maxFreq = 0;
    for (int i = 0; i < MAX; i++) {
        if (freq[i] > 0) {
            if (minFreq == 0 || freq[i] < minFreq) minFreq = freq[i];
            if (freq[i] > maxFreq) maxFreq = freq[i];
        }
    }
    if (minFreq == maxFreq) return "YES";
    int minCount = 0, maxCount = 0;
    for (int i = 0; i < MAX; i++) {
        if (freq[i] == minFreq) minCount++;
        else if (freq[i] == maxFreq) maxCount++;
    }
if (minFreq == 1 && minCount == 1 && maxCount * maxFreq == (len - 1)) 
{
        return "YES";
    }
    if ((maxFreq - minFreq == 1) && maxCount == 1) {
        return "YES";
    }

    return "NO";
}

int main() {
    char s[100005];
    scanf("%s", s);
    printf("%s\n", isValid(s));
    return 0;
}