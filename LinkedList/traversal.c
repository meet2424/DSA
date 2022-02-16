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

    return 0;
}
