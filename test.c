#include <stdio.h>
 
int main () { 
    FILE *file;
    struct food {
        char name[20]; 
        unsigned qty; 
        float price; 
    };
    struct food shop[10];
    char i=0;
 
    file = fopen("test.txt", "r");
 
    while (fscanf(file, "%s%u%f", 
        shop[i].name, &(shop[i].qty), 
        &(shop[i].price)) != EOF) {
 
        printf("%s %u %.2f\n", shop[i].name, 
               shop[i].qty, shop[i].price); 
        i++;
    }
}