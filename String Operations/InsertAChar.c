#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){


    char string[999];
    char string2[999];

    int position;
    char ch[5];
    printf("\tINSERT A CHARACTER WITHIN A STRING\n");
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
