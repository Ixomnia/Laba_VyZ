#include <stdio.h>
#define N 20
#define M 20

/*

3 7
2 2 3 4 5 6 7
7 6 5 4 3 2 1
11 2 3 4 5 6 7

*/
int main()
{
	int arr[N][M],n,m,x,del;
	int a = scanf("%d", &n);
	if(a==0 || n < 1 || n > 20){
		printf("Error");
		return 0;
	}
	a = scanf("%d", &m);
	if(a==0 || m < 1 || m>20){
		printf("Error");
		return 0;
	} 
		

	/*for (int i = 0; i < N; i++)//
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = 0;
		}
	}//*/

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &x);
			arr[i][j] = x;
		}
	}
	
	int flag = 0;
	for(int i=m-1; -1<i; i--)
	{
		for(int j=0; j<n-1; j++)
		{
			if(arr[j][i] < arr[j+1][i])
			{	
				if(arr[j][i] > 1)
				{
					flag = 1;
				}
				else {
					flag = 0;
					break;
				}
			}
			else{
				flag = 0;
				break;
			} 

			//printf("%d ", arr[j][i]);
		}
		if(flag == 1)
		{
			del = i;
			break;
		}
		//printf("\n");
	}
	if(m != 1 && n != 1)
	{
		if(flag == 0) printf("not found\n");
	}
 	
	printf("A:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("B:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(n == 1 && m==1) continue;
			if(flag==1){
				if(j == del) continue;
			}
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}