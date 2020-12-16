#include <stdio.h>
#include <conio.h>

/*
����� ������ - 15

������� ��������� - A

*/
int i, n, arr[100], x, arr2[100], z, v, y, res;

int main()
{
    setlocale(0, "");

    
    printf("I find the sum of squares of the second array consisting of the first array, ");
    printf("provided that the index is even and the array element is positive");

    printf("\nEnter the size of the array1: ");
    res = scanf("%d", &n); // ������ ���������� ��������� � �������
    if (res == 0)
    {
        printf("Error, the array must not contain a symbol");
        return -1;
    }



    printf("\nFill the array with any numbers, but not the symbol: ");
    for (i = 0; i < n; ++i) // ��������� ������
    {
        res = scanf("%d", &x);
        if (res == 1) //�������� �� ����� (���� �� �����, �� ����������)
            arr[i] = x;
        else
        {
            printf("Error, the array must not contain a symbol");
            return -1;
        }

    }

    printf("\nElements of the second array: ");
    z = -1;
    for (i = 0; i < n; ++i) // ��������� ������ ������ �� �������, ��� ������� ��� ������� ������ � ����� ������������
    {
        if ((i%2 == 0) && (arr[i] > 0))
        {
            arr2[z + 1] = arr[i];
            ++z;
            printf("%d ", arr2[z]);
        }

    }
    y = 0;
    ++z;
    for (i = 0; i < z; ++i) // �������� �� ������� ������� � ������� ����� ���������
    {
        v = arr2[i] * arr2[i];
        y = y + v;
    }

    printf("\nThe square of the sum of the second array is %d", y);

    getch();
    return 0;
}
