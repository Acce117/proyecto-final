#include <stdio.h>
#include "Logica/header.h"
#include "Interfaz/Interfaz.h"

int main(){
	address addresses[30];
	int log_cant = 15;
	int select = 0;
	float x, y;
	int far_address;

	initial_data(addresses);

	printf("Welcome :)\n");

    while (select != 7)	{
        select = selection();
        switch (select){
            case 1:
                info(addresses, log_cant);
                break;
            case 2:
                show_if_has_number(addresses, log_cant);
                break;
            case 3:
                enter_point(&x, &y);
                far_address = euclidean_distance(addresses, log_cant, x, y);
                show_far_address(addresses, far_address, x, y);
                break;
            case 4:
                if_not_2between(addresses, log_cant);
                break;
            case 5:
                atleast_5addresses(addresses, log_cant);
                break;
            case 6:
                log_cant = enter_new_data(addresses, log_cant);
                break;
            default:
                break;
		}

		system("pause");
		system("cls");
	}

	return 0;
}
