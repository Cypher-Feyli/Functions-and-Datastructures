/* ====================================
File name: exerc_2_6.c (or cpp)
Date: 2018-02-01
Group Number: 1
Members that contributed:
Sayf Rashid
Melinda Ivók
Mehrshad Hosseini
Demonstration code: 28874 Important , No code no bonus !
====================================== */
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
//28874

int main()
{
    int que [ MAX ] ;
    initQue(que,MAX);
    input(que, 7, MAX);
    output(que,MAX);
    input(que, 3, MAX);
    output(que,MAX);
    input(que, 7, MAX);
    printf("\n");
    remov(que,MAX);
    remov(que,MAX);
    output(que,MAX);
    input(que, 34, MAX);
    input(que, 72, MAX);
    input(que, 33, MAX);
    input(que, 27, MAX);
    input(que, 7, MAX);
    printf("\n");
    output(que,MAX);
    return 0;
}

void initQue(int list[], int max) {
	for (int i = 0; i < max; i++) {
		list[i] = -1;
	}
}

int input(int list[], int number, int max) {
	for (int i = 0; i < max;i++) {
		if (list[i] == -1) {
			list[i] = number;
			return 1;
		}
	}
	return 0;
}

int remov(int list[], int max){
    for(int i = 0;i<max-1;i++){
                list[i]=list[1+i];

    }

            list[max] = -1;


    return 0;
}

 int output( int list[], int max){
     for(int i = 0;i<max;i++){

        printf("%d \n",list[i]);
    }
    return 1;
 }
