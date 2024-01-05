#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char string1[999], string2[999], newString[999];
    int choice, i, totalsize, j, k=0;
    printf("\tINSERT A STRING WITHIN A STRING\n");
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