//
// Created by emine on 20.05.2022.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void UpdateTimeSeed(void);
void shuffleDeck(int deck[][13]);
void dealDeck(int deck[][13], const char *suit[], const char *face[]);
int givePokerHand(int deck[][13]);
void showHand(int pokerHandOfPlayer[5], const char *suit[], const char *face[]);

int NumberOfCards = 52;

void main(void){

    const char *suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *face[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                           "Ten", "Jack", "Queen", "King" };

    int deck[4][13] = {0};
    int pokerHandOfPlayerOne[5] ={0};

    UpdateTimeSeed();
    shuffleDeck(deck);
    dealDeck(deck, suit, face);

    *pokerHandOfPlayerOne = givePokerHand(deck);
    showHand(pokerHandOfPlayerOne, suit, face);

}


void UpdateTimeSeed(void){
    srand(time(NULL));
    return;
}

void shuffleDeck(int deck[][13]){
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

void dealDeck(int deck[][13], const char *suit[], const char *face[]){
    int card;
    int row, cardRow;
    int column, cardColumn;

        for (row = 1; row<= 4; row++){
            for (column =1 ; column <= 13; column++){
            card = deck[row][column];
            cardRow = card/13;
            cardColumn = card%13;
            printf("%5s of %-8s \n", face[cardColumn], suit[cardRow]);
            }
        }
}

int givePokerHand(int deck[][13]){

    int i;
    int PokerHand[5] ;
    int row, column;

    for (i = 1; i<=5; i++) {
        row = NumberOfCards /13;
        column = NumberOfCards % 13;
        PokerHand[i] = deck[row][column];
        NumberOfCards = NumberOfCards -1;
    }

    return *PokerHand;
}

void showHand(int pokerHandOfPlayer[5], const char *suit[], const char *face[]){
    int card;
    int row, cardRow;
    int cardColumn;
    printf("\nHere is hand of Player 1\n");

    for (row = 1; row<= 5; row++){
            card = pokerHandOfPlayer[row];
            cardRow = card/13;
            cardColumn = card%4;
            printf("%5s of %-8s \n", face[cardColumn], suit[cardRow]);
    }

}


