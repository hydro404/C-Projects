#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    
    char string1[999];
    int Occ[99];

    system("cls");
    printf("\tSEARCH A CHARACTER WITHIN A STRING\n");
    printf("\t\tEnter the string: ");
    printf("\n\t > "); scanf(" %[^\n]s", string1);
    char ch[1];

    int i, j = 0;
    int n = strlen(string1);
    int counter = 0, numOccurence = 0;

    printf("\n\t\tWhat character do you want to search?");
    printf("\n\t > ");
    scanf(" %c", &ch);

    for(i=0; i<strlen(string1); i++){
        if(string1[i] == ch[0]){
            numOccurence++;
            Occ[j] = i+1;
            j++;
        }
        
    }

    if(numOccurence>0){
        printf("\n\t\tCharacter '%c' has %d number of occurence at position ", ch[0], numOccurence);

        for(i=0; i<numOccurence; i++){
            printf("%d ",Occ[i]);
        }
        printf(" within the string %s", string1);
    }

    else{
        printf("\n\t\tCharacter '%c' does not exist within the string %s", ch[0], string1);
    }
}