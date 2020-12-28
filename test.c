#include <stdio.h>  // Для printf
#include <string.h> // Для strcmp
int main (void)
{ 
   int x=3, y=1, z=0;   
   z=(--x>y)?(x+y):(x-y);
   printf("%d", z);

   return 0;
}