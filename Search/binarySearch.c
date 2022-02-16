#include <stdio.h>

#include <conio.h>

#include <stdlib.h>

void main()
{

    int *ptr, n, i, lb, ub, mid, m = 0, x;

    printf("Enter the number of elements\n");

    scanf("%d", &n);

    printf("\nEnter the elements\n");

    ptr = (int *)malloc(n * sizeof(int));

    for (i = 0; i < 5; i++)
    {

        scanf("%d", &ptr[i]);
    }

    printf("\nEnter the element to find\n");

    scanf("%d", &x);

    lb = 0;

    ub = 4;

    while (lb <= ub)
    {

        mid = (lb + ub) / 2;

        if (ptr[mid] == x)
        {

            printf("\nElement found at position %d\n", mid + 1);

            m = 1;

            break;
        }

        else if (ptr[mid] > x)
        {

            ub = mid - 1;
        }

        else
        {

            lb = mid + 1;
        }
    }

    if (m == 0)
    {

        printf("\nThe Element is not found");
    }
}