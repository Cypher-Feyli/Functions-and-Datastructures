/* ====================================
File name: exerc_3_1.c (or cpp)
Date: 2018-02-09
Group Number: 1
Members that contributed:
Sayf Rashid
Melinda Ivók
Demonstration code: 31048 Important , No code no bonus !
====================================== */
#include <stdio.h>
#include <stdlib.h>
// boundrary, char array
// 
enum DIRECTION {N,O,S,W};

typedef struct {
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

void move(ROBOT* robot) {
    if(robot->dir == N){
            if(robot->ypos <99){
                robot->ypos++;
            }else{
                printf("the robot can't move north\n");
            }
    }else if(robot->dir == O){
        if(robot->xpos <99){
            robot->xpos++;
        }else{
            printf("the robot can't move east\n");
        }
    }else if(robot->dir == S){
        if(robot->ypos !=0){
            robot->ypos--;
        }else{
            printf("the robot can't move south\n");
        }
    }else if(robot->dir == W){
        if(robot->xpos !=0){
            robot->xpos--;
        }else{
            printf("the robot can't move east\n");
        }
}
}
void turn(ROBOT* robot) {
    if(robot->dir == N){
        robot->dir = O;
    }else if(robot->dir == O){
        robot->dir = S;
    }else if(robot->dir == S){
        robot->dir = W;
    }else if(robot->dir == W){
        robot->dir = N;
    }
}

int main(){
    ROBOT* rob = malloc(sizeof(ROBOT));
    rob->dir =N;

   // int xPos,Ypos;
   int exit =2;

    //printf("enter 'm' for move in the current direction or 't' to turn");
    while (exit!=1){
            printf("starting x position of the robot:  ");
            char choice[200];
            rob->dir =N;
            scanf("%d",&rob->xpos );
            if(rob->xpos > 99 || rob->xpos <0){
                    printf("the value is ouside the range so the default value is set to 0");
              rob->xpos  =0;
            }

            printf("\nstarting y position of the robot:  ");
            scanf("%d",&rob->ypos);
            if(rob->ypos > 99 || rob->ypos <0){
                printf("the value is ouside the range so the default value is set to 0");
                rob->ypos  =0;
            }
            exit =2;
            while(exit == 2){
                printf("enter 'm' to move in the current direction or 't' to turn or 'q' to quit\n");
                //move(rob);
                scanf("%s",&choice);
               // printf("\nthis is the %s",choice);
                int i=0;
                while(exit ==2){
                       // printf("test");
                    if(choice[i]=='m'){
                        move(rob);
                    }else if (choice[i]=='t'){
                        turn(rob);
                    }else{
                        break;
                    }
                    i++;
                    //choice++;
                }
                printf(" the x pos is%d \nthe y pos is: %d\n",rob->xpos,rob->ypos);

                printf("to exit press '1' or press 2 to continue another number to restart");
                scanf("%d",&exit);
            }
    }


    free(rob);

    return 0;
}
