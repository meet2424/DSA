#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node *createNode()
{
    int data;
    printf("Enter node data : ");
    scanf("%d", &data);
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void preOrder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d ", ptr->data);
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}
void postOrder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        postOrder(ptr->left);
        postOrder(ptr->right);
        printf("%d ", ptr->data);
    }
}
void inOrder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        inOrder(ptr->left);
        printf("%d ", ptr->data);
        inOrder(ptr->right);
    }
}

void createTree(struct Node *pre)
{
    int child;
    struct Node *ptr;

    if (pre->left == NULL)
    {
        printf("Do u want left child for %d (1/0) : ", pre->data);
        scanf("%d", &child);
        if (child == 1)
        {
            ptr = createNode();
            pre->left = ptr;
            createTree(ptr);
        }
    }
    if (pre->right == NULL)
    {
        printf("Do u want right child for %d (1/0) : ", pre->data);
        scanf("%d", &child);
        if (child == 1)
        {
            ptr = createNode();
            pre->right = ptr;
            createTree(ptr);
        }
    }
}

int main()
{
    // struct Node *root = createNode(7);
    // struct Node *p1 = createNode(2);
    // struct Node *p2 = createNode(3);
    // struct Node *p3 = createNode(1);
    // struct Node *p4 = createNode(4);

    // root->left = p1;
    // root->right = p2;

    // p1->left = p3;

    // p2->right = p4;
    int choice;

    do
    {

        printf("\n1 --> Create Tree\n2 --> PreOrder Traversal\n3 --> PostOrder Traversal\n");
        printf("4 --> InOrder Traversal\n5 --> All Traversal\n6 --> Exit\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            root = createNode();
            createTree(root);
            break;
        case 2:
            if (root == NULL)
            {
                printf("\nCreate Tree First\n");
            }
            else
            {
                printf("PreOrder representation of Binary Tree is \n");
                preOrder(root);
                printf("\n");
                printf("\n");
            }
            break;
        case 3:
            if (root == NULL)
            {
                printf("\nCreate Tree First\n");
            }
            else
            {
                printf("PostOrder representation of Binary Tree is \n");
                postOrder(root);
                printf("\n");
                printf("\n");
            }
            break;
        case 4:
            if (root == NULL)
            {
                printf("\nCreate Tree First\n");
            }
            else
            {
                printf("InOrder representation of Binary Tree is \n");
                inOrder(root);
                printf("\n");
                printf("\n");
            }
            break;
        case 5:
            if (root == NULL)
            {
                printf("\nCreate Tree First\n");
            }
            else
            {
                printf("PreOrder representation of Binary Tree is \n");
                preOrder(root);
                printf("\n");
                printf("\n");
                printf("PostOrder representation of Binary Tree is \n");
                postOrder(root);
                printf("\n");
                printf("\n");
                printf("InOrder representation of Binary Tree is \n");
                inOrder(root);
                printf("\n");
                printf("\n");
            }
            break;
        case 6:
            printf("Exiting...");
            break;
        default:
            printf("\nInvalid Choice\n");
        }

    } while (choice != 6);

    return 0;
}