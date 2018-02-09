/* ====================================
File name: exerc_3_2.c (or cpp)
Date: 2018-02-09
Group Number: 1
Members that contributed:
Sayf Rashid
Melinda Ivók
Demonstration code: 34855 Important , No code no bonus !
====================================== */
#include <stdio.h>
#include <stdlib.h>
//34855

int search_number( int number, int tab[], int size);
int test [] = { 2,2,1};
void sort (int number, int tab []);

int main()
{
   // printf("Hello world:   %d!\n",sizeof(test)/4);
    int sizeAr = sizeof(test)/4;
    search_number(2, test, sizeAr);
    sort(sizeAr,test);
    search_number(2, test, sizeAr);
    return 0;
}
void sort(int number, int tab []){
   int i, j, temp;
   for (i = 0; i < number-1; i++){

       for (j = 0; j < number-i-1; j++){
           if (tab[j] > tab[j+1]){
              temp= tab[j];
              tab[j] = tab[j+1];
              tab[j+1] = temp;
              }
       }
    }
}

int search_number(int number, int tab[], int size){
    for(int i =0;i<size;i++){
        if(tab[i] == number){
            printf("found:  %d\n",i);
            return i;
        }
    }
    printf("-1");
    return -1;
}
