#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

int printRandoms(int lower, int upper);  //randomize a number, the parameter lower is the lowest possible to be randomized and the upper is the highest
void hangMan(); //print the header hangman
void hangManpics(int hang); //print the current status of hangman with the parameter hang. every incorrect, the variable hang increases and the status changes.
void gameOver();
void youWin();

int main(){


    FILE *filePointer ;
    char arr[100][100]; // words to be fscanf in words.c
    char hangWord[100];
    char selectedWord[100];
    char input[2];

    int randomnum, counter = 0;
    int hang = 0;  // initial status of hangman,
    int i=0;
   
    filePointer = fopen("words.c", "r") ;  //open the file as read
     

    if ( filePointer == NULL ){
        printf( "words.c file does not exist!" ) ;
    }

    else{
        
        while(1){
            fscanf(filePointer, "%s", arr[i]); //assign the contents of words.c to the array arr[][]
            i++;
            if(feof(filePointer))
                    break; // hit end-of-file while getting the array
        }

        srand(time(0)); // randomize the shuffle every run

        randomnum = printRandoms(0, i); //selecting the word from words.c thru its index

        int wordLength = strlen(arr[randomnum]); // length of the selected word

        strcpy(selectedWord,arr[randomnum]); // copy the selected word 'arr[randomnum]' and assign to selectedWord

        //printf("Selected Word: %s\n", selectedWord);

        int j, k;

        for(j=0; j<wordLength; j++){
            hangWord[j] = '_'; // print the spaces
        }

        int a;

        do{
            system("cls");
            counter = 0;

            //if all the input are equal to the selectedWord, you win!
            if(strcmp(hangWord,selectedWord)==0){ 
                system("cls");
                youWin();
                printf("\n\nThe correct answer is %s.\n\n", selectedWord);
                break;
            }

            hangMan();
            printf("\n\n\n\n");
            hangManpics(hang); //display the status of hangman

            printf("\n\n\n\nWord Length: %d\n\n", wordLength);

            //printf("Selected Word: %s\n", selectedWord); //check the selected word

            //printing the spaces on initial, but the characters will be replaced if the guess is correct
            for(j=0; j<wordLength; j++){
                printf("%c ", hangWord[j]);
            }
            printf("\n\n\n\n");

            printf("Enter a character: >");
            scanf("%s", input); //input a guess character

            //check the guess character if it exists, if yes change the '_' from the array hangWord to the input character
            for(a=0; a<wordLength+1; a++){
                if(input[0] == selectedWord[a]){
                    hangWord[a] = input[0];
                    counter++;
                }
            }

            //if the guess character does not exist in the selectedWord, add the state of hang  => hangManpics(hang) => magiging next state
            if(counter==0){
                hang++;
            }

            //if guessed five times incorrectly, game over then display the answer!
            if(hang==5){
                system("cls");
                hangManpics(hang);
                gameOver();
                printf("\n\nThe correct answer is %s.\n\n", selectedWord);
                break;
            }

        }while(hang<5); // while not guessed five times incorrectly, do the loop

        fclose(filePointer);
        return 0; 
   }
}
          



int printRandoms(int lower, int upper){
    int i;
    for (i = 0; i < 1; i++) {
        int num = (rand() % (upper - lower)) + lower;
        return num;
    }
}

void hangMan(){

printf("\t\t {}    {}    {}{}     {}    {}    {}}}}}    {}      {}    {}{}     {}    {}\n");
printf("\t\t {}    {}   {}  {}    {}}}  {}   {}    {}   {}}}  {{{}   {}  {}    {}}}  {}\n");
printf("\t\t {}{{}}{}  {}{{}}{}   {} {} {}   {}         {} {{}} {}  {}{{}}{}   {} {} {}\n");
printf("\t\t {}    {}  {}    {}   {}  {{{}   {}  {{{{   {}  {}  {}  {}    {}   {}  {{{}\n");
printf("\t\t {}    {}  {}    {}   {}    {}    {}}}}}    {}      {}  {}    {}   {}    {}\n");
}

