#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_index(int arr[],int size,int value)
 {
    for (int i=0; i<size;i++)
     {
        if(arr[i]==value)
     {
        return i;
     }
}
    return -1;
}
//function to swap two integers
void swap(int* a, int* b) 
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify_up(int arr[], int i)
 {
    while (i>0 && arr[(i-1)/2]>arr[i])
     {
        swap(&arr[i],&arr[(i-1)/2]);
        i=(i-1)/2;
    }
}
void heapify_down(int arr[],int size,int i)
 {
    int smallest=i;
    int left = 2*i+1;
    int right = 2*i+2;
  if (left < size && arr[left] < arr[smallest]) 
 {
 smallest = left;
 }
if (right < size && arr[right] < arr[smallest])
 {
        smallest=right;
    }
    if (smallest != i)
     {
     swap(&arr[i],&arr[smallest]);
     heapify_down(arr,size,smallest);
    }
}
void insert_min_heap(int arr[],int* size,int value) 
{
    (*size)++;
    arr[*size-1]=value;
    heapify_up(arr,*size-1);
}

void delete_from_min_heap(int arr[], int* size, int value) 
{
    int index_to_delete = find_index(arr, *size, value);
    if (index_to_delete == -1)
     {
        return; 
    }
    arr[index_to_delete] = arr[*size - 1];
    (*size)--;
    heapify_down(arr, *size, index_to_delete);
}

int main() 
{
    int Q;
    scanf("%d",&Q);
    int heap[100000];
    int heap_size = 0;
    for (int i=0; i<Q; i++)
     {
        int type;
        scanf("%d", &type);
        if (type == 1) {
        int v;
        scanf("%d", &v);
       insert_min_heap(heap, &heap_size, v);
        } 
       else if (type == 2)
     {
     int v;
     scanf("%d", &v);
     delete_from_min_heap(heap, &heap_size, v);
    }
      else if (type == 3)
    {
     if (heap_size > 0) 
 {
   printf("%d\n", heap[0]);
       }
     }
   }
    return 0;
}