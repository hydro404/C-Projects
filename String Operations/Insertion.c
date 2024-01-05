#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void insertCharacter();
void insertString();
/*Insertion 
Deletion
Sorting
Searching
Merging
*/

int main(){
    system("cls");
    int choice = 0, length;
    printf("\n\n\n\t\tWhat do you want to do?\n\n\n\n\n\n");
    printf("\t[1] Insert a character in a string\n");
    printf("\t[2] Insert a string to another string\n");
    printf("\t[3] Exit\n");

    printf("\n\t> "); scanf("%d", &choice);
    
    switch(choice){
        case 1:
        system("cls");
        insertCharacter();
        break;

        case 2:
        system("cls");
        insertString();
        break;

        case 3:
        system("cls");
        printf("\n\n\tP r o g r a m   E x i t!\n");
        break;

        default:
        main();
    }
}
void insertCharacter(){

    char string[999];
    char string2[999];

    int position;
    char ch[5];

    printf("\t\tEnter a string: ");
    printf("\n\t > "); scanf(" %[^\n]s", string);

    system("cls");

    printf("\n\n\tString: %s", string);
    a:
    printf("\n\n\tEnter a position value: ");
    printf("\n\t > "); scanf("%d", &position);

    if(position<0 || position>strlen(string)){
        system("cls");
        printf("\n\t\tInvalid input! Try again.");
        position = 0;
        goto a;
    }
    else{
        printf("\n\t\tWhat character do you want to insert to position %d?", position);
        printf("\n\t > ");
        scanf(" %c", &ch);

        int copyPos = position-1;
        int length = strlen(string)+1;
        int i, j=0;

        for(i=0; i<length; i++){
            if(position-1==i){         
                string2[i] = ch[0];
            }
            else{
                string2[i] = string[j];
                j++;                
            }
            
        }
        printf("\n\tString: %s", string2);
    }
}

void insertString(){
    char string1[999], string2[999], newString[999];
    int choice, i, totalsize, j, k=0;

    printf("\t\tEnter the first string: ");
    printf("\n\t > "); scanf(" %[^\n]s", string1);

    printf("\t\tEnter the second string: ");
    printf("\n\t > "); scanf(" %[^\n]s", string2);

    system("cls");
    
    printf("\t\tString 1: %s", string1);
    printf("\n\t\tString 2: %s", string2);
    
    printf("\n\n\t\tWhat position in string1 do you want to insert string2?");
    printf("\n\t> ");   scanf("%d", &choice);

    totalsize = strlen(string1) + strlen(string2);

    for(i=0; i<totalsize; i++){
        if(choice-1==i){
            for(j=0; j<strlen(string2); j++){
                newString[i] = string2[j];
                i++;
            }
        }
            newString[i] = string1[k];
            k++;
    }
    printf("\n\n\t\tNew String: %s\n\n", newString);
}