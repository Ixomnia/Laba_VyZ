#include "functions.h"
#include <stdio.h>
typedef struct sNode {
	struct sNode* next;
	int value;
} tNode;
int push(int dij, tNode *p)
{	
	p->value = dij;
	return 0;
}
int pop(tNode* p)
{
	int tmp;
	tmp = p->value;
	return tmp;
}