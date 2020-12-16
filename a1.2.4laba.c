#include <stdio.h>

#define N 100

int main()
{
    int i, n, a;
    char arr[N];

    printf("Size text\n");
    scanf("%d", &n);

    fflush(stdin);

    printf("Input text\n");
    for (i = 0; i < n; i++)
    {
        scanf("%c", &arr[i]);
    }

    printf("Sort text\n");
    for (i = 0; i < n; i+=5)
        if (i+4 < n)
        {
            a = i+4;
            for (; a >= i; a--)
            {
                printf("%c", arr[a]);
            }
            printf(" ");
        }
        else
        {
            a = i;
            for (--n; n >= a; n--)
            {
                printf("%c", arr[n]);
            }
            printf(" ");
        }

    return 0;
}
/*
*   Size text
*   17
*   Input text
*   ABCDEFGHIJKLNMOPQ
*   Sort text
*   EDCBA JIHGF OMNLK QP
*/