#include <stdio.h>

#define Max 30
int Top = -1;
int Too = -1;
char stack[Max];
char outputStack[Max];

int precedence(char opr)
{
    switch (opr)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    default:
        return -1;
    }
}

void push(char opr)
{
    if (Top != (Max - 1))
    {
        stack[++Top] = opr;
    }
}

void pushOutputStack(char operand)
{

    if (Too != (Max - 1))
    {
        outputStack[++Too] = operand;
    }
}

char pop()
{
    if (Top != -1)
    {
        return stack[Top--];
    }
    return 0;
}

void postfix(char a[])
{
    for (int i = 0; (a[i] != '\0'); i++)
    {
        char c;
        int pre;
        if (a[i] == '(')
        {
            push(a[i]);
        }
        else if (a[i] == ')')
        {
            c = pop();
            while (c != '(')
            {
                pushOutputStack(c);
                c = pop();
            }
        }
        else if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%')
        {
            pre = precedence(a[i]);
            if (pre > precedence(stack[Top]))
            {
                push(a[i]);
            }
            else
            {
                while (pre <= precedence(stack[Top]) && Top != -1)
                {
                    c = pop();
                    pushOutputStack(c);
                }
                push(a[i]);
            }
        }
        else
        {
            pushOutputStack(a[i]);
        }
    }
    while (Top != -1)
    {
        pushOutputStack(pop());
    }
}

int main()
{
    char a[Max];
    printf("\n");
    printf("Please enter a valid expression to convert to Postfix\n", Max);
    scanf("%s", a);
    postfix(a);
    printf("\nPostfix of given expression is : ");
    for (int i = 0; i <= Too; i++)
    {
        printf("%c", outputStack[i]);
    }
    printf("\n");
    return 0;
}

//=========================Algorithm=========================
// Step 1: Add)to the end of the infix expression
// Step 2: Push(on to the stack
// Step 3: Repeat until each character in the infix notation is scanned
// IF a(is encountered, push it on the stack
// IF an operand (whether a digit or a character) is encountered, add it
// postfix expression.
// IF a)is encountered, then
// a. Repeatedly pop from stack and add it to the postfix expression until a
// ( is encountered.
// b. Discard the ( . That is, remove the ( from stack and do not
// add it to the postfix expression
// IF an operator is encountered, then
// a. Repeatedly pop from stack and add each operator (popped from the stack) to the
// postfix expression which has the same precedence or a higher precedence than
// b. Push the operator to the stack
// [END OF IF]
// Step 4: Repeatedly pop from the stack and add it to the postfix expression until the stack is empty
// Step 5: EXIT