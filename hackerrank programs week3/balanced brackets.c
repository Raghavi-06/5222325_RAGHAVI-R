#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isBalanced(char* s) 
{
    char stack[1000];
    int top = -1;
    for (int i = 0; i < strlen(s); i++) 
    {
        char currentChar = s[i];
        if (currentChar == '(' || currentChar == '[' || currentChar == '{') 
        {
            if (top < 999)
             {
                stack[++top] = currentChar;
            } 
            else 
            {
                return false; //stack overflow
            }
        } else
         {
            if (top == -1)
             {
                return false;
            }
   char lastOpen = stack[top--];
if ((currentChar == ')' && lastOpen != '(') ||
 (currentChar == ']' && lastOpen != '[') ||
 (currentChar == '}' && lastOpen != '{')) 
 {
    return false;
            }
        }
    }

    return top == -1;
}
int main() 
{
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) 
    {
        char s[1000];
        scanf("%s", s);
        if (isBalanced(s))
         {
            printf("YES\n");
        } else
         {
            printf("NO\n");
        }
    }
    return 0;
}