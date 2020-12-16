/*
*
*   номер задачи - 9
*   уровень сложности - А
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct sNode{
    struct sNode *next;
    int value;
} tNode;

tNode *create_list(int N)
{
    tNode *p_begin = NULL;
    tNode *p = NULL;
    //заполним односвязный список
    p_begin = (tNode *)malloc(sizeof(tNode));
    p = p_begin;
    p->next = NULL;
    printf("input numbers in list\n");
    int s;
    scanf("%d", &s);
    p->value = s;
    for(int k = 1; k < N; k++) {   
        p->next = (tNode *)malloc(sizeof(tNode));
        //шаг
        p = p->next;
        //заполнить новую структуру данных
        p->next = NULL;//тут происходит краш ругается студия2019 C6011
        int i;
        scanf("%d", &i);
        p->value = i;
    }
    return p_begin;
}


void delete_list(tNode *p_begin)
{
    tNode *p = p_begin;
    while (p != NULL) {
        tNode *tmp;
        tmp = p;
        //шаг
        p = p->next;
        //удалить память ячейки
        free(tmp);
    }
}

tNode *create_list2(int N, int arr[])
{
    int i = 1;
    tNode *p_begin = NULL;
    tNode *p = NULL;
    //заполним односвязный список
    p_begin = (tNode *)malloc(sizeof(tNode));
    p = p_begin;
    p->next = NULL;
    p->value = arr[0];
    for(int k = 1; k < N; k++) {   
        p->next = (tNode *)malloc(sizeof(tNode));
        //шаг
        p = p->next;
        //заполнить новую структуру данных
        p->next = NULL;//тут происходит краш ругается студия2019 C6011
        p->value = arr[i];
        i++;
    }

    return p_begin;
}
void delete_list2(tNode *p_begin)
{
    tNode *p = p_begin;
    while (p != NULL) {
        tNode *tmp;
        tmp = p;
        //шаг
        p = p->next;
        //удалить память ячейки
        free(tmp);
    }
}

int main()
{
    int n, sum, arr[1000], z;
    z = 0;
    printf("Input size list\n");
    scanf("%d",&n);

    tNode *p_begin = create_list(n);
    tNode *p = p_begin;
    sum = 0;
    while (p != NULL)
    {
         //printf("%d \t", p->value);
        sum += p->value;
        arr[z] = sum;
        z++;
        //шаг
        p = p->next;
    }
    
    
    
    tNode *p_begin2 = create_list2(n, arr);
    tNode *p2 = p_begin2;
    printf("Second list: \n");
    while (p2 != NULL) {
        printf("%d\t", p2->value);
        //шаг
        p2 = p2->next;
    }
    delete_list(p_begin);
    delete_list2(p_begin);
    printf("\nList printed!\n");
    return 0;
}