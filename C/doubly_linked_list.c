#include<stdio.h>
#include<stdlib.h>

typedef struct Node  {
	int data;
	struct Node* next;
	struct Node* prev;
}nodex;


nodex* createList(int x){
    nodex * head = malloc(sizeof(nodex));
    head->data = x;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

void addToFirst(nodex **list,int x){

    nodex * head = malloc(sizeof(nodex));
    head->data = x;
    head->next = *list;
    head->prev = NULL;
    (*list)->prev = head;
    *list = head;
}

void addToLast(nodex **list, int val) {
    nodex *newNode = malloc(sizeof(nodex));
    nodex *current = *list;
    newNode->data = val;
    newNode->next = NULL;
    if(*list ==  NULL){
        newNode->prev = NULL;
        *list = newNode;
    }else{
        while(current->next != NULL){
            current= current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void removeByIndex(nodex **list,int index){
    nodex * current = *list;
    //temp_node the Node that we're going to free after we have removed it
    nodex * temp_node = NULL;
     if (index == 0) {
         pop(list);
    }else{
         for(int i =0;i<index-1;i++){
             if(current->next == NULL){
                 break;
             }else{
                  current = current->next;
             }
         }
         temp_node = current->next;

     //We re-link the nodes
         current->next = temp_node->next;
         temp_node->next->prev = temp_node->prev;
         printf("%p",temp_node);
         free(temp_node);
    }
}


void printList(nodex * head) {
    nodex * current = head;
    printf("\n");

    while (current != NULL) {

        printf("%d ", current->data);
        current = current->next;

    }
    printf("\n");

}

int pop(nodex ** head) {
    nodex * next_node = NULL;

    if (*head == NULL) {
        printf("The list is empty");
        return 0;
    }else{
        next_node = (*head)->next;
        free(*head);
        *head = next_node;
        return 1;
    }
}




int main() {
    //We create the linked list with the variable linked_list
    nodex * linked_list=createList(7);
    addToFirst(&linked_list,9);
    addToFirst(&linked_list,3);

    addToLast(&linked_list,6);
    printList(linked_list);
    removeByIndex(&linked_list,1);
    printf("\n");
    printList(linked_list);
    printf("\n");
    printList(linked_list);
    pop(&linked_list);
    printList(linked_list);
    pop(&linked_list);
    pop(&linked_list);
    pop(&linked_list);
    pop(&linked_list);
    pop(&linked_list);
}
