#include <stdio.h>
#include <string.h>
#include "Logica/estructura.h"
#include "lib/fort.h"

int selection(){
	int choice;

	printf("press:\n\t1 to see the data\n");
    printf("\t2 to see the addresses that has the number\n");
	printf("\t3 to see the farthest address\n");
	printf("\t4 to see how many addresses hasn't two between streets\n");
	printf("\t5 to see if they are at least 5 addresses with two between streets and its number\n");
    printf("\t6 to enter new data\n");
    printf("\t7 to exit...\n");

	do{
		fflush(stdin);
		printf("Your choice: ");
    } while (scanf("%d", &choice) != 1 || choice < 1 || choice > 7);

	system("cls");
	return choice;
}


void print_info(address addresses[], int i, ft_table_t *table){
    if(addresses[i].has_number == 1){
        ft_printf_ln(table, "%d|%s|%s|%s|%.2f|%.2f|%d|%s", addresses[i].number, addresses[i].main_street, addresses[i].between_1, addresses[i].between_2, addresses[i].coord_X, addresses[i].coord_Y, addresses[i].inhabitants, "yes");
    }
    else{
        ft_printf_ln(table, "%d|%s|%s|%s|%.2f|%.2f|%d|%s", addresses[i].number, addresses[i].main_street, addresses[i].between_1, addresses[i].between_2, addresses[i].coord_X, addresses[i].coord_Y, addresses[i].inhabitants, "no");
    }
}


void info(address addresses[], int cant){
	ft_table_t *table = ft_create_table();
	ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);
    ft_write_ln(table, "No", "Main street", "Between 1", "Between 2", "Coord X", "Coord Y", "Inhabitants", "Has number?");
    int i;
    for (i = 0; i < cant; i++){
        print_info(addresses, i, table);
	}
	printf("%s\n", ft_to_string(table));
}


void show_if_has_number(address addresses[], int cant){
    ft_table_t *table = ft_create_table();
    ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);
    ft_write_ln(table, "No", "Main street", "Between 1", "Between 2", "Coord X", "Coord Y", "Inhabitants", "Has number?");
	int i;
    for (i = 0; i < cant; i++){
        if (addresses[i].has_number){
            print_info(addresses, i, table);
		}
	}
    printf("%s\n", ft_to_string(table));
}


void show_far_address(address addresses[], int pos, float x, float y){
	printf("The farthest address to the point %.2f, %.2f is\n", x, y);
	printf("%s between %s and %s\n", addresses[pos].main_street, addresses[pos].between_1, addresses[pos].between_2);
}

void if_not_2between(address addresses[], int cant){
    int counter = 0, i;

    for(i = 0; i < cant; i++){
        if(strlen(addresses[i].between_1) == 0 && strlen(addresses[i].between_2) == 0){
            counter++;
        }
    }
    printf("They are %d addresses that hasn't the two betwenn streets registered.\n", counter);
}

void atleast_5addresses(address addresses[], int cant){
    int i, counter = 0;
    for(i = 0; i < cant; i++){
        if((strlen(addresses[i].between_1) > 0 && strlen(addresses[i].between_2) > 0) && addresses[i].has_number == true){
            counter++;
        }
    }
    printf("They are %d addresses that have two between and the number registered.\n", counter);
}
