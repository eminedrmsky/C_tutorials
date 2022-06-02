//
// Created by emine on 20.05.2022.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void UpdateTimeSeed(void);
void shuffleDeck(int deck[][13]);
void dealDeck(int deck[][13], const char *suit[], const char *face[]);
void givePokerHand(int deck[][13], int pokerHandOfPlayer[5]);
void showHand(int pokerHandOfPlayer[5], const char *suit[], const char *face[]);

//Hand valuation

void isTherePair(int pokerHandOfPlayer[5]);
void isThereKinds(int pokerHandOfPlayer[5]);
void isThereFlush(int pokerHandOfPlayer[5]);
void isThereStraight(int pokerHandOfPlayer[5]);

int NumberOfCards = 51;

void main(void){

    void (*evaluationFunctions[4])(int ) = {isTherePair, isThereKinds, isThereFlush, isThereStraight};

    const char *suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *face[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                           "Ten", "Jack", "Queen", "King" };

    int deck[4][13] = {0};
    int pokerHandOfPlayerOne[5] ={0};
    int functionCounter ;


    UpdateTimeSeed();
    shuffleDeck(deck);
    dealDeck(deck, suit, face);

    givePokerHand(deck, pokerHandOfPlayerOne);
    showHand(pokerHandOfPlayerOne, suit, face);

    for (functionCounter = 0; functionCounter <3 ; functionCounter ++){

        (*evaluationFunctions[functionCounter])(pokerHandOfPlayerOne);
    }



}


void UpdateTimeSeed(void){
    srand(time(NULL));
    return;
}

void shuffleDeck(int deck[][13]){
    int row;
    int column;
    int cardNumber;

    for(cardNumber =0; cardNumber <=NumberOfCards; cardNumber++){
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

        for (row = 0; row<= 3; row++){
            for (column =0 ; column <= 12; column++){
            card = deck[row][column];
            cardRow = (int)(card/13);
            cardColumn = card%13;
            printf("%5s of %-8s \n", face[cardColumn], suit[cardRow]);
            }
        }
}

void givePokerHand(int deck[][13], int pokerHandOfPlayer[5]){

    int i;
    int row, column;

    for (i = 0; i<=4; i++) {
        row = NumberOfCards /13;
        column = NumberOfCards % 13;
        pokerHandOfPlayer[i] = deck[row][column];
        NumberOfCards = NumberOfCards -1;
    }


}

void showHand(int pokerHandOfPlayer[5], const char *suit[], const char *face[]){
    int card;
    int row, cardRow;
    int cardColumn;
    printf("\nHere is hand of Player 1\n");

    for (row = 0; row<= 4; row++){
            card = pokerHandOfPlayer[row];
            cardRow = card/13;
            cardColumn = card%13;
            printf("%5s of %-8s \n", face[cardColumn], suit[cardRow]);
    }

}

void isTherePair(int pokerHandOfPlayer[5]){
    int card, pairCounter = 0;
    int row;
    int cardColumn[5];

    for (row = 0; row<= 4; row++){
        card = pokerHandOfPlayer[row];
        cardColumn[row] = card%13;}

    for (row = 4; row >=1 ;row --){
        for (int instantCard = row - 1 ; instantCard >= 0 ; instantCard --){
                if (cardColumn[row] == cardColumn[instantCard]) {
                    pairCounter = pairCounter + 1;
                    break;
                }
        }
    }
    printf("There are %d pairs \n", pairCounter);
}

void isThereKinds(int pokerHandOfPlayer[5]){
    int card, kindCounter = 1;
    int row;
    int cardColumn[5];

    for (row = 0; row<= 4; row++){
        card = pokerHandOfPlayer[row];
        cardColumn[row] = card%13;}

    for (row = 4; row >=1 ;row --){
        for (int instantCard = row - 1 ; instantCard >= 0 ; instantCard --){
            if (cardColumn[row] == cardColumn[instantCard]) {
                kindCounter = kindCounter + 1;
                if (kindCounter >= 3){
                    printf("There is a %d of a kind\n", kindCounter);
                    break;
                }
                else{
                    printf("There is no kinds\n");
                }
            }

            kindCounter = 1;
        }
    }

}

void isThereFlush(int pokerHandOfPlayer[5]){
    int card, counter = 0;
    int row;
    int cardRow[5];

    for (row = 0; row<= 4; row++){
        card = pokerHandOfPlayer[row];
        cardRow[row] = card/13;
    }
    for (int instantCard = row - 1 ; instantCard >= 0 ; instantCard --){
        if (cardRow[row] == cardRow[instantCard]){
            counter = counter + 1;
        }
    }
    if (counter == 4){
        printf("There is a Flush\n");
    }
    else{
        printf("There is no Flush\n");
    }

}

void isThereStraight(int pokerHandOfPlayer[5]){



}


