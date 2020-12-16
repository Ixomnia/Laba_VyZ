/*
*
*   номер задачи - 3d
*   Шейкер-сортировки 
*   уровень сложности - А
*/
#define M 100
#define N 100
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>


int shekerSort(int arr[M][N],int m, int n) 
{
    int count=0;
    for(int j = 0; j<m; j++)
    {
        int left = 0, right = n - 1;
        int flag = 1;
        while ((left < right) && flag > 0)
        {
            flag = 0;
            for (int i = left; i<right; i++)  
            {
                if (arr[j][i]<arr[j][i + 1]) 
                {            
                    int t = arr[j][i];
                    arr[j][i] = arr[j][i + 1];
                    arr[j][i + 1] = t;
                    flag = 1;
                    count++;      
                }
            }
            right--; 
            for (int i = right; i>left; i--) 
            {
                if (arr[j][i - 1]<arr[j][i]) 
                {            
                    int t = arr[j][i];
                    arr[j][i] = arr[j][i - 1];
                    arr[j][i - 1] = t;
                    flag = 1;
                    count++;
                }
            }
            left++;
        }
    }
    return count;
}




int main()
{
    int arr[M][N], m, n, p[2];
    
    srand(time(NULL));
    printf("Input size array: ");
    scanf("%d%d", &m, &n);
    printf("Input numbers");
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            //arr[i][j] = rand();
            scanf("%d", &arr[i][j]);
        }
    }
   /*printf("Beginning array\n");
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            printf("%7d ", arr[i][j]);
        }
        printf("\n");
    }*/
    int count=shekerSort(arr, m, n);
    /*printf("Sorting strings\n");
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            printf("%7d ", arr[i][j]);
        }
        printf("\n");
    }*/
    int left = 0, right = m - 1, sravn=0, count2=0; 
    int flag = 1; 
    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i<right; i++)  
        {
            if (arr[i][0] < arr[i+1][0]) 
            {
                sravn++;
                
                for(int j = 0; j<n; j++)
                {
                    int t = arr[i][j];
                    arr[i][j] = arr[i+1][j];
                    arr[i+1][j] = t;
                    count2++;
                }                         
                flag = 1;
            }
        }
        right--; 
        for (int i = right; i>left; i--) 
        {
            if (arr[i-1][0]<arr[i][0]) 
            {   
                sravn++;
                
                for(int j = 0; j<n; j++)
                {
                    int t = arr[i][j];
                    arr[i][j] = arr[i-1][j];
                    arr[i-1][j] = t;
                    count2++;
                }
                flag = 1;
            }
        } 
        left++;
    }
   /*printf("Sorting columns\n");
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            printf("%7d ", arr[i][j]);
        }
        printf("\n");
    }*/
    printf("\nPermutations: %d\n",count2+count);
    printf("\nComparisons: %d\n",sravn+count);
    
    return 0;
}