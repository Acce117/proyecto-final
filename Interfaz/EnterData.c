#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Logica/estructura.h"


int choice(char *str){
    int choice;

    while(scanf("%d", &choice) != 1 || (choice != 0 && choice != 1)){
        printf("\aWrong selection...\n");
        printf("%s", str);
        fflush(stdin);
    }

    return choice;
}


void validate_point_value(float *point, char* str){
    printf("Coordinate %s: ", str);

    while(scanf("%f", point) != 1 || *point < 0){
        printf("\aThe coordinate %s must be a floating number...\n", str);
        printf("Coordinate %s: ", str);
        fflush(stdin);
    }
}


void add_street(char *entrada, char *str){
    printf("%s street: ", str);

    fgets(entrada, 20, stdin);

    entrada[strlen(entrada) - 1] = '\0';

    fflush(stdin);
}


void validate_integer(int *data, char *str){
    printf("Number of %s: ", str);

    while(scanf("%d", data) != 1 || *data < 0){
        printf("\aThis data must be an integer number...\n");
        printf("Number of %s: ", str);
        fflush(stdin);
    }

}


bool validate_repeted_street(char *address_in_base, char *address_usser){
    int i;
    int len_1 = strlen(address_in_base);
    bool same_string = true;
    if(strlen(address_in_base) == strlen(address_usser)){
        for(i = 0; i < len_1 && same_string; i++){
            if(tolower(address_in_base[i]) != tolower(address_usser[i])){
                same_string = false;
            }
        }
    }
    return same_string;
}


bool validate_repeted_data(address addresses[], int cant, int *pos){
    int i, counter_check;

    bool all_check = false;

    for(i = 0; i < cant && !all_check; i++){
        counter_check = 0;

        if(addresses[i].number == addresses[cant].number)
            counter_check++;

        if(addresses[i].coord_X == addresses[cant].coord_X)
            counter_check++;

        if(addresses[i].coord_Y == addresses[cant].coord_Y)
            counter_check++;

        if(validate_repeted_street(addresses[i].main_street, addresses[cant].main_street))
            counter_check++;

        if(validate_repeted_street(addresses[i].between_1, addresses[cant].between_1))
            counter_check++;

        if(validate_repeted_street(addresses[i].between_1, addresses[cant].between_2))
            counter_check++;

        if(counter_check == 6)
            all_check = true;
            *pos = i;
    }

    return all_check;
}


void update_inhabitants(int *inhabitants){
    printf("Enter the number of inhabitants: ");
    while(scanf("%d", inhabitants) != 1 || *inhabitants < 0){
        printf("\aThis value must be an integer number...\n");
        printf("Enter the number of inhabitants: ");
    }
}


int add_address(address addresses[], int cant){
    int n = 1, m, pos;
    printf("Enter 1 if want to enter more data\nEnter 0 if you don't want to enter more data\n\n");

    do{
        printf("Do you want to enter more data? ");

        n = choice("Enter 1 if want to enter more data\nEnter 0 if you don't want to enter more data\n");

        if(n == 1){
            validate_point_value(&addresses[cant].coord_X, "X");
            validate_point_value(&addresses[cant].coord_Y, "Y");

            fflush(stdin);

            add_street(addresses[cant].main_street, "Main");

            add_street(addresses[cant].between_1, "First between");

            add_street(addresses[cant].between_2, "Second between");

            validate_integer(&addresses[cant].inhabitants, "inhabitants");
            validate_integer(&addresses[cant].number, "address");

            if(validate_repeted_data(addresses, cant, &pos)){
                system("cls");
                printf("\aThis address already exist in the data base...\n");
                if(addresses[pos].inhabitants != addresses[cant].inhabitants){
                    printf("The number of inhabitants differs from de exisiting address\n");
                    printf("Do you want to update the number of inhabitants?\n");

                    printf("  Press 1. yes...\n\t0. no...\n");
                    m = choice("  Press 1. yes...\n\t0. no...\n");

                    switch(m){
                        case 1:
                            update_inhabitants(&addresses[pos].inhabitants);
                            break;
                        case 0:
                            break;
                    }
                }
            }
            else{
                addresses[cant++].has_number = true;
            }
        }
    }while(n != 0 && cant < 30);

    system("cls");
    if(cant == 30){
        printf("\aYou have reached the limit of data you can enter...\n");
    }

    return cant;
}


void add_point(float *point_x, float *point_y)
{
    validate_point_value(point_x, "X");
    validate_point_value(point_y, "Y");

    printf("\n");
}
