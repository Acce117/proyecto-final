#include "estructura.h"
#include <math.h>

int euclidean_distance(address addresses[], int cant, float x, float y){
	int i, pos = 0;
	float distance = sqrt(pow((x - addresses[0].coord_X), 2) + pow((y - addresses[0].coord_Y), 2));

    for (i = 1; i < cant; i++){
		if (sqrt(pow((x - addresses[i].coord_X), 2) + pow((y - addresses[i].coord_Y), 2)) > distance)		{
			distance = sqrt(pow((x - addresses[i].coord_X), 2) + pow((y - addresses[i].coord_Y), 2));
			pos = i;
		}
	}

	return pos;
}
