//
// Created by emine on 20.05.2022.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void UpdateTimeSeed(void);
void shuffleDeck(int deck[][13]);
void dealDeck(int deck[][13], const char *suit[], const char *face[]);

void main(void){

    const char *suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *face[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                           "Ten", "Jack", "Queen", "King" };

    int deck[4][13] = {0};

    UpdateTimeSeed();
    shuffleDeck();



}


void UpdateTimeSeed(void){
    srand(time(NULL));
    return;
}

void shuffleDeck(int deck[][]){
    int row;
    int column;
    int cardNumber;

    for(cardNumber =1; cardNumber <=52; cardNumber++){
        do{
            row = rand() % 4;
            column = rand() % 13;
        }while(deck[row][column] != 0);

        deck[row][column] = cardNumber;
    }
}


