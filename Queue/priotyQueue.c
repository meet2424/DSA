#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};
struct node *start = NULL;

void traversal()
{
    struct node *ptr = start;

    printf("Printing priority queue elements\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        printf("%d ", ptr->priority);
        printf("\n");
        ptr = ptr->next;
    }
    printf("\n");
}

int dequeue()
{
    int v = start->data;
    struct node *ptr = start;
    start = start->next;
    free(ptr);
    return v;
}

void enqueue(int data, int priority)
{
    struct node *pre = start;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->priority = priority;
    if (start == NULL || priority < start->priority)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {

        while (pre->next != NULL && pre->next->priority <= priority)
        {
            pre = pre->next;
        }

        ptr->next = pre->next;
        pre->next = ptr;
    }
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
    if (start == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    int choice, value, priority;
    do
    {
        printf("\n*********Priority Queue operations using linked list*********\n");
        printf("1  -->  Enqueue\n2  -->  Dequeue\n3  -->  Display\n4  -->  Exit\n");
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
                printf("Enter the priority of element : ");
                scanf("%d", &priority);
                enqueue(value, priority);
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
            printf("Exiting...");
            break;
        default:
            printf("Invalid choice");
        }
    } while (choice != 4);

    return 0;
}