/* ====================================
File name: exerc_2_4.c (or cpp)
Date: 2018-02-01
Group Number: 1
Members that contributed:
Sayf Rashid
Melinda Ivók
Mehrshad Hosseini
Demonstration code: 27688 Important , No code no bonus !
====================================== */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
//27688

int main(){
    char *text= malloc(MAX);
    printf("Enter a message: \n");
    fgets(text, 20, stdin);
    palindromChecker(strlen(text),text);
    free(text);
    return 0;
}

int palindromChecker(int theLength,char *theString){
    theLength = theLength -1;

    for(int i =0;i<theLength/2;i++){
        if(theString[i]!= theString[theLength-i -1]){
            printf("%-20s Not Palindrom\n", theString);
            return 1;

        }
    }
   printf("%-20s Palindrom\n", theString);
   return 0;
}