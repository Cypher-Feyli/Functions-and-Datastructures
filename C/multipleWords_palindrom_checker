#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 256
char **orderedIds;
int palindromChecker(int theLength,char *theString){
    for(int i =0;i<theLength;i++){
        if(theString[i]!= theString[theLength-i -1]){
            printf("%-20s Not Palindrom\n", theString);
            return 1;

        }
    }
   printf("%-20s Palindrom\n", theString);
   return 0;
}
void findWords(char *buffer){
    char *word;
    char *ptr = buffer;

     // remove space, escape sequence
    while ((word = strtok(ptr, " ,.\t\n"))) {
        int len = strlen(word);
        palindromChecker(len,word);
        ptr = NULL;
    }


}

int main(void){
    int count = 0;
    int t = 0;
    char **buffer = malloc(BUFFER_SIZE);
    if (!buffer) {
        return -1;
    }
     printf("Enter a message: \n");

    while (count<10 && t != 1 ){

        buffer[count] = malloc((100) * sizeof(char));
        printf("Enter a word or sentence \nor just press enter to quit:   ");
        fgets(buffer[count], BUFFER_SIZE, stdin);
        if(strlen(buffer[count])==1){
            t = 1;
        }
        count++;
    }

    printf("resultat: \n");
    printf("------------------------------------ \n");
    for (int i = 0; i < count; i++){
        findWords(buffer[i]);
        free(buffer[i]);
     }

    free(buffer);

    return 0;
}
