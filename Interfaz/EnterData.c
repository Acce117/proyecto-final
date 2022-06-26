#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Logica/estructura.h"

/*void clean_buffer(){
    int c;
    do{
        c = getchar();
    } while (c != EOF && c != '\n');
}*/

int select_enter_data(){
    int choice;

    while(scanf("%d", &choice) != 1 || (choice != -1 && choice != 1)){
        printf("\aWrong selection...\n");
        printf("Enter 1 if want to enter more data\nEnter 1 if you don't want to enter more data\n");
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

    //fflush(stdin);
}

void validate_integer(int *data, char *str){
    printf("Number of %s: ", str);

    while(scanf("%d", data) != 1 || data < 0){
        printf("\aThis data must be an integer number...\n");
        printf("Number of %s: ", str);
        fflush(stdin);
    }

}


bool validate_repeted_street(char *address_in_base, char *address_usser){
    int i;
    bool same_string = true;
    if(strlen(address_in_base) == strlen(address_usser)){
        for(i = 0; i < strlen(address_in_base) && same_string; i++){
            if(address_in_base[i] != address_usser[i]){
                same_string = false;
            }
        }
    }
    return same_string;
}

bool validate_repeted_data(address addresses[], int cant){
    int i, counter_check, pos;

    bool all_check = false;

    for(i = 0; i < cant && !all_check; i++){
        counter_check = 0;

        if(addresses[i].number == addresses[cant].number){
            counter_check++;
        }
        if(addresses[i].coord_X == addresses[cant].coord_X){
            counter_check++;
        }
        if(addresses[i].coord_Y == addresses[cant].coord_Y){
            counter_check++;
        }
        if(validate_repeted_street(addresses[i].main_street, addresses[cant].main_street))
            counter_check++;

        if(validate_repeted_street(addresses[i].between_1, addresses[cant].between_1))
            counter_check++;

        if(validate_repeted_street(addresses[i].between_1, addresses[cant].between_2))
            counter_check++;

        if(counter_check == 6)
            all_check = true;
    }

    return all_check;
}

int add_address(address addresses[], int cant){
    int n = 1;
    printf("Enter 1 if want to enter more data\nEnter -1 if you don't want to enter more data\n\n");

    do{
        printf("Do you want to enter more data? ");

        n = select_enter_data();

        if(n == 1){
            validate_point_value(&addresses[cant].coord_X, "X");
            validate_point_value(&addresses[cant].coord_Y, "Y");

            fflush(stdin);
            //clean_buffer();
            add_street(addresses[cant].main_street, "Main");

            add_street(addresses[cant].between_1, "First between");

            add_street(addresses[cant].between_2, "Second between");

            validate_integer(&addresses[cant].inhabitants, "inhabitants");
            validate_integer(&addresses[cant].number, "address");

            if(validate_repeted_data(addresses, cant)){
                system("cls");
                printf("\aThis address already exist in the data base...\n");
            }
            else{
                addresses[cant++].has_number = true;
            }
        }
    }while(n != -1 && cant < 30);

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
