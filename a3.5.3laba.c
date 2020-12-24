#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


typedef struct sNode {
	struct sNode* next;
	char ch[21];
} tNode;


tNode* create_list()
{
	int len = 0;
	tNode* p_begin = NULL;
	tNode* p = NULL;
	p_begin = (tNode*)malloc(sizeof(tNode));
	p = p_begin;
	p->next = NULL;
	len++;
	scanf("%s", p->ch);
	if (strlen(p->ch) > 20)
	{
		printf("Error word");
		return 0;
	}
	while (p->ch[strlen(p->ch) - 1] != '.' && p->ch[strlen(p->ch) - 1] != '?' && p->ch[strlen(p->ch) - 1] != '!')
	{
		len++;
		if (len > 30)
		{
			printf("Error sentence");
			return 0;
		}
		p->next = (tNode*)malloc(sizeof(tNode));
		p = p->next;
		p->next = NULL;
		scanf("%s", p->ch);
		if (strlen(p->ch) > 20)
		{
			printf("Error word");
			return 0;
		}
		for (int i = 0; i < strlen(p->ch); i++)
		{
			if (!isalpha(p->ch[i]) && p->ch[i] != '.' && p->ch[i] != '?' && p->ch[i] != '!')
			{
				printf("Error symbol");
				return 0;
			}
		}
	}
	return p_begin;
}


tNode* modified_list(tNode* p_begin)
{
	char ch2[1000];
	int count = 0;
	tNode* p = p_begin;
	scanf("%s", ch2);
    for (int i = 0; i < strlen(ch2); i++)
		{
			if (!isalpha(ch2[i]))
			{
				printf("Error symbol");
				return 0;
			}
		}
    int flag = 0;
	while (p != NULL)
	{
		count++;
		if (strcmp (p->ch, ch2)==0)
        {
            flag = 1;
            printf("%d", count);
            break;
        }
        p=p->next;
    }
    count = 0;
    if(flag == 0) printf("%d", count);
}

void delete_list(tNode* p_begin)
{
	tNode* p = p_begin;
	while (p != NULL) {
		tNode* tmp;
		tmp = p;
		//шаг
		p = p->next;
		//удалить память ячейки
		free(tmp);
	}
}

int main()
{
	char ch[1000], ch2[1000];
	int len;
	ch[0] = '\0';
	tNode* p_begin = create_list();
	if (p_begin == 0)
    {
        delete_list(p_begin);
        return 0;
    } 
        
	modified_list(p_begin);
	delete_list(p_begin);
	return 0;
}