void hangManpics(int hang){

    //kada increase ng value ng hang, iba yung magpprint depende sa case.
    switch(hang){
    

    //if hang == 0, eto magpprint, this is the initial state
    case 0:
        //system("cls");
        printf("\t\t\t\t\t      '''\n");
        printf("\t\t\t\t\t        +---+\n");
        printf("\t\t\t\t\t        |   |\n");
        printf("\t\t\t\t\t            |\n");
        printf("\t\t\t\t\t            |\n");
        printf("\t\t\t\t\t            |\n");
        printf("\t\t\t\t\t      ========='''\n");
        break;
    //if hang == 1, eto magpprint at pag namali ng isa and so on...
    case 1:
        //system("cls");
        printf("\t\t\t\t\t      '''\n");
        printf("\t\t\t\t\t        +---+\n");
        printf("\t\t\t\t\t        |   |\n");
        printf("\t\t\t\t\t        O   |\n");
        printf("\t\t\t\t\t            |\n");
        printf("\t\t\t\t\t            |\n");
        printf("\t\t\t\t\t      ========='''\n");
        break;

    case 2:
        //system("cls");
        printf("\t\t\t\t\t      '''\n");
        printf("\t\t\t\t\t        +---+\n");
        printf("\t\t\t\t\t        |   |\n");
        printf("\t\t\t\t\t        O   |\n");
        printf("\t\t\t\t\t       /|   |\n");
        printf("\t\t\t\t\t            |\n");
        printf("\t\t\t\t\t      ========='''\n");
        break;
    
    case 3:
        //system("cls");
        printf("\t\t\t\t\t      '''\n");
        printf("\t\t\t\t\t        +---+\n");
        printf("\t\t\t\t\t        |   |\n");
        printf("\t\t\t\t\t        O   |\n");
        printf("\t\t\t\t\t       /|\\  |\n");
        printf("\t\t\t\t\t            |\n");
        printf("\t\t\t\t\t      ========='''\n");
        break;

    case 4:
        //system("cls");
        printf("\t\t\t\t\t      '''\n");
        printf("\t\t\t\t\t        +---+\n");
        printf("\t\t\t\t\t        |   |\n");
        printf("\t\t\t\t\t        O   |\n");
        printf("\t\t\t\t\t       /|\\  |\n");
        printf("\t\t\t\t\t       /    |\n");
        printf("\t\t\t\t\t      ========='''\n");
        break;
    
     case 5:
        //system("cls");
        printf("\t\t\t\t\t    '''\n");
        printf("\t\t\t\t\t      +---+\n");
        printf("\t\t\t\t\t      |   |\n");
        printf("\t\t\t\t\t      O   |\n");
        printf("\t\t\t\t\t     /|\\  |\n");
        printf("\t\t\t\t\t     / \\  |\n");
        printf("\t\t\t\t\t    ========='''\n");
        break;
    }


}

void gameOver(){
printf("\t\t _______ _______ __   __ _______    _______ __   __ _______ ______   \n");
printf("\t\t|       |       |  |_|  |       |  |       |  | |  |       |    _ |  \n");
printf("\t\t|    ___|   _   |       |    ___|  |   _   |  |_|  |    ___|   | ||  \n");
printf("\t\t|   | __|  |_|  |       |   |___   |  | |  |       |   |___|   |_||_ \n");
printf("\t\t|   ||  |       |       |    ___|  |  |_|  |       |    ___|    __  |\n");
printf("\t\t|   |_| |   _   | ||_|| |   |___   |       ||     ||   |___|   |  | |\n");
printf("\t\t|_______|__| |__|_|   |_|_______|  |_______| |___| |_______|___|  |_|\n");
}

void youWin(){
printf("\t\t __   __ _______ __   __    _     _ ___ __    _ \n");
printf("\t\t|  | |  |       |  | |  |  | | _ | |   |  |  | |\n");
printf("\t\t|  |_|  |   _   |  | |  |  | || || |   |   |_| |\n");
printf("\t\t|       |  | |  |  |_|  |  |       |   |       |\n");
printf("\t\t|_     _|  |_|  |       |  |       |   |  _    |\n");
printf("\t\t  |   | |       |       |  |   _   |   | | |   |\n");
printf("\t\t  |___| |_______|_______|  |__| |__|___|_|  |__|\n");
}