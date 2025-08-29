#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
 {
    int val;
    int index;
} Element;
int compare_asc(const void*a, const void*b)
 {
return ((Element*)a)->val - ((Element*)b)->val;
}
int compare_desc(const void*a, const void*b) 
{
 return ((Element*)b)->val-((Element*)a)->val;
}
int min_swaps(int arr[],int n,int ascending) 
{
 Element elements[n];
 for (int i=0;i<n;i++)
 {
     elements[i].val = arr[i];
     elements[i].index = i;
    }
    if(ascending) 
    {
    qsort(elements,n,sizeof(Element),compare_asc);
    } 
    else 
    {
    qsort(elements,n,sizeof(Element),compare_desc);
  }
    int visited[n];
    for (int i=0;i<n;i++)
     {
        visited[i]=0;
    }
    int swaps = 0;
    for (int i=0;i<n;i++) 
    {
    if (visited[i] || elements[i].index == i)
  {
     continue;
 }
    int cycle_size = 0;
    int j = i;
    while (!visited[j])
     {
     visited[j] = 1;
     j = elements[j].index;
    cycle_size++;
   }
  swaps += (cycle_size - 1);
  }
  return swaps;
}
int main() 
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int arr_copy[n];
    for (int i=0;i<n;i++)
     {
        scanf("%d",&arr[i]);
        arr_copy[i]=arr[i];
    }
    int swaps_asc = min_swaps(arr,n,1);
    int swaps_desc = min_swaps(arr_copy,n,0);

    if (swaps_asc < swaps_desc) 
    {
        printf("%d\n",swaps_asc);
    } 
    else
     {
        printf("%d\n",swaps_desc);
    }
 return 0;
}
