#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverse(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void deleteAtBetween(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *ptr;
    int i = 0;
    while (i != index - 2)
    {
        p = p->next;
        i++;
    }

    ptr = p->next;
    p->next = ptr->next;
    free(ptr);
}

void deleteWithGivenValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *ptr = head->next;
    while (ptr->data != value && ptr->next != NULL)
    {
        p = p->next;
        ptr = ptr->next;
    }
    if (ptr->next != NULL)
    {
        p->next = ptr->next;
        free(ptr);
    }
    else
    {
        printf("\nNo element was present with given value\n\n");
    }
}
int main()
{
    struct Node *head, *currentNode, *temp;

    for (int i = 0; i < 5; i++)
    {
        currentNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter element %d : ", (i + 1));
        scanf("%d", &currentNode->data);

        if (i == 0)
        {
            head = temp = currentNode;
        }
        else
        {
            temp->next = currentNode;
            temp = currentNode;
        }
    }

    temp->next = NULL;
    temp = head;

    printf("\nThe elements are \n");
    traverse(temp);

    //   int index;
    //   printf ("\nEnter element at which position to delete : ");
    //   scanf ("%d", &index);

    int value;
    printf("\nEnter the value of which element to delete : ");
    scanf("%d", &value);

    //   printf ("\nThe elements after Deletion at position %d are\n",index);
    printf("\nThe elements after Deletion are\n");
    //  deleteAtBetween(temp,index);
    deleteWithGivenValue(temp, value);
    traverse(temp);

    return 0;
}
