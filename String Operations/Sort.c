#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char string1[999];
    system("cls");
    printf("\t\tSORT THE STRING\n");
    printf("\t\tEnter the string: ");
    printf("\n\t > "); scanf(" %[^\n]s", string1);

    char temp;

    int i, j;
    int n = strlen(string1);

    printf("\n\t\tString before sorting - %s \n", string1);

    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (string1[i] > string1[j]) {
                temp = string1[i];
                string1[i] = string1[j];
                string1[j] = temp;
            }
        }
    }
    
    printf("\n\t\tString after sorting  - %s \n", string1);
}