#include <stdio.h>
typedef struct
{
int petrol;
int distance;
} 
Pump;
int main() 
{
 int n;
 scanf("%d",&n);
 Pump pumps[n];
 for(int i=0; i<n; i++)
{
scanf("%d %d",&pumps[i].petrol,&pumps[i].distance);
}
int start_index = 0;
int current_petrol = 0;
for (int i=0; i<n; i++)
{
 current_petrol += pumps[i].petrol - pumps[i].distance;
 if (current_petrol < 0)
{
 start_index = i+1;
 current_petrol = 0;
 }
}
 printf("%d\n",start_index); 
 return 0;
}