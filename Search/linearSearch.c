#include <stdio.h>

#include <conio.h>

#include <stdlib.h>

void main()
{

    int i, n, *ptr, c, x = 0;

    printf("Enter the number of elements\n");

    scanf("%d", &n);

    printf("\nEnter the elements\n");

    ptr = (int *)malloc(n * sizeof(int));

    for (i = 0; i < 5; i++)
    {

        scanf("%d", &ptr[i]);
    }

    printf("\nEnter the element to find\n");

    scanf("%d", &c);

    for (i = 0; i < 5; i++)
    {

        if (ptr[i] == c)
        {

            printf("\nElement found at position %d\n", i + 1);

            x = 1;
        }
    }

    if (x == 0)
    {

        printf("\nThe Element is not found");
    }
}