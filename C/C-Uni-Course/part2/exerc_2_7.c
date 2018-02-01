/* ====================================
File name: exerc_2_7.c (or cpp)
Date: 2018-02-01
Group Number: 1
Members that contributed:
Sayf Rashid
Melinda Ivók
Mehrshad Hosseini
Demonstration code: 20142 Important , No code no bonus !
====================================== */
#include <stdio.h>
#include <stdlib.h>
//20142
int main()
{
    char pers[11];
    //char quit;
    while(pers[0] != 'q'){
        printf("enter q to quit or enter personalnumber:   ");

        readPersnr(&pers);
        if(*pers == 'q'){
        //    printf("break");
            break;

        }
        if(controlDay(&pers) == 1){
            controlDigit(&pers);
        }
    }

    return 0;
}

void readPersnr(char *person){
   // printf("enter your person number:    ");
    scanf("%s",person);
}

int controlDay( const char *persnr ){
    int i = 0,j = 1;
    while (i < 5){
                if(i>3){
                    int day = (persnr[i]- '0')*10 + (persnr[i+1]- '0');
                   // printf("wrong day input:  %d",day);
                    if(day> 31  || day <0 ){
                            printf("wrong day input:  %d",day);
                            return 0;
                    }
                }
                else if(i>1){
                   int month = (persnr[i]- '0')*10 + (persnr[i+1]- '0');
                   if(month> 12  || month <0 ){
                        printf("wrong month input:  %d",month);
                        return 0;
                   }

                }else{
                     int year = (persnr[i]- '0')*10 + (persnr[i+1]- '0');
                     if(year> 99  || year <0 ){
                        printf("wrong year input");
                        return 0;
                    }
                }
        i+=2;
    }
    printf("%d",j);
     return j;
}

int controlDigit( const char *persnr ){
    int i = 0,j,sum = 0;
    while (i != 9){
        j = persnr[i] - '0';
        if(i % 2 == 0){
            j=j*2;
            if(j>9){
               j = (j%10)+1;
            }
        }
        sum += j;
        i++;
    }
     sum = abs((sum% 10)-10);
     printf("the last is %d and yours is %d\n", sum % 10,(persnr[9] - '0'));
     return sum % 10;
}


