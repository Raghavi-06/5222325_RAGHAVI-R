#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STRINGS 200001
int compare(const void* a, const void* b) 
{
const char* str1 = *(const char**)a;
const char* str2 = *(const char**)b;
int len1 = strlen(str1);
int len2 = strlen(str2);
if (len1 != len2)
 {
 return len1 - len2;
 }
 return strcmp(str1, str2);
}
int main()
{
 int n;
 scanf("%d", &n);
 char** unsorted = (char**)malloc(n * sizeof(char*));
 if (unsorted == NULL) 
 {
 return 1; 
 }
 char buffer[1000001]; 
 for(int i = 0; i < n; i++)
{
 scanf("%s", buffer);
 unsorted[i] = (char*)malloc(strlen(buffer) + 1); 
 if (unsorted[i] == NULL) 
 {
 return 1; 
 }
 strcpy(unsorted[i], buffer);
}
 qsort(unsorted, n, sizeof(char*), compare);
for (int i = 0; i < n; i++)
 {
 printf("%s\n", unsorted[i]);
 free(unsorted[i]);
 }
 free(unsorted);
 return 0;
}