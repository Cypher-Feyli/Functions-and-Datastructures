/* ====================================
File name: exerc_2_1.c (or cpp)
Date: 2018-02-01
Group Number: 1
Members that contributed:
Sayf Rashid
Melinda Ivók
Mehrshad Hosseini
Demonstration code: 26473 Important , No code no bonus !
====================================== */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

//26473
int main(){
    char str[MAX], strC[MAX], strCl[MAX];
	printf("Write a word, max length 20 characters:   ");
    fgets(str, MAX, stdin);

    strcpy(strCl, str);
    printf("first we copy by using strcpy and the result is: %s \n",strCl);
    printf("then by using the self made method \n");
    //getchar();
    copyString(strC, str);
	printf("The original word is %sthe copied word is %s", str,strC);

    return 0;
}
void copyString(char *copy, char *original){

	//char* p;
	while (*original != '\0'){
		*copy++ = *original++;
	}
	*copy++ = '\0';
}
