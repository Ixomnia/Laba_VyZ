#include <stdio.h>
#include <conio.h>
/*
Номер задания - 1e
Уроввень сложности - A
*/
int main()
{
	int arr[100][100], n, n2, i, j, x, y, z, max, min, indx1, indx2;
	int cj[100], ci[100];
	int test;


	printf("\n Enter the size of the array (number of rows and columns): ");
	test = scanf_s("%d%d", &n, &n2);

	if ((n < 0) || (n2 < 0))
	{
		printf("Error,only positive");

		return -2;
	}
	if (test < 2)
	{
		printf(" \nError, can not be a symbol\n");
		return -1;
	}



	for (i = 0; i < n; i++) ci[i] = 0;
	for (i = 0; i < n2; i++) cj[i] = 0;


	printf("\n Enter numbers - ");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n2; j++)
		{
			test = scanf_s("%d", &x);
			arr[i][j] = x;
		}
	}

	if (test == 0)
	{
		printf(" \nError, can not be a symbol\n");
		return -1;
	}


	printf("\n Your arrey looks like this\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n2; j++)
		{
			printf(" [%d][%d]=%d ", i, j, arr[i][j]);
			ci[i] += arr[i][j];
			cj[j] += arr[i][j];

		}
		printf("  |%d", ci[i]);
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < n2; i++)
	{
		printf("     %d   ", cj[i]);

	}


	printf("\n\n");


	max = ci[0];
	for (i = 0; i < n; i++)
	{
		
		if (ci[i] >= max)
			max = ci[i];
	}
	min = cj[0];
	for (i = 0; i < n2; i++)
	{
		
		if (cj[i] <= min)
			min = cj[i];
	}


	printf(" min column = %d\n max line = %d\n\n", min, max);
	for (i = 0; i < n; i++)
	{
		if (ci[i] == max)
		{
			indx1 = i;
			break;
		}
	}

	for (i = 0; i < n2; i++)
	{
		if (cj[i] == min)
		{
			indx2 = i;
			break;
		}
	}

	printf("\n Item on the line with the highest amount and the column with the minimum amount = ");
	printf("'[%d][%d] = %d'\n", indx1, indx2, arr[indx1][indx2]);

	system("pause");
	return 0;
}
