#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head, *last;

void createCLL()
{
    struct Node *temp, *currentNode;
    int n;

    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("Enter the Node data : ");
        currentNode = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &currentNode->data);

        if (head == NULL)
        {
            head = temp = currentNode;
        }
        else
        {
            temp->next = currentNode;
            temp = currentNode;
        }
    }
    last = temp;
    temp->next = head;
}

void displayCLL()
{
    struct Node *ptr = head;
    printf("\nThe Linked List Elements are \n");

    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

void insertBefore()
{
    struct Node *ptr = head;
    struct Node *pre = ptr;
    int value, data;
    printf("\nEnter the value of Node you want to Insert before : ");
    scanf("%d", &value);
    printf("\nEnter the data of Node you want to Insert : ");
    scanf("%d", &data);
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;

    while (ptr->data != value && ptr->next != head)
    {
        pre = ptr;
        ptr = ptr->next;
    }

    if (ptr == head)
    {
        newnode->next = head;
        last->next = newnode;
        head = newnode;
    }
    else
    {
        newnode->next = ptr;
        pre->next = newnode;
    }
}

void insertAfter()
{
    struct Node *ptr = head;
    int value, data;
    printf("\nEnter the value of Node you want to Insert before : ");
    scanf("%d", &value);
    printf("\nEnter the data of Node you want to Insert : ");
    scanf("%d", &data);
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;

    while (ptr->data != value && ptr->next != head)
    {
        ptr = ptr->next;
    }

    if (ptr == last)
    {
        newnode->next = ptr->next;
        ptr->next = newnode;
        last = newnode;
    }
    else
    {
        newnode->next = ptr->next;
        ptr->next = newnode;
    }
}

void delete ()
{
    struct Node *ptr = head;
    struct Node *pre = ptr;
    int value, x = 0;
    printf("\nEnter the value of Node you want to Delete : ");
    scanf("%d", &value);

    while (ptr->data != value && ptr->next != head)
    {
        if (ptr->next == last)
        {
            x++;
        }
        pre = ptr;
        ptr = ptr->next;
    }

    if (x == 1)
    {
        printf("\nNo Node found with given data\n");
    }
    else if (ptr == head)
    {
        last->next = ptr->next;
        free(head);
        head = ptr->next;
    }
    else if (ptr == last)
    {
        pre->next = last->next;
        free(last);
        last = pre->next;
    }
    else
    {
        pre->next = ptr->next;
        free(ptr);
    }
}

int main()
{
    int choice;
    do
    {

        printf("\n\n--------Circular Linked List Operations-------\n");
        printf("1-->Create\n");
        printf("2-->Display\n");
        printf("3-->Insert before a Node\n");
        printf("4-->Insert after a Node\n");
        printf("5-->Delete\n");
        printf("6-->Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {

        case 1:
            createCLL();
            break;
        case 2:
            displayCLL();
            break;
        case 3:
            insertBefore();
            break;
        case 4:
            insertAfter();
            break;
        case 5:
            delete ();
            break;
        case 6:
            break;
        default:
            printf("\nSelect feom given options\n");
        }

    } while (choice != 6);

    return 0;
}
