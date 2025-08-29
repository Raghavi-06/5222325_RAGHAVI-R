#include <stdio.h>
#include <limits.h>

int deque[100001];
int front = 0, rear = -1;
void push_back(int x) 
{
  deque[++rear] = x;
}
void pop_front()
 {
  if (front <= rear)
{
  front++;
  }
}
void pop_back() 
{
 if (front<=rear)
 {
  rear--;
  }
 }
int peek_front() 
{
 if (front <= rear) 
 {
  return deque[front];
 }
  return -1;
}
int main() 
{
  int n,q;
  scanf("%d %d",&n,&q);
  int arr[n];
  for(int i=0; i<n;i++)
  { 
    scanf("%d", &arr[i]);
 }
 while(q--)
  {
     int d;
     scanf("%d", &d);
     long long min_of_maxes = -1;
     front = 0;
     rear = -1;
     for (int i=0;i<d;i++) 
        {
    while (front<=rear && arr[deque[rear]]<=arr[i]) 
    {
     pop_back();
   }
   push_back(i);
 }
     min_of_maxes = arr[peek_front()];
     for (int i = d; i < n; i++) 
     {
     while (front<=rear && deque[front]<=i-d)
     {
     pop_front();
  }
    while (front<=rear && arr[deque[rear]]<=arr[i])
   {
     pop_back();
  }
   push_back(i);
 if (min_of_maxes==-1 || arr[peek_front()]<min_of_maxes) 
 {
  min_of_maxes = arr[peek_front()];
   }
 }
 printf("%lld\n",min_of_maxes);
    }
    return 0;
}
