/* ====================================
File name: exerc_3_4.c (or cpp)
Date: 2018-02-09
Group Number: 1
Members that contributed:
Sayf Rashid
Melinda Ivók
Demonstration code: 38304 Important , No code no bonus !
====================================== */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define FILENAME "db.bin"
// -----Typedefs -------
typedef struct {
    char firstname[20];
    char famnamne[20];
    char pers_number[13]; // yyyymmddnnnc
}PERSON;
// Function declaration (to be extend)
PERSON input_record( void); // Reads in a person record.
void write_new_file( PERSON *inrecord); //Creats a file and write a first record
void printfile(void); // print out all persons in the file
void search_by_firstname( char *name);// print out person if in list
void append_file(PERSON *inrecord);// appends a new person to the file

PERSON input_record()	{
	PERSON *pers =  malloc(sizeof(PERSON));
    char firstName[20];
    char famName[20];
    char pN[13];
    printf("Enter your first name\n");
    scanf("%s",firstName);
    strcpy(pers->firstname,firstName);
    printf("Enter your family name\n");
    scanf("%s",famName);
    strcpy(pers->famnamne,famName);
    printf("Enter your personalnumber\n");
    scanf("%s",pN);
    strcpy(pers->pers_number,pN);
    append_file(pers);
    return *pers;
}

void write_new_file(PERSON* inrecord)	{
    FILE* fileptr;
    if((fileptr=fopen(FILENAME,"wb"))==NULL) {
        printf("\n Can not create the file");
        exit(1);
    }
    strcpy(inrecord->firstname,"markus");
    strcpy(inrecord->famnamne,"rosenberg");
    strcpy(inrecord->pers_number,"9912011213");
    //inrecord->firstname= "ad";
   // inrecord->famnamne = "r";
   // inrecord->pers_number="34";
	fwrite(inrecord, sizeof(PERSON), 1, fileptr);
	fclose(fileptr);
}

void printfile(void){
    FILE *fileptr;
    PERSON *person = malloc(sizeof(PERSON));

    if((fileptr=fopen(FILENAME,"rb"))==NULL) {
     printf("\n Can not open file");
     exit(1);
   }
   // --------   Reads all file  --------
   while(fread(person, sizeof(PERSON), 1, fileptr)){
        if (!strcmp("Debug", person->famnamne)== 0) {
            printf("Firstname: %s\n",person->firstname);
            printf("Fam Name:  %s \n",person->famnamne);
            printf("personal number:  %s\n",person->pers_number);
        }
    }
   free(person);
   fclose(fileptr);
}
// search by lastname
void search_by_firstname( char *name){
    FILE *fileptr;
    PERSON *findName = malloc(sizeof(PERSON));

    if((fileptr=fopen(FILENAME,"rb"))==NULL) {
        printf("\n Can not open file");
        exit(1);
    }
    while(fread(findName, sizeof(PERSON), 1, fileptr)){

        if (strcmp(name, findName->firstname)== 0) {
            printf("Firstname: %s\n",findName->firstname);
            printf("Fam Name:  %s \n", findName->famnamne);
            printf("personal number:  %s\n",findName->pers_number);
        }
    }
    free(findName);
    fclose(fileptr);
}
void search_by_lastname( char *name){
    FILE *fileptr;
    PERSON *findName = malloc(sizeof(PERSON));

    if((fileptr=fopen(FILENAME,"rb"))==NULL) {
        printf("\n Can not open file");
        exit(1);
    }
    while(fread(findName, sizeof(PERSON), 1, fileptr)){

        if (strcmp(name, findName->famnamne)== 0) {
            printf("Firstname: %s\n",findName->firstname);
            printf("Fam Name:  %s \n", findName->famnamne);
            printf("personal number:  %s\n",findName->pers_number);
        }
    }
    free(findName);
    fclose(fileptr);
}

void append_file(PERSON *inrecord) {
	FILE* fileptr;
	if ((fileptr = fopen(FILENAME, "ab")) == NULL) {
		printf("Can not append to file");
		exit(1);
	}
    fwrite(inrecord, sizeof(PERSON), 1, fileptr);
    fclose(fileptr);
}

int main( void){
    PERSON *ppost =malloc(sizeof(PERSON));;
    int choice = 0;
    char *pe;
    char choice2=1;
    while (choice != 5) {
            printf("enter 1 if you want to create a new or delete the old file\n");
            printf("enter 2 if you want to Add a new person to the file\n");
            printf("enter 3 Search for a person in the file\n");
            printf("enter 4 Print out all in the file\n");
            printf("enter 5 to exit\n");
            scanf("%d", &choice);

            if(choice == 1){
                write_new_file(ppost);
            }else if(choice == 2){
               input_record();
            }else if(choice == 3){
                printf("if search by firstname enter 1, else lastname \n");
                scanf("%d", &choice2);
                if(choice2 ==1){
                        printf("enter the firstname:  ");
                        scanf("%s",&pe);
                        search_by_firstname(&pe);

                }else{
                        printf("enter the lastname:  ");
                        scanf("%s",&pe);
                        search_by_lastname(&pe);
                }


            }else if(choice == 4){
                printfile();
            }
    }
    free(ppost);
    return(0);
}

