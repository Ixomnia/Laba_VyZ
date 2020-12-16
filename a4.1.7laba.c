#include <stdio.h>
#include <stdlib.h>

typedef struct sNode{
    struct sNode *next;
    int value;
} tNode;

tNode *create_list(){
    int z;
    int t = 1;
    tNode *p_begin = NULL;
    tNode *p = NULL;
    p_begin = (tNode *)malloc(sizeof(tNode));
    if(p_begin == NULL){
        printf("Error: can't allocate memory");
        return -1;
    }
    p = p_begin;
    scanf("%d", &z);
    p->next = NULL;
    p->value = z;
    while(t == 1){
        int k = scanf("%d", &z);
        if (k == 0) break;
        p->next = (tNode *)malloc(sizeof(tNode));
        p = p->next;
        p->next = NULL;
        p->value = z;
    }
    return p_begin;
}


void delete_list(tNode *p_begin)
{
    tNode *p = p_begin;
    while (p != NULL) {
        tNode *tmp;
        tmp = p;
        p = p->next;
        free(tmp);
    }
}


int main()
{
    tNode *p_begin = create_list();
    tNode *p = p_begin;
    tNode *last;
    tNode *past;
    tNode *tmp;
    p = p_begin;
    past = p;
    if(p->value%2 == 0 && p->next == NULL){
        delete_list(p_begin);
        printf("List is empty");
        return 0;
    }
    //последний четный
    while (p != NULL)
    {
        if (p->value%2 == 0) last = p;
        p = p->next;
    }
    p = p_begin;
    while (p != NULL)
    {
        if (p->next == last)
        {
            tmp = p->next;
            p->next = p->next->next;
            free(tmp);
            break;
        }
        p = p->next;
    }
    //первый четный
    p = p_begin;
    past = p;
    while (p != NULL)
    {
        if (p_begin->value%2 == 0){
            tmp = p_begin;
            p_begin = p_begin->next;
            p = p->next;
            free(tmp);
            break;
        }
        if (p->value%2 == 0)
        {
            tmp = p;
            past->next = p->next;
            p = p->next;
            free(tmp);
            break;
        }
        else
        {  
            past = p;
            p = p->next;
        }
    }

//печать 
    p = p_begin;
    if (p == NULL) printf("List is empty");
    while (p != NULL)
    {
        printf("%d ", p->value);
        p = p->next;
    }
    delete_list(p_begin);
    return 0;
}