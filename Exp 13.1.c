// Create a Menu Driven Program to implement queue operations such as enqueue, dequeue, overload , underload and traversing enabling evaluation of queue management and performance characterstics.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int items[MAX];
    int front;
    int rear;
    int count;
} Queue;

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isEmpty(Queue *q)
{
    return q->count == 0;
}

int isFull(Queue *q)
{
    return q->count == MAX;
}

int enqueue(Queue *q, int item)
{
    if (isFull(q))
    {
        printf("Queue overflow! Cannot enqueue %d\n", item);
        return 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = item;
    q->count++;
    printf("Enqueued %d\n", item);
    return 1;
}

int dequeue(Queue *q, int *item)
{
    if (isEmpty(q))
    {
        printf("Queue underflow! Cannot dequeue\n");
        return 0;
    }
    *item = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    printf("Dequeued %d\n", *item);
    return 1;
}

void traverse(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents (front to rear):\n");
    int i = q->front;
    for (int c = 0; c < q->count; c++)
    {
        printf("%d\n", q->items[i]);
        i = (i + 1) % MAX;
    }
}

void overload(Queue *q)
{
    int n, item;
    printf("How many elements to enqueue? ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid number.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    if (q->count + n > MAX)
    {
        printf("Queue overflow! Can only enqueue %d more elements\n", MAX - q->count);
        return;
    }
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &item) != 1)
        {
            printf("Invalid input. Stopping overload.\n");
            while (getchar() != '\n')
                ;
            break;
        }
        enqueue(q, item);
    }
}

void underload(Queue *q)
{
    int n, item;
    printf("How many elements to dequeue? ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid number.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    if (n > q->count)
    {
        printf("Queue underflow! Only %d elements available\n", q->count);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        dequeue(q, &item);
    }
}

void menu()
{
    Queue q;
    int choice, item;
    initQueue(&q);

    do
    {
        printf("\n==== Queue Menu ====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Overload (enqueue multiple)\n");
        printf("4. Underload (dequeue multiple)\n");
        printf("5. Traverse (display queue)\n");
        printf("6. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number 1-6.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter item to enqueue: ");
            if (scanf("%d", &item) != 1)
            {
                printf("Invalid input.\n");
                while (getchar() != '\n')
                    ;
                break;
            }
            enqueue(&q, item);
            break;

        case 2:
            if (dequeue(&q, &item))
            {
            }
            break;

        case 3:
            overload(&q);
            break;

        case 4:
            underload(&q);
            break;

        case 5:
            traverse(&q);
            break;

        case 6:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice, please select 1-6.\n");
        }
    } while (choice != 6);
}

int main()
{
    menu();
    return 0;
}