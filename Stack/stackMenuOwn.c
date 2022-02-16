#include <stdio.h>

#define Max 5
int Top = -1;
int a[Max];

void display()
{
    if (Top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nThe status of the stack is \n");
        for (int i = Top; i >= 0; i--)
        {
            printf("%d\n", a[i]);
        }
    }
}

void push()
{
    int data;

    if (Top == (Max - 1))
    {
        printf("\nStack Overflow");
    }
    else
    {
        printf("\nEnter the data to push : ");
        scanf("%d", &data);
        a[++Top] = data;
        printf("Pushed element is = %d\n", data);
    }
}

void peek()
{
    if (Top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("\nTop element of the stack is %d\n", a[Top]);
    }
}

void pop()
{
    if (Top == -1)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        printf("Poped element is = %d\n", a[Top--]);
    }
}

void isEmpty()
{
    if (Top == -1)
    {
        printf("\nStack is Empty\n");
    }
}

void isFull()
{
    if (Top == Max - 1)
    {
        printf("\nStack is Full\n");
    }
}

int main()
{

    int choice;

    do
    {
        printf("\n\n------------Stack Operations---------------\n");
        printf("    1    -->    Display\n");
        printf("    2    -->    Push\n");
        printf("    3    -->    Pop\n");
        printf("    4    -->    Peek\n");
        printf("    5    -->    isEmpty\n");
        printf("    6    -->    isFull\n");
        printf("    7    -->    Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            push();
            break;
        case 3:
            pop();
            break;
        case 4:
            peek();
            break;
        case 5:
            isEmpty();
            break;
        case 6:
            isFull();
            break;
        case 7:
            break;
        default:
            printf("\nSelect form given options\n");
        }
    } while (choice != 7);

    return 0;
}
