/* ====================================
File name: exerc_2_2.c (or cpp)
Date: 2018-02-01
Group Number: 1
Members that contributed:
Sayf Rashid
Melinda Ivók
Mehrshad Hosseini
Demonstration code: 21954 Important , No code no bonus !
====================================== */
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
//21954

int main(){
     int *array[MAX];
     int a;
     for(int i =0; i<MAX;i++){
        a = ((i+1)*rand()) % 99 ;
       // printf("Write a word, max length 20 characters: %d  \n",a);
        array[i] = a ;
     }

   printf("The value of the label array(adress) is: %p \n", &array);
   printf("The first value of the array is: %d\n", *array);
   printf("The size of an integer is: %d \n", sizeof(int));
   printf("The size of the array is: %d \n", sizeof(array));
   for(int i =0; i<MAX;i++){
        int doubling = (int)array[i] * 2;
         printf("the value of the integer is:  %d  \n",array[i]);
        printf("and the double %d\n",doubling);

   }
    //free(array);
    return 0;
}