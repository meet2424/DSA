#include <stdio.h>
#include <conio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1 && front != 0)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = value;
}

int dequeue()
{
    int x = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }

    return (x);
}

int peek()
{
    return (queue[front]);
}

void display()
{
    int i;
    if (front <= rear)
    {
        printf("Queue contains : ");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    else
    {
        printf("Queue contains : ");
        for (i = front; i <= MAX - 1; i++)
        {
            printf("%d ", queue[i]);
        }
        for (i = 0; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int isFull()
{
    if ((rear == front - 1) || (rear == MAX - 1 && front == 0))
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (front == -1 || rear == -1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int value, choice;
    do
    {
        printf("\n-------------------Circular Queue Operations----------------------\n");
        printf("1  -->  Enqueue\n2  -->  Dequeue\n3  -->  Peek\n4  -->  Display\n5  -->  Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            if (isFull())
            {
                printf("Queue Overflow\n");
            }
            else
            {
                printf("Enter the value to insert : ");
                scanf("%d", &value);

                enqueue(value);
            }
            break;
        case 2:
            if (isEmpty())
            {
                printf("Queue Underflow\n");
            }
            else
            {
                value = dequeue(queue);
                printf("Deleted %d from the Queue\n", value);
            }
            break;
        case 3:
            if (isEmpty())
            {
                printf("Queue is empty\n");
            }
            else
            {
                value = peek(queue);
                printf("Front of queue is : %d\n", value);
            }
            break;
        case 4:
            if (isEmpty())
            {
                printf("Queue Underflow\n");
            }
            else
            {
                display(queue);
            }
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice");
        }
    } while (choice != 5);

    return 0;
}