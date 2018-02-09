/* ====================================
File name: exerc_3_3.c (or cpp)
Date: 2018-02-09
Group Number: 1
Members that contributed:
Sayf Rashid
Melinda Ivók
Demonstration code: 30369 Important , No code no bonus !
====================================== */
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//#### Konstanter #####
#define MAX 5
// 30369
// ##### Typedefs ####
typedef struct Node  {
	int number;
	struct Node* next;
	struct Node* prev;
}nodex;

nodex* createList(int x){
    nodex * head = malloc(sizeof(nodex));
    head->number = x;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

nodex* addToFirst(nodex **list,int x){

    nodex * head = malloc(sizeof(nodex));
    head->number = x;
    head->next = *list;
    head->prev = NULL;
    (*list)->prev = head;
    *list = head;
    return head;
}

nodex* random_list(void ){
    int nr;
    nr = rand() % (100);
    nodex *top = createList(nr);
    for( int i =0;i<MAX-1;i++){
        nr = rand() % (100);
       // printf("d\n");
        addToFirst(&top,nr);
    }

    return(top);
}


int main() {
    srand( time(0));
    int nr=0;



    //We create the linked list with the variable linked_list
    nodex * head=random_list();
    nodex* item = head;

   // printf("%d\n",head->number);
    addToFirst(&head,88);

    //addToFirst(&head,99);

    nodex * akt_post=head;

    while( akt_post!=NULL){
        printf("\n Post nr %d : %d" , nr++, akt_post->number);
        akt_post=akt_post->next;
    }
    printf("\nfirst element %d \n",item->prev->number);
    printf("\n%d",item->number);
    printf("\n%d",head->number);
    while((akt_post=head)!=NULL){
        head=akt_post->next;
        free(akt_post);
    }


}
