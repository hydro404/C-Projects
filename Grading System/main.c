#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//NOTE: Changing the value of max_stud will change the Maximum capacity of the Data Records!!
#define max_stud 20

struct SUBJECTS{
	float MATH;
    float SCIENCE;
    float FILIPINO;
    float AP;
    float ENGLISH;
	float PE;
};

struct stu_records{
	int ID_num;
    char firstNAME[255];
    char middleINITIAL[20];
    char lastNAME[255];
	char SEX[5];
	struct SUBJECTS data;
};

//functions
int displayData(FILE *a, struct stu_records arr[]);
void menu(FILE *a, struct stu_records arr[]);
void modify_add(struct stu_records arr[], int length);
void modify_update(struct stu_records arr[], int length);
void modify_delete(struct stu_records arr[], int length);
void sort_struct(struct stu_records arr[], int length);
void greetings();


int main(){

    FILE *a = fopen("data.c", "r");
	struct stu_records arr[255];

	if(a==NULL)
		printf("\n\n\n\t\t\t\tThe file 'data.c' does not exist within the directory!\n\n\t\t\t\tPlease create a file named 'data.c' within the directory of this program.\n\n\t\t\t\tAfter that, re-run this program.\n\n\n");

	else{
		printf("\n\n\t\t\tNOTE: This program will generate an initial profile if the file 'data.c' has no content in which you can delete later!\n\n");
		menu(a, arr);
		return 0;
	}
}


void greetings(){
	printf("\n\n\n\t\t\t\t\t	_____________________________________________________________        \n");
	printf("\t\t\t\t\t________|						       	    |________\n");
	printf("\t\t\t\t\t\\       |  WELCOME TO CAMALIG NATIONAL HIGH SCHOOL GRADING SYSTEM   |       /\n");
	printf("\t\t\t\t\t \\      |                                                           |      / \n");
	printf("\t\t\t\t\t /      =============================================================      \\ \n");
	printf("\t\t\t\t\t/       \\                                                           /       \\\n");
	printf("\t\t\t\t\t==========                                                         ===========\n\n\n\n");
}

