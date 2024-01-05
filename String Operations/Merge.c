#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    system("cls");
    char string1[999], string2[999];
    printf("\t\tMERGE TWO STRINGS\n");
    printf("\t\tEnter the first string: ");
    printf("\n\t > "); scanf(" %[^\n]s", string1);

    printf("\t\tEnter the second string: ");
    printf("\n\t > "); scanf(" %[^\n]s", string2);
    system("cls");

    printf("\n\t\tConcantenated String: %s",strcat(string1, string2));
}
