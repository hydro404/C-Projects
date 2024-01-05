#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char string1[999], string2[999];
    int delete, i, length, j;

    printf("\tDELETE A CHARACTER WITHIN A STRING\n");
    printf("\t\tEnter a string: ");
    printf("\n\t > "); scanf(" %[^\n]s", string1);
    strcpy(string2, string1);
    a:
    printf("\n\tEnter the character position you want to delete: ");
    printf("\n\t > "); scanf("%d", &delete);

    length = strlen(string1);
    if(delete<1 || delete>length){
        system("cls");
        printf("\n\t\tInvalid input! Try again.");
        delete = 0;
        goto a;

    }
    else{

        for(i=delete-1; i<length; i++){
            string1[i] = string1[i+1];
        }

        printf("\n\tString before: %s", string2);
        printf("\n\tString after: %s", string1);
    }
}
