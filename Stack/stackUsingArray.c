#include <stdio.h>

#define MaxSize 5
int top = -1;
int a[MaxSize];

void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("The status of the stack is \n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", a[i]);
        }
    }
    printf("\n");
}

void push()
{
    int num;
    if (top == (MaxSize - 1))
    {
        printf("Stack OverFlow\n");
    }
    else
    {
        printf("Enter the element to be pushed : ");
        scanf("%d", &num);
        top++;
        a[top] = num;
    }
    printf("\n");
    display();
}

int pop()
{
    int num;
    if (top == -1)
    {
        printf("Stack UnderFlow\n");
    }
    else
    {
        num = a[top];
        printf("Poped element is = %d\n", num);
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element of the stack is %d\n", a[top]);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n");
        printf("---------------STACK OPERATION-----------------\n");
        printf("1    -->    PUSH\n");
        printf("2    -->    POP\n");
        printf("3    -->    DISPLAY\n");
        printf("4    -->    PEEK\n");
        printf("5    -->    EXIT\n");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            break;
        default:
            printf("\nPlease select a valid choice\n");
        }

    } while (choice != 5);

    return 0;
}
