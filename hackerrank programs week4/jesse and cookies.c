#include <stdio.h>
#include <stdlib.h>

struct MinHeap
 {
    long long* harr; 
    int capacity; 
    int heap_size; 
};
struct MinHeap* create_min_heap(int capacity) 
{
 struct MinHeap* min_heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
 min_heap->heap_size = 0;
 min_heap->capacity = capacity;
 min_heap->harr=(long long*)malloc(capacity*sizeof(long long));
 return min_heap;
}
void swap(long long* a, long long* b) 
{
 long long temp = *a;
 *a = *b;
 *b = temp;
}
void min_heapify(struct MinHeap* min_heap, int idx)
 {
  int smallest =idx;
  int left = 2*idx+1;
  int right = 2*idx+2;
 if (left < min_heap->heap_size && min_heap->harr[left] < min_heap->harr[smallest]) 
 {
     smallest = left;
    }
if(right < min_heap->heap_size && min_heap->harr[right] < min_heap->harr[smallest]) 
{
 smallest = right;
 }
 if (smallest != idx)
 {
    swap(&min_heap->harr[idx], &min_heap->harr[smallest]);
     min_heapify(min_heap, smallest);
    }
}
void insert_key(struct MinHeap* min_heap, long long key) 
{
    if (min_heap->heap_size == min_heap->capacity) 
    {
        return;
    }
    min_heap->heap_size++;
    int i = min_heap->heap_size-1;
    min_heap->harr[i] = key;
    while (i != 0 && min_heap->harr[(i - 1) / 2] > min_heap->harr[i])
    {
     swap(&min_heap->harr[i], &min_heap->harr[(i - 1) / 2]);
     i = (i-1)/2;
    }
}
long long extract_min(struct MinHeap* min_heap) 
{
    if (min_heap->heap_size <= 0) 
    {
        return -1;
    }
    if (min_heap->heap_size == 1)
     {
        min_heap->heap_size--;
        return min_heap->harr[0];
    }
    long long root = min_heap->harr[0];
    min_heap->harr[0] = min_heap->harr[min_heap->heap_size - 1];
    min_heap->heap_size--;
    min_heapify(min_heap, 0);
    return root;
}
void solve() 
{
    int n;
    long long k;
    scanf("%d %lld", &n, &k);
    struct MinHeap* min_heap = create_min_heap(n);
    for (int i = 0; i < n; i++) {
     long long sweetness;
     scanf("%lld", &sweetness);
     insert_key(min_heap, sweetness);
    }
    int operations = 0;
    while (min_heap->heap_size > 1 && min_heap->harr[0] < k) {
     long long least_sweet = extract_min(min_heap);
     long long second_least_sweet = extract_min(min_heap);
  long long new_cookie_sweetness = least_sweet + 2 * second_least_sweet;
    insert_key(min_heap, new_cookie_sweetness);
    operations++;
 }
    if (min_heap->harr[0] >= k)
     {
        printf("%d\n", operations);
    } 
    else 
    {
     printf("-1\n");
    }
    free(min_heap->harr);
    free(min_heap);
}
int main() 
{
    solve();
    return 0;
}
