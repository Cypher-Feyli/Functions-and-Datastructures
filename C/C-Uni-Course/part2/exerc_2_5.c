/* ====================================
File name: exerc_2_5.c (or cpp)
Date: 2018-02-01
Group Number: 1
Members that contributed:
Sayf Rashid
Melinda Ivók
Mehrshad Hosseini
Demonstration code: 26866 Important , No code no bonus !
====================================== */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define MAXNUMBER 20

// 26866

void create_random(int *tab);
void count_frequency(int *tab,int *freq);
void draw_histogram(int *freq);

int main(){
    //srand for new random number every run
    srand(time(NULL));
    int table[MAX], n;
    int frequency[MAXNUMBER];
    create_random(table);
    for(int i = 0;i<MAX;i++){
        printf("%d\n",table[i]);
    }
    count_frequency(table,frequency);
    draw_histogram(frequency);
    return 0;
}

// create the table in fill it with random numbers
void create_random(int *table) {

    for (int i = 0; i < MAX; i++) {
        *table = rand() % MAXNUMBER;
        *table++;
    }
}

void count_frequency(int *tab,int *freq){
    //int andAnotherOne = 1;
    for(int i = 0;i<MAXNUMBER;i++){
        *freq =0;
       for(int j = 0;j<MAX;j++){
            if(i==tab[j]){
                 *freq= *freq +1;
            }
       }
       *freq++;
    }
}

void draw_histogram(int *freq){
    for(int i = 0;i<MAXNUMBER;i++){
            if(freq[i]>0){
                printf("%d              ",i);
            }
        for(int j = 0;j<freq[i];j++){
            printf("x");
        }
    printf("\n");
    }

}
