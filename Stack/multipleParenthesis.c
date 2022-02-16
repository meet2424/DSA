#include <stdio.h>

#define Max 30
int Top = -1;
char stack[Max];

int match(char x, char y)
{
    if (x == '(' && y == ')')
    {
        return 1;
    }
    else if (x == '{' && y == '}')
    {
        return 1;
    }
    else if (x == '[' && y == ']')
    {
        return 1;
    }

    return 0;
}

int push(char item)
{

    if (Top == (Max - 1))
    {
        return 0;
    }
    else
    {
        stack[++Top] = item;
        return 1;
    }
}

int pop(char item)
{
    if (Top == -1)
    {
        return 0;
    }
    else
    {
        if (match(stack[Top], item))
        {
            Top--;
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void check(char a[])
{
    int check = 1;
    for (int i = 0; (a[i] != '\0' && check != 0); i++)
    {
        if (a[i] == '(' || a[i] == '[' || a[i] == '{')
        {
            check = push(a[i]);
        }
        else if (a[i] == ')' || a[i] == ']' || a[i] == '}')
        {
            check = pop(a[i]);
        }
    }

    if (check != 1 || Top != -1)
    {
        printf("\nThe given expression is not balanced\n");
    }
    else
    {
        printf("\nThe given expression is perfectly balanced\n");
    }
}

int main()
{
    char a[Max];
    printf("Enter your expression\n");
    scanf("%s", a);
    check(a);

    return 0;
}
