#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100000 
typedef struct 
{
    int arr[MAX_SIZE];
    int top;
} Stack;
void initStack(Stack* s)
 {
    s->top = -1;
}
int isStackEmpty(Stack* s) 
{
    return s->top == -1;
}
void push(Stack* s, int value) 
{
    if (s->top == MAX_SIZE - 1)
     {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = value;
}
int pop(Stack* s)
 {
    if (isStackEmpty(s)) {
        return -1; 
    }
    return s->arr[s->top--];
}
typedef struct 
{
    Stack stack1; 
    Stack stack2; 
} Queue;
void initQueue(Queue* q)
 {
    initStack(&q->stack1);
    initStack(&q->stack2);
}
void enqueue(Queue* q, int value) 
{
    push(&q->stack1, value);
}
int dequeue(Queue* q)
 {
    if (isStackEmpty(&q->stack1) && isStackEmpty(&q->stack2)) {
        return -1; 
    }
    if (isStackEmpty(&q->stack2)) 
    {
        while (!isStackEmpty(&q->stack1)) 
        {
            push(&q->stack2, pop(&q->stack1));
        }
    }
    return pop(&q->stack2);
}
int front(Queue* q)
 {
    if (isStackEmpty(&q->stack1) && isStackEmpty(&q->stack2)) {
        return -1;
    }
    if (isStackEmpty(&q->stack2))
     {
        while (!isStackEmpty(&q->stack1))
         {
            push(&q->stack2, pop(&q->stack1));
        }
    }
    return q->stack2.arr[q->stack2.top];
}
int main() 
{
    Queue q;
    initQueue(&q);
    int num_queries;
    scanf("%d", &num_queries);
    for (int i = 0; i < num_queries; ++i)
     {
        int type;
        scanf("%d", &type);
        if (type == 1) 
        {
            int value;
            scanf("%d", &value);
            enqueue(&q, value);
        } 
        else if (type == 2)
         {
            dequeue(&q);
        }
         else if (type == 3) 
         {
            printf("%d\n", front(&q));
        }
    }

    return 0;
}

