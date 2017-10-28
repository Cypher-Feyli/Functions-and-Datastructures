
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(void) {
    //Use system("clear") on linux ("cls") on windows
	system("cls");
	findWord("test.txt", "is");
	return(0);
	//char *word = "of";
}
/*This method looks for a specific word and prints out
 the position of the word or words if multiple occurences
 of the word exist in the file*/
void findWord(char *fname, char *str) {
    FILE *fp;
    int find_result = 0;
    char temp[500];
    int sum =0;
    int prevPos;
    int count;
    int position;


    if((fp = fopen(fname, "r")) == NULL) {
            printf("ERROR!!!!!!!!!!");
            exit(1);
    }else{
        // while going through every line of the file and storing it in temp
        while(fgets(temp, 501, fp) != NULL) {
			int lineSize = strlen(temp);
			char *tmp = temp;
			// check if the line has the string
			if((strstr(temp, str)) != NULL) {
				count = 0;
				char *word;
				char *ptr = tmp;

				//check if the string is the word by checking word by word
				while ((word = strtok(ptr, " ,.\t\n"))) {
				   if(strcmp(word,str)==0){
						count++;
					   // printf("found");
						// position is where the word is found in the line
						position = word - temp;
						if(count > 1){
							sum += position-prevPos;
						}else{
						   sum += position;
						}

					printf("\n %d byte %d \n",position, sum);
					prevPos = position;

					}
				ptr = NULL;
				}
			count = 0;
			find_result++; 
			}

		sum += lineSize - position;
		position = 0; 
		}

        if(find_result == 0) {
                printf("\nSorry, couldn't find a match.\n");
        }
          //Close the file if still open.
        if(fp) {
                fclose(fp);
        }
   	}
}

