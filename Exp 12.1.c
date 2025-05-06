// Develop Menu Driven Program to implement stack operations including push, pop, overload and traversing allowing for analysis of stack behaviour and efficiency.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int items[MAX];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

int push(Stack *s, int item)
{
    if (isFull(s))
    {
        printf("Stack overflow! Cannot push %d\n", item);
        return 0;
    }
    else
    {
        s->items[++(s->top)] = item;
        printf("Pushed %d onto stack\n", item);
        return 1;
    }
}

int pop(Stack *s, int *popped_item)
{
    if (isEmpty(s))
    {
        printf("Stack underflow! Cannot pop\n");
        return 0;
    }
    else
    {
        *popped_item = s->items[(s->top)--];
        printf("Popped %d from stack\n", *popped_item);
        return 1;
    }
}

void traverse(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents (top to bottom):\n");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d\n", s->items[i]);
    }
}

void overload(Stack *s)
{
    int n, item;
    printf("How many elements to push onto the stack? ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid number.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    if (s->top + n >= MAX)
    {
        printf("Stack overflow! Can only push %d more items\n", MAX - s->top - 1);
        return;
    }
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &item) != 1)
        {
            printf("Invalid input. Stopping overload insert.\n");
            while (getchar() != '\n')
                ;
            break;
        }
        push(s, item);
    }
}

void menu()
{
    Stack s;
    int choice, item, popped_item;
    initStack(&s);

    do
    {
        printf("\n==== Stack Menu ====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Overload (push multiple)\n");
        printf("4. Traverse (display stack)\n");
        printf("5. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number 1-5.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter item to push: ");
            if (scanf("%d", &item) != 1)
            {
                printf("Invalid input.\n");
                while (getchar() != '\n')
                    ;
                break;
            }
            push(&s, item);
            break;

        case 2:
            if (pop(&s, &popped_item))
            {
            }
            break;

        case 3:
            overload(&s);
            break;

        case 4:
            traverse(&s);
            break;

        case 5:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice, please select 1-5.\n");
        }
    } while (choice != 5);
}

int main()
{
    menu();
    return 0;
}