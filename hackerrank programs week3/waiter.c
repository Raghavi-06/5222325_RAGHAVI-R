#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50001
#define MAX_PRIMES 1201
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
    if (s->top < MAX_SIZE - 1) 
    {
        s->arr[++s->top] = value;
    }
}
int pop(Stack* s) {
    if (isStackEmpty(s)) 
    {
        return -1;
    }
    return s->arr[s->top--];
}
void generatePrimes(int primes[], int count) 
{
    int is_prime[MAX_SIZE] = {0};
    int prime_count = 0;
    for (int p = 2; prime_count < count; p++)
     {
        if (is_prime[p] == 0) 
        {
            primes[prime_count++] = p;
            for (int i = p * 2; i < MAX_SIZE; i += p) 
            {
                is_prime[i] = 1;
            }
        }
    }
}
int main()
 {
    int n, q;
    scanf("%d %d", &n, &q);
    Stack current_A, next_A, B;
    initStack(&current_A);
    initStack(&next_A);
    initStack(&B);
    
    for (int i = 0; i < n; i++)
     {
        int plate;
        scanf("%d", &plate);
        push(&current_A, plate);
    }
    
    int primes[MAX_PRIMES];
    generatePrimes(primes, q);
    for (int i = 0; i < q; i++) 
    {
        int prime = primes[i];
        while (!isStackEmpty(&current_A)) 
        {
            int plate = pop(&current_A);
            if (plate % prime == 0) 
            {
                push(&B, plate);
            } 
            else 
            {
                push(&next_A, plate);
            }
        }
        
        while (!isStackEmpty(&B)) {
            printf("%d\n", pop(&B));
        }
        current_A = next_A;
        initStack(&next_A);  
    }

    while (!isStackEmpty(&current_A)) 
    {
        printf("%d\n", pop(&current_A));
    }

    return 0;
}
