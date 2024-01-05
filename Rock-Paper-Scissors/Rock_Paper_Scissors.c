#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void displayResult(int a);
void displayWinner(int a, int b);

int main(){

    int p1, p2;
    char str[5];
    v:
    srand(time(0));
    p1 = (rand()%3)+1;
    //printf("\n\n\n\nP1 : %d", p1);
    p2 = (rand()%3)+1;
    //printf("\nP2 : %d\n\n", p2);
    printf("\n\n\nPLAYER 1: "); displayResult(p1);
    printf("\n\nPLAYER 2: "); displayResult(p2); printf("\n\n");

    displayResult(p1);
    printf(" VS "); 
    displayResult(p2); printf("\n\n");
    printf("RESULT: "); displayWinner(p1, p2);
    printf("\n\nWould you like to try again? Y/N\n");
    printf("> "); scanf("%s", str);

    if((strcmp(str , "Y")==0) || strcmp(str , "y")==0){
        system("cls");
        goto v;
    }
        
    else
        return 0;
}


void displayResult(int a){
    if(a==1){
        printf("ROCK");
    }
    else if(a==2){
        printf("SCISSOR");
    }
    else if(a==3){
        printf("PAPER");
    }
}

void displayWinner(int a, int b){
    if(a==1 && b==2){
        printf("The winner is P1!");
    }
    else if(a==2 && b==1){
        printf("The winner is P2!");
    }
    else if(a==2 && b==3){
        printf("The winner is P1!");
    }
    else if(a==3 && b==2){
        printf("The winner is P2!");
    }
    else if(a==1 && b==3){
        printf("The winner is P2!");
    }
    else if(a==3 && b==1){
        printf("The winner is P1!");
    }
    else{
        printf("Draw. Try again.");
    }
}