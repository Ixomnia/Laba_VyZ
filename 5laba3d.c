/*
*
*   номер задачи - 3d
*   уровень сложности - А
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_lower(const char *str)
{
    if (*str == '.') return 0;

    return (islower(str) ? 1 : 0) + count_lower(str+1);
}

int main()
{
    int n;
    char str[1000];
    gets(str);
    n = count_lower(str);
    printf("%d", n);
    return 0;
}