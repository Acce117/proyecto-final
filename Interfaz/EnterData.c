#include <stdio.h>
#include <string.h>
#include "Logica/estructura.h"

void clean_buffer(void)
{
    int c;
    do
    {
        c = getchar();
    } while (c != EOF && c != '\n');
}

void validate_point_value(float *point, char* str){
    printf("Coordinate %s: ", str);

    while(scanf("%f", point) != 1 || *point < 0){
        printf("\aThe coordinate %s must be a floating number...", str);
        printf("Coordinate %s: ", str);
        fflush(stdin);
    }
}

void add_street(char *entrada, char *str){
    //clean_buffer();
    printf("%s street: ", str);
    fgets(entrada, 20, stdin);
    entrada[strlen(entrada) - 1] = '\0';
}

void validate_integer(int *data, char *str){
    printf("Number of %s: ", str);

    while(scanf("%d", data) != 1 || data < 0){
        printf("\aThis data must be an integer number...\n");
        printf("Number of %s: ", str);
        fflush(stdin);
    }

}

int add_address(address addresses[], int cant){
    int n;

    printf("Enter 1 if want to enter more data\nEnter -1 if you don't want to enter more data\n\n");

    while(n != -1 && cant < 30){
        printf("Do you want to enter more data? ");

        while(scanf("%d", &n) != 1 || (n != -1 && n != 1)){
            printf("\aWrong selection...\n");
            printf("Enter 1 if want to enter more data\nEnter 1 if you don't want to enter more data\n");
            fflush(stdin);
        }

        if(n == 1){
            validate_point_value(&addresses[cant].coord_X, "X");
            validate_point_value(&addresses[cant].coord_Y, "Y");

            clean_buffer();
            add_street(addresses[cant].main_street, "Main");

            add_street(addresses[cant].between_1, "First between");

            add_street(addresses[cant].between_2, "Second between");

            validate_integer(&addresses[cant].inhabitants, "inhabitants");
            validate_integer(&addresses[cant].number, "address");

            addresses[cant++].has_number = true;
        }
        system("cls");
    }
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
