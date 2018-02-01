/* ====================================
File name: exerc_2_8.c (or cpp)
Date: 2018-02-01
Group Number: 1
Members that contributed:
Sayf Rashid
Melinda Ivók
Mehrshad Hosseini
Demonstration code:  26856 Important , No code no bonus !
====================================== */

/*
 *  File    : nim.c
 *  Program : Nim game
 *  Author  : ...
 26856
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>


#define MAX_COINS 13

const int HUMAN = 0;
const int COMPUTER = 1;

/* ------------- IO --------------- */

/*
 * human_choice
 * Get human choce as an int from stdin.
 * Clears stdin.
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int human_choice(int pile);

/*
 * write_winner
 * Write winner as a string on stdout.
 * in: Values HUMAN or COMPUTER.
 * out:
 */
void write_winner( int player );

/*
 * play_again
 * Ask human if he/she wants to play
 * another round. If 'n' or 'N' selected
 * (single char) return false else true.
 * Clears stdin.
 * in:
 * out: true or false
 */
int play_again();

/* ---------------- Logic ----------------*/

/*
 * computer_choice
 * Get computers choice (including some AI,
 * if 4 coins or less left, function makes a
 * smart choice else random).
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int computer_choice(int pile);

/*
 * toggle
 * Switches player, if HUMAN in COMPUTER out
 * etc.
 * in:  actual player
 * out: next player
 */
int toggle( int player );

/* --------------------- Utilities -------------*/
void clear_stdin();

/***************************************************
 *
 *    MAIN
 *
 ***************************************************/
int main()
{
    int playagain = 0;

    while (playagain ==0){
  int pile,			/* This is how many coins we have */
    player,			/* Who is playing? */
    n_coins;			/* Number of coins taken */

  srand( time(0) );		/* Setup random */

  printf("Välkommen till NIM by ...");



  pile = MAX_COINS;		/* Set start values (= init) */
  player = HUMAN;

  /*
   *  Program main loop
   */


  while( true ) {


    printf("Det ligger %d  mynt i högen\n", pile );

    if( player == HUMAN ){
      n_coins = human_choice(pile);
    }else{
      n_coins = computer_choice(pile);
      printf("- Jag tog %d\n", n_coins);
    }
    pile -= n_coins;
    player = toggle( player );

    if( pile <= 1 ){
      break;
    }

  }



  /*
   * end main loop
   */

  write_winner( player );
  if(play_again() == 1){
        playagain = 0;

  }else {
      playagain = 1;
  }
   }


  printf("Avslutat\n");

  return 0;
}

/******************************************************
 *
 *  DEFINITIONS
 *
 ******************************************************/


void clear_stdin()
{
  while( getchar() != '\n' ){
    ;
  }
}

int human_choice(int pile){
    int choice;
    printf("enter a number between 1 to 3\n");
    scanf("%d", &choice);
    clear_stdin();
    if (choice > 0 && choice < 4 && choice <= pile){
        return choice;
    }
    printf("Wrong number, enter a number between 1 to 3");
    return 0;
}

int computer_choice(int pile){
    if (pile > 4) {
            if(pile == 3){
                return 2;
            }else if(pile ==2){
                return 1;
            }
            return 1 + rand() % 3;
    }
    else {
            return pile - 1;
    }

}

void write_winner(int player){
    if (player == 0){
	printf("Computer wins\n");
    }else {
	printf("You won!\n");
    }
}

int play_again(){
    char c;
    printf("Do you want to play again?");
    scanf("%c", &c);
    clear_stdin();
    if (c == 'n'){
         return 0;
    }
    return 1;

}

int toggle( int player)
{if ( player == 0){
	return 1;
}return 0;

}
