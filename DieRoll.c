#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DiceFaceNumber 6
enum STATUS {CONTINUE, WON, LOST};
int BankBalance = 1000;

void UpdateTimeSeed(void);
int RollDice(void);
void KeepPlaying(int GameStatus, int PlayersPoint, int sum, int Wage);
int GetWage(void);


void main(){
    enum STATUS GameStatus;
    int Wage =0;

    while( BankBalance != 0) {
        if (BankBalance > 2000){
            printf("You are getting somewhere!");
        }else{
            if (BankBalance <=500){
                printf("What a Waste of time!");
            }
        }
        UpdateTimeSeed();
        Wage = GetWage();
        int PlayersPoint;
        int sum = RollDice();
        switch (sum) {
            case 7:
            case 11:
                GameStatus = WON;
                printf("You won!!");
                BankBalance = BankBalance + Wage;
                printf("Now your bank balance is %d \n", BankBalance);
                break;
            case 2:
            case 3:
            case 12:
                GameStatus = LOST;
                printf("You Lost !");
                BankBalance = BankBalance - Wage;
                printf("Now your bank balance is %d \n", BankBalance);
                break;
            default:
                GameStatus = CONTINUE;
                PlayersPoint = sum;
                KeepPlaying(GameStatus, PlayersPoint, sum, Wage);
                break;
        }
    }
    printf("You are broke!!");
}

void UpdateTimeSeed(void){
    srand(time(NULL));
    return;
}

int RollDice(void){
    int DieOne, DieTwo;
    DieOne = 1 + rand()%DiceFaceNumber;
    DieTwo =1 + rand()%DiceFaceNumber;

    printf("%d \n",DieOne + DieTwo);
    return DieOne + DieTwo;
}

void KeepPlaying( int GameStatus, int PlayersPoint, int sum, int Wage){
    while(GameStatus == CONTINUE){
        sum = RollDice();
        if (sum == PlayersPoint){
            GameStatus = WON;
            BankBalance = BankBalance + Wage;
        }
        else{
            if(sum == 7){
                GameStatus = LOST;
                BankBalance = BankBalance - Wage;
            }
        }
    }

    if (GameStatus == WON){
        printf("You won!!");
        printf("Now your bank balance is %d \n", BankBalance);
    }
    else{printf("You Lost !");}
    printf("Now your bank balance is %d \n", BankBalance);
}
int GetWage(void){
    int Wage;
    printf("Enter a wage");
    scanf("%d",&Wage);

    if (Wage <= BankBalance){
        return Wage;
    }
    else{
        printf("You have only %d in your bank\n Please enter a valid wage\n", BankBalance);
        return GetWage();
    }
}