void menu(FILE *a, struct stu_records arr[]){
	int chosen, chosen2, chosen3, chosen4, length;
	int index, indicator=0, index2, male=0, female=0, passed=0, failed=0;
	float average;

	main_menu:
	greetings();
	printf("\t\t\t\t\t\t\t\tWhat would you like to do?\n");
	printf("\n\t\t\t\t\t\t\t[1] View List of Students and their Grades\n");
	printf("\t\t\t\t\t\t\t[2] Modify the List\n");
	printf("\n\t\t\t\t\t\t> ");
	scanf("%d", &chosen);

	if(chosen==1){
		system("cls");
		menu:
		length = displayData(a, arr);
		printf("\n\n\t\t\t\t\t\t\t\tWhat would you like to do?\n");
		printf("\n\t\t\t\t\t\t\t[1] Modify the List");
		printf("\n\t\t\t\t\t\t\t[2] Compute the average of a student");
		printf("\n\t\t\t\t\t\t\t[3] View Summary");
		printf("\n\t\t\t\t\t\t\t[4] Exit\n");
		printf("\n\t\t\t\t\t\t\t> "); scanf("%d", &chosen2);

			if(chosen2==1){
			system("cls");
			sub_menu1:
			length = displayData(a, arr);
			printf("\n\n\t\t\t\t\t\t\t\tWhat would you like to do?\n");
			printf("\n\t\t\t\t\t\t\t[1] Add a profile");
			printf("\n\t\t\t\t\t\t\t[2] Update a profile");
			printf("\n\t\t\t\t\t\t\t[3] Delete a profile");
			printf("\n\t\t\t\t\t\t\t[4] Go Back\n");
			printf("\n\t\t\t\t\t\t\t> ");
			scanf("%d", &chosen3);

			if(chosen3==1){
					system("cls");
					ask_user:
					printf("\n\n\t\t\t\t\t\t\t\tWould you like to continue?\n");
					printf("\n\t\t\t\t\t\t\t[1] Yes");
					printf("\n\t\t\t\t\t\t\t[2] No");
					printf("\n\t\t\t\t\t\t\t> "); scanf("%d", &chosen4);

					if(chosen4==1){
						system("cls");
						modify_add(arr, length);
						goto menu;
					}
					else if(chosen4==2){
						system("cls");
						goto sub_menu1;
					}
					else{
						system("cls");
						goto ask_user;
					}
				}

			else if(chosen3==2){
					system("cls");
					ask_user1:
					printf("\n\n\t\t\t\t\t\t\t\tWould you like to continue?\n");
					printf("\n\t\t\t\t\t\t\t[1] Yes");
					printf("\n\t\t\t\t\t\t\t[2] No");
					printf("\n\t\t\t\t\t\t\t> "); scanf("%d", &chosen4);

						if(chosen4==1){
							system("cls");
							displayData(a, arr);
							modify_update(arr,length);
							goto menu;
						}
						else if(chosen4==2){
							system("cls");
							goto sub_menu1;
						}
						else{
							system("cls");
							goto ask_user1;
						}
					}

				else if(chosen3==3){
					system("cls");
					ask_user2:
					printf("\n\n\t\t\t\t\t\t\t\tWould you like to continue?\n");
					printf("\n\t\t\t\t\t\t\t[1] Yes");
					printf("\n\t\t\t\t\t\t\t[2] No");
					printf("\n\t\t\t\t\t\t\t> "); scanf("%d", &chosen4);

						if(chosen4==1){
							system("cls");
							modify_delete(arr, length);
							goto menu;
						}
						else if(chosen4==2){
							system("cls");
							goto sub_menu1;
						}
						else{
							system("cls");
							goto ask_user2;
						}


				}

				else if(chosen3==4){
						system("cls");
						goto menu;
					}

				else {system("cls"); goto sub_menu1;}
			}

			else if(chosen2==2){
				system("cls");
				sub_menuA:
				length = displayData(a, arr);

				printf("\n\t\t\t\t\t\t   NOTE: YOU CAN ENTER THE ID AS AN INTEGER");
				printf("\n\n\t\t\t\t\tENTER THE LAST THREE DIGITS OF THE ID YOU WANT TO GET THE AVERAGE:\n");
				printf("\n\t\t\t\t\t> "); scanf("%d", &chosen3);

				if(chosen3 <= 0 || chosen3 > max_stud){
					system("cls");
					printf("\n\t\t\t\t\t\t        THE ENTERED ID IS INVALID. TRY AGAIN.");
					printf("\n\t\t\t\t\t\t         ID NUMBER SHOULD BE FROM 001 to %03d\n\n ", max_stud);
					goto sub_menuA;
				}

				for(index=0; index<max_stud; index++){
					if(chosen3==arr[index].ID_num){
						indicator = 1;
						break;
					}
				}

				if(indicator==1){
					system("cls");
					displayData(a, arr);
					average = (arr[index].data.MATH + arr[index].data.SCIENCE + arr[index].data.FILIPINO + arr[index].data.AP + arr[index].data.ENGLISH + arr[index].data.PE)/6;
					menu_sub:
					printf("\n\n\t\t\t\t\t\t\tThe average of %s %s. %s is %.2f\n",  arr[index].firstNAME, arr[index].middleINITIAL, arr[index].lastNAME, average);
				}

				else{
					system("cls");
					printf("\n\t\t\t\t\t\t       THE ENTERED ID DOES NOT EXIST! TRY AGAIN. \n\n ");
					goto sub_menuA;
				}

				indicator = 0;

				printf("\n\n\t\t\t\t\t\t\t\tWhat would you like to do?\n");
				printf("\n\t\t\t\t\t\t\t[1] Go back to Main Menu");
				printf("\n\t\t\t\t\t\t\t[2] Compute or check the average of other students");
				printf("\n\t\t\t\t\t\t\t[3] Exit\n");
				printf("\n\t\t\t\t\t\t\t> "); scanf("%d", &chosen3);

					if(chosen3==1){
						system("cls");
						goto menu;
					}

					else if(chosen3==2){
						system("cls");
						 goto sub_menuA;
					}

					else if(chosen3==3){
						res3:
						system("cls");
						printf("\n\n\t\t\t\t\t\t\t\tWould you like to continue?\n");
						printf("\n\t\t\t\t\t\t\t[1] Yes");
						printf("\n\t\t\t\t\t\t\t[2] No");
						printf("\n\t\t\t\t\t\t\t> "); scanf("%d", &chosen4);
							if(chosen4==1){
								system("cls");
								printf("\n\n\t\t\t\t\t\t\tP r o g r a m  E x i t e d !\n\n\n");
							}
							else if(chosen4==2){
								system("cls");
								goto menu_sub;
							}
							else{
								system("cls");
								goto res3;
							}

					}
					else {system("cls"); displayData(a, arr); goto menu_sub;}
			}

			else if(chosen2==3){
				system("cls");

				for(index2=0; index2<length; index2++){

					average = (arr[index2].data.MATH + arr[index2].data.SCIENCE + arr[index2].data.FILIPINO + arr[index2].data.AP + arr[index2].data.ENGLISH + arr[index2].data.PE)/6;

					if(average>=75) passed++;
					else if(average<75) failed++;

					if((strcmp(arr[index2].SEX, "M")==0) || (strcmp(arr[index2].SEX, "m")==0)){
						male++;
					}
					else if((strcmp(arr[index2].SEX, "F")==0) || (strcmp(arr[index2].SEX, "f")==0)){
						female++;
					}
				}
				summary:
				displayData(a, arr);
				printf("\n\n\t\t\t\t\t\t\tTotal Number of Student/s: %d", length);
				printf("\n\n\t\t\t\t\t\t\tNumber of Male/s: %d", male);
				printf("\n\t\t\t\t\t\t\tNumber of Female/s: %d\n", female);
				printf("\n\n\t\t\t\t\t\t\tPassing Grade: Average should be 75 and up\n");
				printf("\n\t\t\t\t\t\t\tNumber of Student/s who passed: %d", passed);
				printf("\n\t\t\t\t\t\t\tNumber of Student/s who failed: %d\n", failed);

				printf("\n\n\t\t\t\t\t\t\t\tWhat would you like to do?\n");
				printf("\n\t\t\t\t\t\t\t[1] Go back to Main Menu");
				printf("\n\t\t\t\t\t\t\t[2] Exit\n");
				printf("\n\t\t\t\t\t\t\t> "); scanf("%d", &chosen3);

					if(chosen3==1) {
						male = 0; female = 0; passed = 0; failed = 0;
						system("cls");
						goto menu;
					}

					else if(chosen3==2){
						res2:
						system("cls");
						printf("\n\n\t\t\t\t\t\t\t\tWould you like to continue?\n");
						printf("\n\t\t\t\t\t\t\t[1] Yes");
						printf("\n\t\t\t\t\t\t\t[2] No");
						printf("\n\t\t\t\t\t\t\t> "); scanf("%d", &chosen4);
							if(chosen4==1){
								system("cls");
						 		printf("\n\n\t\t\t\t\t\t\tP r o g r a m  E x i t e d !\n\n\n");
							}
							else if(chosen4==2){
								system("cls");
								goto summary;
							}
							else{
								system("cls");
								goto res2;
							}

					}
					else {system("cls"); goto summary;}
			}

			else if(chosen2==4){
				exit_back:
				system("cls");
					printf("\n\n\t\t\t\t\t\t\t\tWould you like to continue?\n");
					printf("\n\t\t\t\t\t\t\t[1] Yes");
					printf("\n\t\t\t\t\t\t\t[2] No");
					printf("\n\t\t\t\t\t\t\t> "); scanf("%d", &chosen4);
					
					if(chosen4==1){
						system("cls");
						printf("\n\n\t\t\t\t\t\t\tP r o g r a m  E x i t e d !\n\n\n");
					}
					else if(chosen4==2){
						system("cls");
						goto menu;
					}
					else{
						system("cls");
						goto exit_back;
					}
			}

			else{
				system("cls");
				goto menu;
			}
	}

	else if(chosen==2){
			sub_menu2:
			system("cls");
			length = displayData(a, arr);
			printf("\n\n\t\t\t\t\t\t\t\tWhat would you like to do?\n");
			printf("\n\t\t\t\t\t\t\t[1] Add a profile");
			printf("\n\t\t\t\t\t\t\t[2] Update a profile");
			printf("\n\t\t\t\t\t\t\t[3] Delete a profile");
			printf("\n\t\t\t\t\t\t\t[4] Go Back\n");
			printf("\n\t\t\t\t\t\t\t> ");
			scanf("%d", &chosen3);

			if(chosen3==1){
				system("cls");
					ask_user3:
					printf("\n\n\t\t\t\t\t\t\t\tWould you like to continue?\n");
					printf("\n\t\t\t\t\t\t\t[1] Yes");
					printf("\n\t\t\t\t\t\t\t[2] No");
					printf("\n\t\t\t\t\t\t\t> "); scanf("%d", &chosen4);
						if(chosen4==1){
							system("cls");
							modify_add(arr, length);
							goto menu;
						}
						else if(chosen4==2){
							system("cls");
							goto sub_menu2;
						}
						else{
							system("cls");
							goto ask_user3;
						}
			}

			else if(chosen3==2){
				system("cls");
					ask_user4:
					printf("\n\n\t\t\t\t\t\t\t\tWould you like to continue?\n");
					printf("\n\t\t\t\t\t\t\t[1] Yes");
					printf("\n\t\t\t\t\t\t\t[2] No");
					printf("\n\t\t\t\t\t\t\t> "); scanf("%d", &chosen4);
						if(chosen4==1){
							system("cls");
							displayData(a, arr);
							modify_update(arr,length);
							goto menu;
						}
						else if(chosen4==2){
							system("cls");
							goto sub_menu2;
						}
						else{
							system("cls");
							goto ask_user4;
						}
			}

			else if(chosen3==3){
				system("cls");
					ask_user5:
					printf("\n\n\t\t\t\t\t\t\t\tWould you like to continue?\n");
					printf("\n\t\t\t\t\t\t\t[1] Yes");
					printf("\n\t\t\t\t\t\t\t[2] No");
					printf("\n\t\t\t\t\t\t\t> "); scanf("%d", &chosen4);
						if(chosen4==1){
							system("cls");
							modify_delete(arr, length);
							goto menu;
						}
						else if(chosen4==2){
							system("cls");
							goto sub_menu2;
						}
						else{
							system("cls");
							goto ask_user5;
						}
			}

			else if(chosen3==4){
					system("cls");
					goto menu;
			}
			
			else {system("cls"); goto sub_menu2;}
	}

	else{
		system("cls");
		goto main_menu;
	}
}

