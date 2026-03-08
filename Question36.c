#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;
int size = 0;

void enqueue(int value, int capacity)
{
    rear = (rear + 1) % capacity;
    queue[rear] = value;
    size++;
}

int dequeue(int capacity)
{
    int val = queue[front];
    front = (front + 1) % capacity;
    size--;
    return val;
}

int main()
{
    int n, m;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        enqueue(x, n);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        int temp = dequeue(n);
        enqueue(temp, n);
    }

    for(int i = 0; i < size; i++)
    {
        printf("%d ", queue[(front + i) % n]);
    }

    return 0;
}