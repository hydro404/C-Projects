//Write a program in C to separate odd and even integers in separate arrays.

#include<stdio.h>

int main(){
    int str[255], odd[255], even[255];
    int num, i, j=0, k=0;

    printf("\n\n\nEnter the size: ");
    scanf("%d", &num);

    printf("Enter %d numbers: \n", num);

    for(i=0; i<num; i++){
        printf("Integer %d: ", i+1);
        scanf("%d", &str[i]);
    }

    for(i=0; i<num; i++){
        if(str[i] % 2 == 0){
            even[j] = str[i];
            j++;
        }
        else{
            odd[k] = str[i];
            k++;
        } 
    }

    printf("\n\nEVEN NUMBERS: \n");

    for(i=0; i<j; i++){
        printf("%d\n", even[i]);
    }

    printf("ODD NUMBERS: \n");
    
    for(i=0; i<k; i++){
        printf("%d\n", odd[i]);
    }

    return 0;
    
}