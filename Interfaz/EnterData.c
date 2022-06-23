#include <stdio.h>
#include "Logica/estructura.h"

void validation_xy(float *point, char* str){
    printf("Coordinate %s: ", str);
    while(scanf("%f", point) != 1 || *point < 0){
        printf("\aThe coordinate %s must be a floating number...", str);
        printf("Coordinate %s: ", str);
        fflush(stdin);
    }
}
void validation_integer(int *data, char *str){
    printf("Number of %s: ", str);

    while(scanf("%d", data) != 1 || data < 0){
        printf("\aThis data must be an integer number...\n");
        printf("Number of %s: ", str);
        fflush(stdin);
    }

}

int enter_new_data(address addresses[], int cant){
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
            validation_xy(&addresses[cant].coord_X, "X");
            validation_xy(&addresses[cant].coord_Y, "Y");

            printf("Main street: ");
            scanf("%s", addresses[cant].main_street);
            printf("First between street: ");
            scanf("%s", addresses[cant].between_1);
            printf("Second between street: ");
            scanf("%s", addresses[cant].between_2);

            validation_integer(&addresses[cant].inhabitants, "inhabitants");
            validation_integer(&addresses[cant].number, "address");

            addresses[cant++].has_number = true;
        }
    }
    if(cant == 30){
        printf("\aYou have reached the limit of data you can enter...\n");
    }
    return cant;
}

void enter_point(float *point_x, float *point_y)
{
    validation_xy(point_x, "X");
    validation_xy(point_y, "Y");

    printf("\n");
}
