#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 1000000
char *history[MAX_STACK_SIZE];
int top = -1;
void push(char *s)
 {
    if (top < MAX_STACK_SIZE - 1) 
    {
        history[++top] = (char *)malloc(strlen(s) + 1);
        strcpy(history[top], s);
    }
}
void pop(char *s) 
{
    if (top >= 0) 
    {
        strcpy(s, history[top]);
        free(history[top]);
        top--;
    }
}
int main()
 {
    int Q;
    scanf("%d", &Q);
    char s[1000001] = ""; 
    while (Q--)
     {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            char W[1000001];
            scanf("%s", W);
            push(s);
            strcat(s, W);
        } else if (type == 2) {
            int k;
            scanf("%d", &k);
            push(s);
            int len = strlen(s);
            s[len - k] = '\0';
        } else if (type == 3) {
            int k;
            scanf("%d", &k);
            printf("%c\n", s[k - 1]);
        } else if (type == 4) {
            pop(s);
        }
    }
    for (int i = 0; i <= top; i++)
     {
        free(history[i]);
    }

    return 0;
}
