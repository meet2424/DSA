#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL, *rear = NULL;

void traversal()
{
    struct node *ptr = front;

    printf("Printing queue elements\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int dequeue()
{
    int v = front->data;
    if (front == rear)
    {
        free(front);
        front = NULL;
        rear = NULL;
    }
    else
    {
        struct node *ptr = front;
        front = front->next;
        free(ptr);
    }
    return v;
}

void enqueue(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    if (rear == NULL)
    {
        rear = ptr;
        front = ptr;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
    rear->next = NULL;
}

int peek()
{

    return front->data;
}

int isFull()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        return 1;
    }
    else
    {
        free(temp);
        return 0;
    }
}

int isEmpty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    int choice, value;
    do
    {
        printf("\n\n*********Queue operations using linked list*********\n");
        printf("1  -->  Enqueue\n2  -->  Dequeue\n3  -->  Display\n4  -->  Peek\n5  -->  Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            if (isFull())
            {
                printf("Queue is Full!\n");
            }
            else
            {
                printf("Enter the data to insert : ");
                scanf("%d", &value);
                enqueue(value);
            }
            break;
        case 2:
            if (isEmpty())
            {
                printf("Queue is EMPTPY!\n");
            }
            else
            {
                value = dequeue();
                printf("Deleted %d from queue\n", value);
            }
            break;
        case 3:
            if (isEmpty())
            {
                printf("Queue is EMPTPY!\n");
            }
            else
            {
                traversal();
            }
            break;
        case 4:
            if (isEmpty())
            {
                printf("Queue is EMPTPY!\n");
            }
            else
            {
                value = peek();
                printf("The value at front of queue is : %d", value);
            }
            break;
        case 5:
            printf("Exiting...");
            break;
        default:
            printf("Invalid choice");
        }
    } while (choice != 5);

    return 0;
}