#include <stdio.h>

#define N 100

int main()
{
    int i, n, a;
    char arr[N];

    //for (i = 0; i < N; i++) arr[i]=0;

    //setlocale(0, "");

    //printf("¬ведите размер массива\n");
    scanf("%d", &n);

    fflush(stdin);

    //printf("¬ведите элементы\n");
    for (i = 0; i < n; i++)
    {
        scanf("%c", &arr[i]);
    }

    //printf("\nЁлементы после сортировки \n");
    for (i = 0; i < n; i+=5)
        if (i+4 < n)
        {
            a = i+4;
            for (; a >= i; a--)
            {
                printf("%c", arr[a]);
            }
        }
        else
        {
            a = i;
            for (--n; n >= a; n--)
            {
                printf("%c", arr[n]);
            }
        }

    return 0;
}
