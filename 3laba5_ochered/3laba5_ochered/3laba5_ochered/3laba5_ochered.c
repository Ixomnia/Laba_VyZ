#include <stdio.h>
#include "functions.h"
//3 1 5 2 1 4 2 -> 3 2 4 2
typedef struct sNode {
	struct sNode* next;
	int value;
} tNode;

tNode* create_list(int siz)
{
	tNode* p_begin = NULL;
	tNode* p = NULL;
	p_begin = (tNode*)malloc(sizeof(tNode));
	p = p_begin;
	p->next = NULL;
	p->value = 0;
	for (int i = 1; i < siz; i++)
	{
		p->next = (tNode*)malloc(sizeof(tNode));
		p = p->next;
		p->next = NULL;
		p->value = 0;
	}
	return p_begin;
}

void delete_list(tNode* p_begin)
{
	tNode* p = p_begin;
	while (p != NULL) {
		tNode* tmp;
		tmp = p;
		p = p->next;
		free(tmp);
	}
}

int main()
{
	int siz, dij, end = -1, end1 = -1, true = 1, flag = 0, *ochered, tmp[100], tmp1, min, max;
	printf("Input size: ");
	int x = scanf("%d", &siz);
	if (siz < 0 || x == 0)
	{
		printf("Error");
		return 0;
	}
	tNode *p_begin = create_list(siz);
	tNode *p = p_begin;
	for (int i = 0; i < siz; i++)
	{
		int x = scanf("%d", &dij);
		if (x == 0)
		{
			printf("Error");
			return 0;
		}
		end++;
		if (flag == 0) {
			min = dij;
			max = dij;
			flag = 1;
		}
		push(dij, p);
		p = p->next;
	}
	p = p_begin;
	for (int i = 0; i < siz; i++)
	{
		tmp[i]=pop(p);
		if (tmp[i] < min)
		{
			min = tmp[i];
		}
		if (tmp[i] > max)
		{
			max = tmp[i];
		}
		p = p->next;
	}
	
	p = p_begin;
	for (int i = 0; i < siz; i++)
	{
		if (tmp[i] == min || tmp[i] == max) {

		}
		else
		{
			tmp1 = tmp[i];
			end1++;
			push(tmp1, p);
			p = p->next;
		}
	}

	p = p_begin;
	for (int i = 0; i < siz; i++)
	{
		printf("%d ", tmp[i]);
	}
	printf("-> ");
	for (int i = 0; i < end1+1; i++)
	{
		printf("%d ", p->value);
		p = p->next;
	}
	delete_list(p_begin);
	return 0;
}