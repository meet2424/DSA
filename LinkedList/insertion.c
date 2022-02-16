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

// struct Node * insertAtFirst (struct Node *head, int data)
// {

//   struct Node *ptr = (struct Node *) malloc (sizeof (struct Node));

//   ptr->data = data;
//   ptr->next = head;

//   return ptr;

// }

// void insert(struct Node *head, int index ,int data)
// {

//   struct Node *ptr = (struct Node *) malloc (sizeof (struct Node));
//   struct Node *p=head;
//   int i=0;
//   while(i!=index-2){
//     p=p->next;
//     i++;
//   }
//   ptr->data = data;
//   ptr->next = p->next;
//   p->next=ptr;

// }

// void insertAtEnd(struct Node *head ,int data)
// {

//   struct Node *ptr = (struct Node *) malloc (sizeof (struct Node));
//   struct Node *p=head;
//   while(p->next!=NULL){
//     p=p->next;
//   }
//   ptr->data = data;
//   ptr->next =NULL;
//   p->next=ptr;

// }

// void insertAfterNode(struct Node *preNode ,int data)
// {

//   struct Node *ptr = (struct Node *) malloc (sizeof (struct Node));

//   ptr->data = data;
//   ptr->next =preNode->next;
//   preNode->next=ptr;

// }

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

    //   int data;
    //   int index;
    //   printf ("\n\nEnter element to inert : ");
    //   scanf ("%d", &data);
    //   printf ("\nEnter element at which position to inert : ");
    //   scanf ("%d", &index);

    //   printf ("\nThe elements after Insertion \n");
    //   temp = insertAtFirst(temp,data);
    //   insert(temp,index,data);
    //   insertAtEnd(temp,data);

    //   traverse (temp);
    return 0;
}