int displayData(FILE *a, struct stu_records arr[]){
	a = fopen("data.c", "r");
	int i=0, j, indicator = 0;

	while(!feof(a)){

		indicator = 0;
		reset:
		fscanf(a, "%d", &arr[i].ID_num);
		fscanf(a, "\n%[^\n]s", arr[i].firstNAME);
		fscanf(a, "\n%s", arr[i].middleINITIAL);
		fscanf(a, "\n%[^\n]s", arr[i].lastNAME);
		fscanf(a, "\n%s", arr[i].SEX);
		fscanf(a, "%f", &arr[i].data.MATH);
		fscanf(a, "%f", &arr[i].data.SCIENCE);
		fscanf(a, "%f", &arr[i].data.FILIPINO);
		fscanf(a, "%f", &arr[i].data.AP);
		fscanf(a, "%f", &arr[i].data.ENGLISH);
		fscanf(a, "%f\n", &arr[i].data.PE);

				if(arr[i].data.MATH == 0){
					indicator++;
						if(indicator>1){
							arr[i].ID_num = 1;
							strcpy(arr[i].firstNAME, "INITIAL");
							strcpy(arr[i].middleINITIAL, "N");
							strcpy(arr[i].lastNAME, "DATA");
							strcpy(arr[i].SEX, "M");
							arr[i].data.MATH = 91;
							arr[i].data.SCIENCE = 92;
							arr[i].data.FILIPINO = 93;
							arr[i].data.AP = 95;
							arr[i].data.ENGLISH = 95;
							arr[i].data.PE = 95;
						}
					goto reset;
				}
				else{
					i++;
				}
	}
	indicator = 0;
	fclose(a);
	printf("  \t\t\t\t\t\t-------------------------------------------------------\n");
	printf("  \t\t\t\t\t\t| CAMALIG NATIONAL HIGH SCHOOL STUDENT GRADING SYSTEM |\n");
	printf("  \t\t\t\t\t\t-------------------------------------------------------\n");
	printf("  ---------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("  |    ID     | |       FIRST NAME      | |M.I.| |    LAST NAME    |  | SEX |  |  MATH  |  |SCIENCE |  |FILIPINO|  |   AP   |  |ENGLISH |  |   PE   |\n");
	printf("  ---------------------------------------------------------------------------------------------------------------------------------------------------\n");
	for(j=0; j<i; j++){

		printf("  |111-639-%03d|", arr[j].ID_num);
		printf(" |%20s   |", arr[j].firstNAME);
		printf(" |%2s. |", arr[j].middleINITIAL);
		printf(" |%15s  |", arr[j].lastNAME);
		printf("  |  %s  |", arr[j].SEX);
		printf("  |   %.f   |", arr[j].data.MATH);
		printf("  |   %.f   |", arr[j].data.SCIENCE);
		printf("  |   %.f   |", arr[j].data.FILIPINO);
		printf("  |   %.f   |", arr[j].data.AP);
		printf("  |   %.f   |", arr[j].data.ENGLISH);
		printf("  |   %.f   |\n", arr[j].data.PE);
		printf("  ---------------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
	FILE *b = fopen("data.c", "w");
	for(j=0; j<i; j++){

			fprintf(b, "%d", arr[j].ID_num);
			fprintf(b, "\n%s", strupr(arr[j].firstNAME));
			fprintf(b, "\n%s", strupr(arr[j].middleINITIAL));
			fprintf(b, "\n%s", strupr(arr[j].lastNAME));
			fprintf(b, "\n%s", strupr(arr[j].SEX));
			fprintf(b, "\n%.f", arr[j].data.MATH);
			fprintf(b, "\n%.f", arr[j].data.SCIENCE);
			fprintf(b, "\n%.f", arr[j].data.FILIPINO);
			fprintf(b, "\n%.f", arr[j].data.AP);
			fprintf(b, "\n%.f", arr[j].data.ENGLISH);
			fprintf(b, "\n%.f\n\n", arr[j].data.PE);
		}
		fclose(b);
	return i;
}

void modify_add(struct stu_records arr[], int length){
	int i, index, chosen4;
	int temp_int, chk_id = 0, chk_name = 0, chk_sex = 0, temp_grade, chosen;
	char temp_fname[255], temp_mi[20], temp_lname[255], temp_sex[5];
	char sex_array[5] = {'M', 'm', 'F', 'f'};
	FILE *a = fopen("data.c", "r");

	add_id:
	printf("\n\t\t\t\t\t\t\tNOTE: YOU CAN ENTER THE ID AS AN INTEGER"); 
	printf("\n\t\t\t\t\tNOTE: THE MAXIMUM CAPACITY OF THIS GRADING SYSTEM IS UP TO %d STUDENTS", max_stud);
	printf("\n\n\t\t\t\t\t\t\tENTER THE LAST THREE DIGIT/S OF YOUR ID: ");
	printf("\n\n\t\t\t\t\t\t> "); scanf("%d", &arr[length].ID_num);

	temp_int = arr[length].ID_num;

		if(temp_int <= 0 || temp_int > max_stud){
			system("cls");
			printf("\n\n\t\t\t\t\t\t\t  THE ENTERED ID IS INVALID. TRY AGAIN.");
			printf("\n\t\t\t\t\t\t\t   ID NUMBER SHOULD BE FROM 001 to %03d\n\n ", max_stud);
			goto add_id;
		}


		for(index=0; index<length; index++){
			if(temp_int==arr[index].ID_num){
				chk_id = 1;
				break;
			}
		}

			if(chk_id==1){
				system("cls");
				printf("\n\n\t\t\t\t\t\t\t  THE ENTERED ID ALREADY EXISTS! TRY AGAIN. \n\n ");
				chk_id = 0;
				goto add_id;
			}

	system("cls");
	printf("\n\n\t\t\t\t\t\t\tENTER YOUR FIRST NAME: ");
	printf("\n\t\t\t\t\t\t> "); scanf(" %[^\n]s", strupr(arr[length].firstNAME));
	strcpy(temp_fname, strupr(arr[length].firstNAME));

	system("cls");
	initial_add:
	printf("\n\n\t\t\t\t\t\t\tENTER YOUR MIDDLE INITIAL: ");
	printf("\n\t\t\t\t\t\t> "); scanf(" %[^\n]s", strupr(arr[length].middleINITIAL));
	strcpy(temp_mi, strupr(arr[length].middleINITIAL));

	if(strlen(temp_mi)>1){
		system("cls");
		printf("\n\n\t\t\t\t\t\tTHE ENTERED MIDDLE INITIAL IS INVALID! TRY AGAIN. \n\n ");
		goto initial_add;
	}

	system("cls");
	printf("\n\n\t\t\t\t\t\t\tENTER YOUR LAST NAME: ");
	printf("\n\t\t\t\t\t\t> "); scanf(" %[^\n]s", strupr(arr[length].lastNAME));
	strcpy(temp_lname, strupr(arr[length].lastNAME));

		for(index=0; index<length; index++){
			if((strcmp(temp_fname, strupr(arr[index].firstNAME))==0) &&
			(strcmp(temp_mi, strupr(arr[index].middleINITIAL))==0) &&
			(strcmp(temp_lname, strupr(arr[index].lastNAME))==0)) chk_name = 1;
		}

	if(chk_name==1){
			system("cls");
			printf("\t\t\t\t\t\t\tTHE ENTERED NAME ALREADY EXISTS! TRY AGAIN. \n\n ");
			displayData(a, arr);
			chk_name = 0;
			add_name:
			printf("\n\t\t\t\t\t\t\t\tWhat would you like to do?\n");
			printf("\n\t\t\t\t\t\t\t[1] Go back to Main Menu");
			printf("\n\t\t\t\t\t\t\t[2] Enter ID again");
			printf("\n\t\t\t\t\t\t\t[3] Exit\n");
			printf("\n\t\t\t\t\t\t\t> "); scanf("%d", &chosen);

				if(chosen==1){
					system("cls");
					menu(a, arr);
					goto end;
				}
				else if(chosen==2){
					system("cls");
					goto add_id;
				}
				else if(chosen==3){
					res:
					system("cls");
					printf("\n\n\t\t\t\t\t\t\t\tWould you like to continue?\n");
					printf("\n\t\t\t\t\t\t\t[1] Yes");
					printf("\n\t\t\t\t\t\t\t[2] No");
					printf("\n\t\t\t\t\t\t\t> "); scanf("%d", &chosen4);
					if(chosen4==1){
						system("cls");
						printf("\n\n\t\t\t\t\t\t\t r o g r a m  E x i t e d !\n\n\n");
						goto end;
					}
					else if(chosen4==2){
						system("cls");
						goto add_name;
					}
					else{
						system("cls");
						goto res;
					}

				}
				else{
					system("cls"); displayData(a, arr);
					goto add_name;
				}
		}

		system("cls");
		add_sex:
		printf("\n\n\t\t\t\t\t\t\tENTER YOUR SEX: (M/F) ");
		printf("\n\t\t\t\t\t\t> "); scanf(" %s", arr[length].SEX);

		strcpy(temp_sex, arr[length].SEX);

			if((strcmp(temp_sex, "M")==0) || (strcmp(temp_sex, "m")==0) || (strcmp(temp_sex, "F")==0) || (strcmp(temp_sex, "f")==0))
				strcpy(arr[length].SEX, temp_sex);
			else{
				system("cls");
				printf("\n\n\t\t\t\t\tTHE ENTERED CHARACTER FOR SEX IS INVALID. TRY AGAIN. \n\n ");
				goto add_sex;
			}

		system("cls");
		add_g1:
		printf("\n\n\t\t\t\t\t\t\tENTER YOUR GRADE IN MATH: ");
		printf("\n\t\t\t\t\t\t> "); scanf("%f", &arr[length].data.MATH);
		temp_grade = arr[length].data.MATH;

		if(temp_grade<65 || temp_grade>99){
			system("cls");
			printf("\n\n\t\t\t\t\t\tTHE ENTERED GRADE IS INVALID. TRY AGAIN.\n");
			printf("\t\t\t\t\t\t     ENTER A GRADE FROM 65 to 99. \n\n ");
			goto add_g1;
		}

		system("cls");
		add_g2:
		printf("\n\n\t\t\t\t\t\t\tENTER YOUR GRADE IN SCIENCE: ");
		printf("\n\t\t\t\t\t\t> "); scanf("%f", &arr[length].data.SCIENCE);
		temp_grade = arr[length].data.SCIENCE;

		if(temp_grade<65  || temp_grade>99){
			system("cls");
			printf("\n\n\t\t\t\t\t\tTHE ENTERED GRADE IS INVALID. TRY AGAIN. \n\n ");
			printf("\t\t\t\t\t\t     ENTER A GRADE FROM 65 to 99. \n\n ");
			goto add_g2;
		}

		system("cls");
		add_g3:
		printf("\n\n\t\t\t\t\t\t\tENTER YOUR GRADE IN FILIPINO: ");
		printf("\n\t\t\t\t\t\t> "); scanf("%f", &arr[length].data.FILIPINO);
		temp_grade = arr[length].data.FILIPINO;

		if(temp_grade<65  || temp_grade>99){
			system("cls");
			printf("\n\n\t\t\t\t\t\t  THE ENTERED GRADE IS INVALID. TRY AGAIN. \n\n ");
			printf("\t\t\t\t\t\t     ENTER A GRADE FROM 65 to 99. \n\n ");
			goto add_g3;
		}

		system("cls");
		add_g4:
		printf("\n\n\t\t\t\t\t\t\tENTER YOUR GRADE IN AP: ");
		printf("\n\t\t\t\t\t\t> "); scanf("%f", &arr[length].data.AP);
		temp_grade = arr[length].data.AP;

		if(temp_grade<65  || temp_grade>99){
			system("cls");
			printf("\n\n\t\t\t\t\t\tTHE ENTERED GRADE IS INVALID. TRY AGAIN. \n\n ");
			printf("\t\t\t\t\t\t     ENTER A GRADE FROM 65 to 99. \n\n ");
			goto add_g4;
		}

		system("cls");
		add_g5:
		printf("\n\n\t\t\t\t\t\t\tENTER YOUR GRADE IN ENGLISH: ");
		printf("\n\t\t\t\t\t\t> "); scanf("%f", &arr[length].data.ENGLISH);
		temp_grade = arr[length].data.ENGLISH;

		if(temp_grade<65  || temp_grade>99){
			system("cls");
			printf("\n\n\t\t\t\t\t\t  THE ENTERED GRADE IS INVALID. TRY AGAIN. \n\n ");
			printf("\t\t\t\t\t\t     ENTER A GRADE FROM 65 to 99. \n\n ");
			goto add_g5;
		}

		system("cls");
		add_g6:
		printf("\n\n\t\t\t\t\t\t\tENTER YOUR GRADE IN PE: ");
		printf("\n\t\t\t\t\t\t> "); scanf("%f", &arr[length].data.PE);

		temp_grade = arr[length].data.PE;

		if(temp_grade<65  || temp_grade>99){
			system("cls");
			printf("\n\n\t\t\t\t\t\tTHE ENTERED GRADE IS INVALID. TRY AGAIN. \n\n ");
			printf("\t\t\t\t\t\t     ENTER A GRADE FROM 65 to 99. \n\n ");
			goto add_g6;
		}

		length++;

		system("cls");
		printf("\n\n\t\t\t\t\t\t         Profile ID %03d was successfully added!\n\n ", temp_int);
		FILE *b = fopen("data.c", "w");
		sort_struct(arr, length);

		for(i=0; i<length; i++){

			fprintf(b, "%d", arr[i].ID_num);
			fprintf(b, "\n%s", strupr(arr[i].firstNAME));
			fprintf(b, "\n%s", strupr(arr[i].middleINITIAL));
			fprintf(b, "\n%s", strupr(arr[i].lastNAME));
			fprintf(b, "\n%s", strupr(arr[i].SEX));
			fprintf(b, "\n%.f", arr[i].data.MATH);
			fprintf(b, "\n%.f", arr[i].data.SCIENCE);
			fprintf(b, "\n%.f", arr[i].data.FILIPINO);
			fprintf(b, "\n%.f", arr[i].data.AP);
			fprintf(b, "\n%.f", arr[i].data.ENGLISH);
			fprintf(b, "\n%.f\n\n", arr[i].data.PE);
		}
		end:
		fclose(b);
}

void modify_delete(struct stu_records arr[], int length){

	int i, chosen4, indicator = 0, j, copy, copy2, c;
	FILE *a = fopen("data.c", "r");

	system("cls");
	delete_id:
	length = displayData(a, arr);
	printf("\n\n");
	printf("\n\t\t\t\t\t\t   NOTE: YOU CAN ENTER THE ID AS AN INTEGER");
	printf("\n\n\t\t\t\t\tENTER THE LAST THREE DIGITS OF THE ID PROFILE YOU WANT TO DELETE: ");
	printf("\n\n\t\t\t\t> "); scanf("%d", &chosen4);

	copy = chosen4;

		if(chosen4 <= 0 || chosen4 > max_stud){
			system("cls");
			printf("\n\t\t\t\t\t\t        THE ENTERED ID IS INVALID. TRY AGAIN.");
			printf("\n\t\t\t\t\t\t         ID NUMBER SHOULD BE FROM 001 to %03d\n\n ", max_stud);
			goto delete_id;
		}
  
		for(i=0; i<max_stud; i++){
			if(arr[i].ID_num==chosen4){
				indicator = 1;
				break;
			}
		}

	if(indicator==1){
		for(j=i; j<length; j++){
			arr[j].ID_num = arr[j+1].ID_num;
			strcpy(arr[j].firstNAME, arr[j+1].firstNAME);
			strcpy(arr[j].middleINITIAL, arr[j+1].middleINITIAL);
			strcpy(arr[j].lastNAME, arr[j+1].lastNAME);
			strcpy(arr[j].SEX, arr[j+1].SEX);
			arr[j].data.MATH = arr[j+1].data.MATH;
			arr[j].data.SCIENCE = arr[j+1].data.SCIENCE;
			arr[j].data.FILIPINO = arr[j+1].data.FILIPINO;
			arr[j].data.AP = arr[j+1].data.AP;
			arr[j].data.ENGLISH = arr[j+1].data.ENGLISH;
			arr[j].data.PE = arr[j+1].data.PE;
		}
	}
	else{
		system("cls");
		printf("\n\t\t\t\t\t\t      THE ENTERED ID DOES NOT EXIST. TRY AGAIN. \n\n ");
		goto delete_id;
	}
	system("cls");
	indicator = 0;
	printf("\n\n\t\t\t\t\t\t         Profile ID %03d was successfully deleted.\n", copy);

		length--;
		FILE *b = fopen("data.c", "w");
		sort_struct(arr, length);
			for(i=0; i<length; i++){

			fprintf(b, "%d", arr[i].ID_num);
			fprintf(b, "\n%s", strupr(arr[i].firstNAME));
			fprintf(b, "\n%s", strupr(arr[i].middleINITIAL));
			fprintf(b, "\n%s", strupr(arr[i].lastNAME));
			fprintf(b, "\n%s", strupr(arr[i].SEX));
			fprintf(b, "\n%.f", arr[i].data.MATH);
			fprintf(b, "\n%.f", arr[i].data.SCIENCE);
			fprintf(b, "\n%.f", arr[i].data.FILIPINO);
			fprintf(b, "\n%.f", arr[i].data.AP);
			fprintf(b, "\n%.f", arr[i].data.ENGLISH);
			fprintf(b, "\n%.f\n\n", arr[i].data.PE);
		}
		fclose(b);
}

void modify_update(struct stu_records arr[], int length){
	FILE *a = fopen("data.c", "r");
	int id, i, chk_id=0, index2;
	float  math, science, filipino, ap, english, pe;
	char fname[255], mi[255], lname[255], sex[20];
	int chosen, chosen2, chosen3, index, indicator = 0;

	system("cls");
	update_id1:
	displayData(a, arr);
	printf("\n\t\t\t\t\t\t\tNOTE: YOU CAN ENTER THE ID AS AN INTEGER");
	printf("\n\n\t\t\t\t\t\tENTER THE LAST THREE DIGITS OF THE ID YOU WANT TO UPDATE:\n");
	printf("\n\t\t\t\t\t> "); scanf("%d", &chosen);

		if(chosen <= 0 || chosen > max_stud){
			system("cls");
			printf("\n\t\t\t\t\t\t        THE ENTERED ID IS INVALID. TRY AGAIN.");
			printf("\n\t\t\t\t\t\t         ID NUMBER SHOULD BE FROM 001 to %03d\n\n ", max_stud);
			goto update_id1;
		}

		for(index=0; index<max_stud; index++){
			if(chosen==arr[index].ID_num){
				indicator = 1;
				break;
			}
		}

			if(indicator==1){
				system("cls");
				displayData(a, arr);

				update_menu:
				printf("\n\n\t\t\t\t\t\t       Profile ID %03d was chosen to be edited.\n", chosen);
				printf("\n\n\t\t\t\t\t\t\t   What would you like to edit?\n");
				printf("\n\t\t\t\t\t\t\t [1] ID");
				printf("\n\t\t\t\t\t\t\t [2] FIRST NAME");
				printf("\n\t\t\t\t\t\t\t [3] MIDDLE INITIAL");
				printf("\n\t\t\t\t\t\t\t [4] LAST NAME");
				printf("\n\t\t\t\t\t\t\t [5] SEX");
				printf("\n\t\t\t\t\t\t\t [6] GRADE IN MATH");
				printf("\n\t\t\t\t\t\t\t [7] GRADE IN SCIENCE");
				printf("\n\t\t\t\t\t\t\t [8] GRADE IN FILIPINO");
				printf("\n\t\t\t\t\t\t\t [9] GRADE IN AP");
				printf("\n\t\t\t\t\t\t\t[10] GRADE IN ENGLISH");
				printf("\n\t\t\t\t\t\t\t[11] GRADE IN PE");
				printf("\n\t\t\t\t\t\t\t[12] Go back to Main Menu");
				printf("\n\n\t\t\t\t\t\t\t> "); scanf("%d", &chosen2);

						if(chosen2==1){
							system("cls");
							displayData(a, arr);
							update_id2:
							printf("\n\n\t\t\t\t\t\t\tEnter the updated value of ID:\n");
							printf("\n\t\t\t\t\t\t\t> "); scanf("%d", &id);

								if(id <= 0 || id > max_stud){
								system("cls");
								displayData(a, arr);
								printf("\n\t\t\t\t\t\t        THE ENTERED ID IS INVALID. TRY AGAIN.");
								printf("\n\t\t\t\t\t\t         ID NUMBER SHOULD BE FROM 001 to %03d\n\n ", max_stud);
								goto update_id2;
								}

								for(index2=0; index2<length; index2++){
									if(id==arr[index2].ID_num){
										chk_id = 1;
										break;
									}
								}

								if(chk_id==1){
									system("cls");
									displayData(a, arr);
									printf("\t\t\t\t\t\t         THE ENTERED ID ALREADY EXISTS! TRY AGAIN. \n\n ");
									chk_id = 0;
									goto update_id2;
								}
								else if(chk_id==0){
									arr[index].ID_num = id;
								}
								system("cls");
								printf("\n\n\t\t\t\t\t\t\t     Profile ID %03d was updated.\n\n", id);
						}

						else if(chosen2==2){
							system("cls");
							displayData(a, arr);
							printf("\n\n\t\t\t\t\t\t\tEnter the updated value of First Name:\n");
							printf("\n\t\t\t\t\t\t\t> "); scanf(" %[^\n]", fname);
							strcpy(arr[index].firstNAME, fname);
							system("cls");
							printf("\n\n\t\t\t\t\t\t\t     Profile ID %03d was updated.\n\n", chosen);
						}

						else if(chosen2==3){
							system("cls");
							update_initial:
							displayData(a, arr);
							printf("\n\n\t\t\t\t\t\t\tEnter the updated value of Middle Initial:\n");
							printf("\n\t\t\t\t\t\t\t> "); scanf("%s", mi);
							if(strlen(mi)>1){
								system("cls");
								printf("\n\n\t\t\t\t\t\t   THE ENTERED MIDDLE INITIAL IS INVALID! TRY AGAIN. \n\n ");
								goto update_initial;
							}
							else{
								strcpy(arr[index].middleINITIAL, mi);
								system("cls");
								printf("\n\n\t\t\t\t\t\t\t     Profile ID %03d was updated.\n\n", chosen);
							}

						}

						else if(chosen2==4){
							system("cls");
							displayData(a, arr);
							printf("\n\n\t\t\t\t\t\t\tEnter the updated value of Last Name:\n");
							printf("\n\t\t\t\t\t\t\t> "); scanf(" %[^\n]", lname);
							strcpy(arr[index].lastNAME, lname);
							system("cls");
							printf("\n\n\t\t\t\t\t\t\t     Profile ID %03d was updated.\n\n", chosen);
						}

						else if(chosen2==5){
							system("cls");
							update_sex:
							displayData(a, arr);
							printf("\n\n\t\t\t\t\t\t\tEnter the updated value of Sex [M/F]:\n");
							printf("\n\t\t\t\t\t\t\t> "); scanf("%s", sex);

								if((strcmp(sex, "M")==0) || (strcmp(sex, "m")==0) || (strcmp(sex, "F")==0) || (strcmp(sex, "f")==0))
									strcpy(arr[index].SEX, strupr(sex));

								else{
								system("cls");
								printf("\n\n\t\t\t\t\t\tTHE ENTERED CHARACTER FOR SEX IS INVALID. TRY AGAIN. \n\n ");
								goto update_sex;
								}

							system("cls");
							printf("\n\n\t\t\t\t\t\t\t     Profile ID %03d was updated.\n\n", chosen);

						}

						else if(chosen2==6){
							system("cls");
							update_math:
							displayData(a, arr);
							printf("\n\n\t\t\t\t\t\t\tEnter the updated value of Grade in Math:\n");
							printf("\n\t\t\t\t\t\t\t> "); scanf("%f", &math);

								if(math<65  || math>99){
								system("cls");
								printf("\n\n\t\t\t\t\t\t\tTHE ENTERED GRADE IS INVALID. TRY AGAIN. \n\n ");
								printf("\t\t\t\t\t\t\t     ENTER A GRADE FROM 65 to 99. \n\n ");
								goto update_math;
								}

								else arr[index].data.MATH = math;

							system("cls");
							printf("\n\n\t\t\t\t\t\t\t     Profile ID %03d was updated.\n\n", chosen);

						}

						else if(chosen2==7){
							system("cls");
							update_science:
							displayData(a, arr);
							printf("\n\n\t\t\t\t\t\t\tEnter the updated value of Grade in Science:\n");
							printf("\n\t\t\t\t\t\t\t> "); scanf("%f", &science);

							 	if(science<65  || science>99){
									system("cls");
									printf("\n\n\t\t\t\t\t\t\tTHE ENTERED GRADE IS INVALID. TRY AGAIN. \n\n ");
									printf("\t\t\t\t\t\t\t     ENTER A GRADE FROM 65 to 99. \n\n ");
									goto update_science;
								}

								else arr[index].data.SCIENCE = science;

							system("cls");
							printf("\n\n\t\t\t\t\t\t\t     Profile ID %03d was updated.\n\n", chosen);
						}

						else if(chosen2==8){
							system("cls");
							update_filipino:
							displayData(a, arr);
							printf("\n\n\t\t\t\t\t\t\tEnter the updated value of Grade in Filipino:\n");
							printf("\n\t\t\t\t\t\t\t> "); scanf("%f", &filipino);

								if(filipino<65  || filipino>99){
									system("cls");
									printf("\n\n\t\t\t\t\t\t\tTHE ENTERED GRADE IS INVALID. TRY AGAIN. \n\n ");
									printf("\t\t\t\t\t\t\t     ENTER A GRADE FROM 65 to 99. \n\n ");
									goto update_filipino;
								}

								else arr[index].data.FILIPINO = filipino;

							system("cls");
							printf("\n\n\t\t\t\t\t\t\t     Profile ID %03d was updated.\n\n", chosen);
						}

						else if(chosen2==9){
							system("cls");
							update_ap:
							displayData(a, arr);
							printf("\n\n\t\t\t\t\t\t\tEnter the updated value of Grade in AP:\n");
							printf("\n\t\t\t\t\t\t\t> "); scanf("%f", &ap);

								if(ap<65  || ap>99){
									system("cls");
									printf("\n\n\t\t\t\t\t\t\tTHE ENTERED GRADE IS INVALID. TRY AGAIN. \n\n ");
									printf("\t\t\t\t\t\t\t     ENTER A GRADE FROM 65 to 99. \n\n ");
									goto update_ap;
								}

								else arr[index].data.AP = ap;

							system("cls");
							printf("\n\n\t\t\t\t\t\t\t     Profile ID %03d was updated.\n\n", chosen);

						}

						else if(chosen2==10){
							system("cls");
							update_english:
							displayData(a, arr);
							printf("\n\n\t\t\t\t\t\t\tEnter the updated value of Grade in English:\n");
							printf("\n\t\t\t\t\t\t\t> "); scanf("%f", &english);

								if(english<65  || english>99){
									system("cls");
									printf("\n\n\t\t\t\t\t\t\tTHE ENTERED GRADE IS INVALID. TRY AGAIN. \n\n ");
									printf("\t\t\t\t\t\t\t     ENTER A GRADE FROM 65 to 99. \n\n ");
									goto update_english;
									}

								else arr[index].data.ENGLISH = english;

							system("cls");
							printf("\n\n\t\t\t\t\t\t\t     Profile ID %03d was updated.\n\n", chosen);

						}

						else if(chosen2==11){
							system("cls");
							update_pe:
							displayData(a, arr);
							printf("\n\n\t\t\t\t\t\t\tEnter the updated value of Grade in PE:\n");
							printf("\n\t\t\t\t\t\t\t> "); scanf("%f", &pe);

							if(pe<65  || pe>99){
								system("cls");
								printf("\n\n\t\t\t\t\t\t\tTHE ENTERED GRADE IS INVALID. TRY AGAIN. \n\n ");
								printf("\t\t\t\t\t\t\t     ENTER A GRADE FROM 65 to 99. \n\n ");
								goto update_pe;
							}

							else arr[index].data.PE = pe;

							system("cls");
							printf("\n\n\t\t\t\t\t\t\t     Profile ID %03d was updated.\n\n", chosen);

						}

						else if(chosen2==12){
							system("cls");

						}

						else{
							system("cls");
							displayData(a, arr);
							goto update_menu;
						}

				FILE *b = fopen("data.c", "w");

				sort_struct(arr, length);

				for(i=0; i<length; i++){
					fprintf(b, "%d", arr[i].ID_num);
					fprintf(b, "\n%s", strupr(arr[i].firstNAME));
					fprintf(b, "\n%s", strupr(arr[i].middleINITIAL));
					fprintf(b, "\n%s", strupr(arr[i].lastNAME));
					fprintf(b, "\n%s", strupr(arr[i].SEX));
					fprintf(b, "\n%.f", arr[i].data.MATH);
					fprintf(b, "\n%.f", arr[i].data.SCIENCE);
					fprintf(b, "\n%.f", arr[i].data.FILIPINO);
					fprintf(b, "\n%.f", arr[i].data.AP);
					fprintf(b, "\n%.f", arr[i].data.ENGLISH);
					fprintf(b, "\n%.f\n\n", arr[i].data.PE);
					}
				end:
				fclose(b);
				}

			else{
				system("cls");
				printf("\n\t\t\t\t\t\t       THE ENTERED ID DOES NOT EXIST! TRY AGAIN. \n\n ");
				goto update_id1;
			}
}

void sort_struct(struct stu_records arr[], int length){
	int i, j;
	struct stu_records temp;

	for(i=0; i<length-1; i++){
		for(j=0; j<(length-1-i); j++){
			if(arr[j].ID_num > arr[j+1].ID_num){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
